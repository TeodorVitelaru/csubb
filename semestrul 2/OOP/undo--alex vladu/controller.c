#include "controller.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include "domain.h"
#include "validator.h"
#include "repository.h"
#include "controller.h"
#include "array.h"

Controller create_Controller(Repository repo)
{
    Controller controller = (Controller)malloc(sizeof(Oferta_Controller));
    controller->repo = repo;
    return controller;
}
void destroy_Controller(Controller controller)
{
    detroy_Repo(controller->repo);
    free(controller);
}

Repository get_Controller_Repo(Controller controller)
{
    return controller->repo;
}


Vector return_last_element(Vector vec)
{
    return vec->v[vec->size-1];
}

void destroy_last_element(Vector vec)
{
    destroy_vector(vec->v[vec->size-1], delete_Oferta);
    vec->size--;
}


void test_undo_list()
{
    Vector oferte = create_vector(2);
    add_vector(oferte, create_Oferta("teodor", 200, "calea nationala", 1000));
    assert(get_Vector_Size(oferte) == 1);
    Vector undoL = create_vector(1);
    add_vector(undoL, oferte);
    Vector previous_list = return_last_element(undoL);
    assert(previous_list->size == 1);
    destroy_last_element(undoL);
    assert(get_Vector_Size(undoL) == 0);
    destroy(undoL, (DestroyFunction) destroy_lista);
}


void test_transform_chars_to_integer()
{
    //Functie care testeaza transform_chars_to_integer
    assert(transform_chars_to_integer("12345") == 12345);
    assert(transform_chars_to_integer("01234") == 1234);
    assert(transform_chars_to_integer("5") == 5);
}

int transform_chars_to_integer(const char* amount_text)
{
    int nr = 0;
    for (int i = 0; i < strlen(amount_text); i++)
        nr *= 10, nr += amount_text[i] - '0';
    return nr;
}

void test_try_to_add_oferta(Controller controller)
{
    //Functia testeaza functie de try_to_add_oferta
    //Functia primeste ca parametru controllerul;
    Vector undoL = create_vector(1);
    char *result=try_to_add_oferta(controller, "apart", "20", "str1.pret", "2501", undoL);
    assert(strcmp(result, "Tipul nu este unul valid! Tipul poate fi doar teren, casa sau apartament\nNot enough infomation about your address!"));
    free(result);
    result = try_to_add_oferta(controller, "kasa", "202z", "Sibiu,str.Luncii,nr.", "2501", undoL);
    assert(strcmp(result, "Tipul nu este unul valid! Tipul poate fi doar teren, casa sau apartament\nSuprafata is not integer\nPlease enter your street address number!"));
    free(result);
    result=try_to_add_oferta(controller, "casa", "65", "Sibiu,str.Luncii,nr.14", "555", undoL);
    assert(check_ok_string(result));
    free(result);
    remove_Ofera_Repo(get_Controller_Repo(controller), 0);
    destroy(undoL, (DestroyFunction) destroy_lista);
}

char* try_to_add_oferta(Controller controller, char* tip, char* suprafata, char* adresa, char* pret, Vector undoL)
{
    char* errors = (char*)malloc(200 * sizeof(char));
    errors[0] = '\0';
    if (!check_equ_string(tip, "teren") && !check_equ_string(tip, "casa") && !check_equ_string(tip, "apartament"))
        strcat(errors, "Tipul nu este unul valid! Tipul poate fi doar teren, casa sau apartament\n");
    if (!check_number_string(suprafata))
        strcat(errors, "Suprafata is not integer\n");
    if (!strlen(adresa))
        strcat(errors, "Adresa trebuie sa fie valida!");
    if (!check_number_string(pret))
        strcat(errors, "Pret is not integer\n");
    if (strlen(adresa) > 30)
        strcat(errors, "Use max.30 characters to represent address!\n");
    int value_adress_error = check_ok_adress(adresa);
    if (value_adress_error == -1)
        strcat(errors, "Not enough infomation about your address!\n");
    if (value_adress_error == 0)
        strcat(errors, "Please enter your street address number!\n");
    if (strlen(errors))
        return errors;
    strcpy(errors, "OK");
    Vector copie_vector = copy_vector(get_Repo_Vector(controller->repo));
    //printf("%d", copie_vector->size);
    add_vector(undoL, copie_vector); //adaugam la undo
    add_Oferta_Repo(get_Controller_Repo(controller), create_Oferta(tip, transform_chars_to_integer(suprafata), adresa, transform_chars_to_integer(pret)));
    return errors;
}

void test_try_to_edit_oferta(Controller controller)
{
    //Functia testeaza functie de try_to_edit_ofert
    //Functia primeste ca parametru controllerul;
    char *result;
    Vector undoL = create_vector(1);
    result=try_to_add_oferta(controller, "casa", "65", "Sibiu,str.Luncii,nr.14", "555", undoL);
    free(result);
    result = try_to_edit(controller, "0", "apart", "20", "str1.pret", "2501", undoL);
    assert(strcmp(result, "Tipul nu este unul valid! Tipul poate fi doar teren, casa sau apartament\nNot enough infomation about your address!"));
    free(result);
    
    result = try_to_edit(controller, "0", "kasa", "202z", "Sibiu,str.Luncii,nr.", "2501", undoL);
    assert(strcmp(result, "Tipul nu este unul valid! Tipul poate fi doar teren, casa sau apartament\nSuprafata is not integer\nPlease enter your street address number!"));
    free(result);
    result = try_to_edit(controller, "0", "casa", "65", "Sibiu,str.Luncii,nr.14", "555", undoL);
    assert(check_ok_string(result));
    free(result);
    remove_Ofera_Repo(get_Controller_Repo(controller), 0);
    destroy(undoL, (DestroyFunction) destroy_lista);
}

char* try_to_edit(Controller controller, char* id_string, char* tip, char* suprafata, char* adresa, char* pret, Vector undoL)
{
    char* errors = (char*)malloc(200 * sizeof(char));
    if (errors == NULL)
        return NULL;
    errors[0] = '\0';
    if (!check_number_string(id_string))
        strcat(errors, "ID is not integer\n");
    int id = transform_chars_to_integer(id_string);
    if (id >= get_Repo_Size(get_Controller_Repo(controller)))
        strcat(errors, "Element donesn't exist in database\n");
    if (id < 0)
        strcat(errors, "Element donesn't exist in database\n");
    if (strlen(errors))
        return errors;
    if (!check_equ_string(tip, "teren") && !check_equ_string(tip, "casa") && !check_equ_string(tip, "apartament"))
        strcat(errors, "Tipul nu este unul valid! Tipul poate fi doar teren, casa sau apartament\n");
    if (!check_number_string(suprafata))
        strcat(errors, "Suprafata is not integer\n");
    if (!strlen(adresa))
        strcat(errors, "Adresa trebuie sa fie valida!");
    if (!check_number_string(pret))
        strcat(errors, "Pret is not integer\n");
    if (strlen(adresa) > 30)
        strcat(errors, "Use max.30 characters to represent address!\n");
    int value_adress_error = check_ok_adress(adresa);
    if (value_adress_error == -1)
        strcat(errors, "Not enough infomation about your address!\n");
    if (value_adress_error == 0)
        strcat(errors, "Please enter your street address number!\n");
    if (strlen(errors))
        return errors;
    strcpy(errors, "OK");
    Vector copie_vector = copy_vector(get_Repo_Vector(controller->repo));
    add_vector(undoL, copie_vector); //adaugam la undo
    edit_Oferta_Repo(get_Controller_Repo(controller), id, create_Oferta(tip, transform_chars_to_integer(suprafata), adresa, transform_chars_to_integer(pret)));
    return errors;
}

void test_try_to_remove(Controller controller)
{
    //Functia testeaza functie de try_to_remove
    //Functia primeste ca parametru controllerul;
    char *result;
    Vector undoL = create_vector(1);
    result=try_to_add_oferta(controller, "casa", "65", "Sibiu,str.Luncii,nr.14", "555", undoL);
    free(result);
    assert(get_Repo_Size(get_Controller_Repo(controller))==1);
    result=try_to_remove(controller, "1", undoL);
    assert(strcmp(result, "Element donesn't exist in database\n")==0);
    free(result);
    result = try_to_remove(controller, "0", undoL);
    assert(check_ok_string(result));
    free(result);
    destroy(undoL, (DestroyFunction) destroy_lista);
}

char* try_to_remove(Controller controller, char* id_string, Vector undoL)
{
    //Functie primeste ca parametru controller si un sir de caractere(id oferta)
    //Functia returneaza un sir de caractere
    //Functia returneaza OK daca s-a putut sterge oferta cu id-ul respectiv
    //Functia returneaza EROARE daca nu exista
    char* errors = (char*)malloc(200 * sizeof(char));
    if (errors == NULL)
        return NULL;
    errors[0] = '\0';
    if (!check_number_string(id_string))
        strcat(errors, "ID is not integer\n");
    int id = transform_chars_to_integer(id_string);
    if (id >= get_Repo_Size(get_Controller_Repo(controller)))
        strcat(errors, "Element donesn't exist in database\n");
    if (id < 0)
        strcat(errors, "Element donesn't exist in database\n");
    if (strlen(errors))
        return errors;
    strcpy(errors, "OK");
    Vector copie_vector = copy_vector(get_Repo_Vector(controller->repo));
    add_vector(undoL, copie_vector); //adaugam la undo
    remove_Ofera_Repo(get_Controller_Repo(controller), id);
    return errors;
}

void test_sort_by_price_asc(Controller controller)
{
    //Functia primeste ca parametru controller
    //Functia testeaza daca se sorteaza asc dupa pret corect datele din repository;
    Vector array=sort_by_price_asc(controller, compare_Oferta_by_price);
    Oferta of0=(Oferta)get_vector_element(array, 0);
    Oferta of1=(Oferta)get_vector_element(array, 1);
    Oferta of5=(Oferta)get_vector_element(array, 5);
    assert(get_Oferta_pret(of0)==150 && get_Oferta_pret(of1)==250);
    assert(get_Oferta_pret(of5)==5550);
    free(get_Vector_Array(array));
    free(array);
}

Vector sort_by_price_asc(Controller controller, int(*cmp)(void*, void*))
{
    Vector array=create_vector(get_Repo_Size(get_Controller_Repo(controller)));
    if (array == NULL)
        return NULL;
    int n = get_Repo_Size(get_Controller_Repo(controller));
    for (int i = 0; i < n; i++)
        add_vector(array, get_vector_element(get_Repo_Vector(get_Controller_Repo(controller)), i));
    int st = 1;
    do {
        st = 1;
        for (int i = 0; i < n-1; i++)
        {
            Oferta of_current=(Oferta)get_vector_element(array, i);
            Oferta of_next=(Oferta)get_vector_element(array, i+1);
            if(cmp(of_current, of_next)>0)
            {
                Telem aux = array->v[i];
                array->v[i] = array->v[i + 1];
                array->v[i + 1] = aux;
                st = 0;
            }
        }
    } while (st == 0);
    return array;
}

void test_sort_by_price_desc(Controller controller)
{
    //Functia primeste ca parametru controller
    //Functia testeaza daca se sorteaza desc dupa pret corect datele din repository;
    Vector array = sort_by_price_desc(controller, compare_Oferta_by_price);
    Oferta of0 = (Oferta)get_vector_element(array, 0);
    Oferta of1 = (Oferta)get_vector_element(array, 1);
    Oferta of5 = (Oferta)get_vector_element(array, 4);
    assert(get_Oferta_pret(of0) == 5550 && get_Oferta_pret(of1) == 1550);
    //printf("%d", get_Oferta_pret(of5));
    assert(get_Oferta_pret(of5) == 250);
    free(get_Vector_Array(array));
    free(array);
}

Vector sort_by_price_desc(Controller controller, int(*cmp)(void *, void*))
{
    //Functia primeste ca parametru controller
    //Functia returneaza un array de oferte sortate descendent dupa pret
    Vector array = create_vector(get_Repo_Size(get_Controller_Repo(controller)));
    if (array == NULL)
        return NULL;
    int n = get_Repo_Size(get_Controller_Repo(controller));
    for (int i = 0; i < n; i++)
        add_vector(array, get_vector_element(get_Repo_Vector(get_Controller_Repo(controller)), i));
    int st = 1;
    do {
        st = 1;
        for (int i = 0; i < n - 1; i++)
        {
            Telem of_current = get_vector_element(array, i);
            Telem of_next = get_vector_element(array, i + 1);
            if (cmp(of_current, of_next)<0)
            {
                Telem aux = array->v[i];
                array->v[i] = array->v[i + 1];
                array->v[i + 1] = aux;
                st = 0;
            }
        }
    } while (st == 0);
    return array;
}

void test_sort_by_tip_asc(Controller controller)
{
    //Functia primeste ca parametru controller
    //Functia testeaza daca se sorteaza asc dupa tip corect datele din repository;
    Vector array = sort_by_tip_asc(controller, compare_Oferta_by_type);
    Oferta of0 = (Oferta)get_vector_element(array, 0);
    Oferta of1 = (Oferta)get_vector_element(array, 1);
    Oferta of2 = (Oferta)get_vector_element(array, 2);
    assert(strcmp(get_Oferta_tip(of0), "apartament")==0);
    assert(strcmp(get_Oferta_tip(of1), "casa")==0);
    assert(strcmp(get_Oferta_tip(of2), "casa")==0);
    free(get_Vector_Array(array));
    free(array);
}

Vector sort_by_tip_asc(Controller controller, int(*cmp)(Telem, Telem))
{
    //Functia primeste ca parametru controller
    //Functia returneaza un array de oferte sortate ascendent dupa tip
    Vector array = create_vector(get_Repo_Size(get_Controller_Repo(controller)));
    if (array == NULL)
        return NULL;
    int n = get_Repo_Size(get_Controller_Repo(controller));
    for (int i = 0; i < n; i++)
        add_vector(array, get_vector_element(get_Repo_Vector(get_Controller_Repo(controller)), i));
    int st = 1;
    do {
        st = 1;
        for (int i = 0; i < n - 1; i++)
        {
            Telem of_current = get_vector_element(array, i);
            Telem of_next = get_vector_element(array, i + 1);
            if(cmp(of_current, of_next)>0)
            {
                Telem aux = array->v[i];
                array->v[i] = array->v[i + 1];
                array->v[i + 1] = aux;
                st = 0;
            }
        }
    } while (st == 0);
    return array;
}

void test_sort_by_tip_desc(Controller controller)
{
    //Functia primeste ca parametru controller
    //Functia testeaza daca se sorteaza asc dupa tip corect datele din repository;
    Vector array = sort_by_tip_desc(controller, compare_Oferta_by_type);
    Oferta of0 = (Oferta)get_vector_element(array, 0);
    Oferta of1 = (Oferta)get_vector_element(array, 1);
    Oferta of2 = (Oferta)get_vector_element(array, 2);
    assert(strcmp(get_Oferta_tip(of0), "teren")==0);
    assert(strcmp(get_Oferta_tip(of1), "teren")==0);
    assert(strcmp(get_Oferta_tip(of2), "casa")==0);
    free(get_Vector_Array(array));
    free(array);
}

Vector sort_by_tip_desc(Controller controller, int(*cmp)(void*, void*))
{
    //Functia primeste ca parametru controller
    //Functia returneaza un array de oferte sortate descendent dupa tip
    Vector array = create_vector(get_Repo_Size(get_Controller_Repo(controller)));
    if (array == NULL)
        return NULL;
    int n = get_Repo_Size(get_Controller_Repo(controller));
    for (int i = 0; i < n; i++)
        add_vector(array, get_vector_element(get_Repo_Vector(get_Controller_Repo(controller)), i));
    int st = 1;
    do {
        st = 1;
        for (int i = 0; i < n - 1; i++)
        {
            Telem of_current = get_vector_element(array, i);
            Telem of_next = get_vector_element(array, i + 1);
            if (cmp(of_current, of_next) < 0)
            {
                Telem aux = array->v[i];
                array->v[i] = array->v[i + 1];
                array->v[i + 1] = aux;
                st = 0;
            }
        }
    } while (st == 0);
    return array;
}

void test_filter_by_tip(Controller controller)
{
    //Functia primeste ca parametru controller
    //Functia testeaza daca se filtreaza dupa tip corect

    Vector array = filter_by_tip(controller, "apartament");
    assert(get_Vector_Size(array)==1);
    free(get_Vector_Array(array));
    free(array);

    array= filter_by_tip(controller, "casa");
    assert(get_Vector_Size(array)==3);
    free(get_Vector_Array(array));
    free(array);

    array = filter_by_tip(controller, "teren");
    assert(get_Vector_Size(array)==2);
    free(get_Vector_Array(array));
    free(array);
}

Vector filter_by_tip(Controller controller, char* tip)
{
    Vector array=create_vector(get_Repo_Size(get_Controller_Repo(controller)));
    int n = get_Repo_Size(get_Controller_Repo(controller));
    for (int i = 0; i < n; i++)
    {
        Oferta element = (Oferta)get_vector_element(get_Repo_Vector(get_Controller_Repo(controller)), i);
        if(check_equ_string(get_Oferta_tip(element), tip))
            add_vector(array, element);
    }
    return array;
}

Vector filter_by_adresa_cluj(Controller controller)
{
    Vector array = create_vector(get_Repo_Size(get_Controller_Repo(controller)));
    int n = get_Repo_Size(get_Controller_Repo(controller));
    for (int i = 0; i < n; i++)
    {
        Oferta element = (Oferta)get_vector_element(get_Repo_Vector(get_Controller_Repo(controller)), i);
        if (strstr(get_Oferta_adresa(element), "Cluj") || strstr(get_Oferta_adresa(element), "cluj") )
            add_vector(array, element);
    }
    return array;
}

void test_filter_by_adresa_cluj(Controller controller)
{
    Vector array = filter_by_adresa_cluj(controller);
    assert(get_Vector_Size(array)==2);
    assert(get_Oferta_pret(array->v[0]) == 250);
    assert(get_Oferta_pret(array->v[1]) == 550);
    free(get_Vector_Array(array));
    free(array);

}

void test_filter_by_suprafata(Controller controller)
{
    //Functia primeste ca parametru controller
    //Functia testeaza daca se filtreaza dupa suprafata



    Vector array = filter_by_suprafata(controller, "150", "350");
    assert(get_Vector_Size(array)==2);
    free(get_Vector_Array(array));
    free(array);

    array = filter_by_suprafata(controller, "20", "3500");
    assert(get_Vector_Size(array) == 6);
    free(get_Vector_Array(array));
    free(array);

    array = filter_by_suprafata(controller, "1550", "650");
    assert(get_Vector_Size(array) == 0);
    free(get_Vector_Array(array));
    free(array);
}
Vector filter_by_suprafata(Controller controller, char* mini_txt, char* maxi_txt)
{
    Vector array = create_vector(get_Repo_Size(get_Controller_Repo(controller)));
    int n = get_Repo_Size(get_Controller_Repo(controller));
    int mini = transform_chars_to_integer(mini_txt);
    int maxi = transform_chars_to_integer(maxi_txt);
    for (int i = 0; i < n; i++)
    {
        Oferta element = (Oferta)get_vector_element(get_Repo_Vector(get_Controller_Repo(controller)), i);
        if (get_Oferta_suprafata(element) >= mini && get_Oferta_suprafata(element) <= maxi)
            add_vector(array, element);
    }
    return array;
}

void test_filter_by_pret(Controller controller)
{
    Vector array = filter_by_pret(controller, "0", "100");
    free(get_Vector_Array(array));
    free(array);

    array = filter_by_pret(controller, "50", "250");
    free(get_Vector_Array(array));
    free(array);

    array = filter_by_pret(controller, "500", "0");
    free(get_Vector_Array(array));
    free(array);
}

Vector filter_by_pret(Controller controller, char* mini_txt, char* maxi_txt)
{
    Vector array = create_vector(get_Repo_Size(get_Controller_Repo(controller)));
    int n = get_Repo_Size(get_Controller_Repo(controller));
    int mini = transform_chars_to_integer(mini_txt);
    int maxi = transform_chars_to_integer(maxi_txt);
    for (int i = 0; i < n; i++)
    {
        Oferta element = (Oferta)get_vector_element(get_Repo_Vector(get_Controller_Repo(controller)), i);
        if (get_Oferta_pret(element) >= mini && get_Oferta_pret(element) <= maxi)
            add_vector(array, element);
    }
    return array;
}

void test_controller(Controller controller)
{
    test_transform_chars_to_integer();
    test_try_to_add_oferta(controller);
    test_try_to_edit_oferta(controller);
    test_try_to_remove(controller);
    test_undo_list();
    
    char *result;
    Vector undoL = create_vector(1);
    result=try_to_add_oferta(controller, "teren", "52", "Sibiu,str.Luncii,nr.14", "350", undoL);
    free(result);
    //printf("%d\n", get_Controller_Repo(controller)->array->size);
    result=try_to_add_oferta(controller, "casa", "120", "Cluj,str.Aurel Vlaicu,nr.184", "250", undoL);
    free(result);
    Vector lista = undoL->v[1];
    //printf("%d", lista->size);

    result=try_to_add_oferta(controller, "apartament", "25", "Cluj,str.Libertatii,nr.1", "550", undoL);
    free(result);

    result=try_to_add_oferta(controller, "teren", "375", "Sibiu,str.Rovine,nr.12", "5550", undoL);
    free(result);

    result=try_to_add_oferta(controller, "casa", "275", "Pitesti,str.Ploiesti,nr.23", "150", undoL);
    free(result);


    result=try_to_add_oferta(controller, "casa", "175", "Alba-Iulia,str.Neagra,nr.5", "1550", undoL);
    free(result);

    test_sort_by_price_asc(controller);
    test_sort_by_price_desc(controller);
    test_sort_by_tip_asc(controller);
    test_sort_by_tip_desc(controller);
    test_filter_by_tip(controller);
    test_filter_by_suprafata(controller);
    test_filter_by_pret(controller);
    test_filter_by_adresa_cluj(controller);
    destroy(undoL, (DestroyFunction) destroy_lista);
}