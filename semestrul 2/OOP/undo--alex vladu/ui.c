
#include "domain.h"
#include "controller.h"
#include "repository.h"
#include "validator.h"
#include <stdlib.h>
//#include <windows.h>
#include <stdio.h>
#include <string.h>
#include "domain.h"
#include "ui.h"


void print_menu()
{
    printf("### MENU ###\n");
    printf("1.Adaugare oferta.\n"); //OK
    printf("2.Actualizare oferta\n"); //OK
    printf("3.Sterge oferta\n"); //OK
    printf("4.Vizualiare oferte\n"); //OK
    printf("5.Vizualizare oferete ordonat dupa pret, tip (crescator/descrescator)\n"); //OK
    printf("6.Vizualizare oferta filtrate dupa suprafata\n"); //IN Progress
    printf("7.Vizualizare oferta filtrate dupa tip\n"); //OK
    printf("8.Vizualizare oferta filtrate dupa pret\n");
    printf("9.UNDO\n");
    printf("10.Exit aplication\n");
    printf("11.Vizualizare oferte filtrate dupa adresa din Cluj\n");
}
void sub_menu_sort_offerts()
{
    printf("### SUBMENU SORT ###\n");
    printf("1.Ordonare dupa pret crescator\n");
    printf("2.Ordonare dupa pret descrescator\n");
    printf("3.Ordonare dupa tip crescator\n");
    printf("4.Ordonare dupa tip descrescator\n");
    printf("5.Back\n");
}
void sub_menu_filter_tip_offerts()
{
    printf("### SUBMENU FILTER BY TIP ###\n");
    printf("1.Afisare toate cele care sunt de tip teren\n");
    printf("2.Afisare toate cele care sunt de tip casa\n");
    printf("3.Afisare toate cele care sunt de tip apartament\n");
    printf("4.Back\n");
}
int digits(int nr)
{
    int cnt = 0;
    while (nr)
    {
        cnt++;
        nr /= 10;
    }
    return cnt;
}
void display_oferte_by_array(Vector vec)
{
    printf("Tip                            ");
    printf("Suprafata                      ");
    printf("Adresa                         ");
    printf("Pret                          \n");
    for (int i = 0; i < get_Vector_Size(vec); i++)
    {
        Oferta oferta=(Oferta)get_vector_element(vec, i);
        printf("%s", get_Oferta_tip(oferta));
        for (size_t j = strlen(get_Oferta_tip(oferta)); j <= 30; j++)
            printf(" ");
        printf("%d", get_Oferta_suprafata(oferta));
        for (int j = digits(get_Oferta_suprafata(oferta)); j <= 30; j++)
            printf(" ");
        printf("%s", get_Oferta_adresa(oferta));
        for (size_t j = strlen(get_Oferta_adresa(oferta)); j <= 30; j++)
            printf(" ");
        printf("%d", get_Oferta_pret(oferta));
        for (int j = digits(get_Oferta_pret(oferta)); j <= 30; j++)
            printf(" ");
        printf("\n");
    }
}

void filter_by_adresa_cluj_ui(Controller controller)
{
    Vector oferte = filter_by_adresa_cluj(controller);
    printf("%d records from database:\n", get_Vector_Size(oferte)), display_oferte_by_array(oferte);
}

void undo_ui(Controller controller, Vector undoL)
{

    char cmd[100];
    printf("SUNTETI SIGUR CA DORITi SA FACETI UNDO?\n");
    printf("y/n:");
    read_line(cmd);
    if(strcmp(cmd, "y") == 0)
    {
        if(undoL->size<=0)
        {
            printf("NU SE MAI POATE FACE UNDO\n");
        } else
        {
            Vector previous_list = copy_vector(return_last_element(undoL));
            destroy_last_element(undoL);
            destroy_vector(get_Repo_Vector(get_Controller_Repo(controller)), delete_Oferta);
            controller->repo->array = previous_list;
            printf("UNDO REALIZAt CU SUCCES\n");
        }

    } else if(strcmp(cmd, "n") == 0)
    {
        printf("NU S A VRUT\n");
    }
}

void read_line(char* store)
{
    fflush(stdin);
    fgets(store, 150, stdin);
    store[strlen(store) - 1] = '\0';
}
void run_console(Controller controller)
{
    int program_run = 1;
    Vector undoL = create_vector(2);
    char* optiune = (char*)malloc(100 * sizeof(char));
    while (program_run)
    {
        print_menu();
        printf("Introduceti o optiune:");
        read_line(optiune);
        //Sleep(1000);
        if (validate_option(optiune, 1, 11))
        {
            int option=transform_chars_to_integer(optiune);
            if (option == 1)
            {
                char* tip = (char*)malloc(200 * sizeof(char));
                char* suprafata = (char*)malloc(200 * sizeof(char));
                char* adresa = (char*)malloc(200 * sizeof(char));
                char* pret = (char*)malloc(200 * sizeof(char));
                printf("Introduceti tipul imobilului. Tipul poate fi doar teren, casa sau apartament:");
                read_line(tip);
                printf("Introduceti suprafata in metrii patrati:");
                read_line(suprafata);
                printf("Introduceti adresa imobilului:");
                read_line(adresa);
                printf("Introduceti pretul imobilului:");
                read_line(pret);
                char* result = try_to_add_oferta(controller, tip, suprafata, adresa, pret, undoL);
                if (check_ok_string(result))
                    printf("Oferta a fost adaugata cu succes!\n");
                else printf("%s", result);
                free(tip), free(suprafata), free(adresa), free(pret), free(result);
            }
            if (option == 2)
            {
                char* id = (char*)malloc(200 * sizeof(char));
                printf("Introduceti id-ul ofertei:");
                read_line(id);
                char* tip = (char*)malloc(200 * sizeof(char));
                char* suprafata = (char*)malloc(200 * sizeof(char));
                char* adresa = (char*)malloc(200 * sizeof(char));
                char* pret = (char*)malloc(200 * sizeof(char));
                printf("Introduceti tipul imobilului. Tipul poate fi doar teren, casa sau apartament:");
                read_line(tip);
                printf("Introduceti suprafata in metrii patrati:");
                read_line(suprafata);
                printf("Introduceti adresa imobilului:");
                read_line(adresa);
                printf("Introduceti pretul imobilului:");
                read_line(pret);
                char* result = try_to_edit(controller, id, tip, suprafata, adresa, pret, undoL);
                if (check_ok_string(result))
                    printf("Oferta a fost modificata cu succes\n");
                else printf("%s", result);
                free(id), free(tip), free(suprafata), free(adresa), free(pret), free(result);
            }
            if (option == 3)
            {
                char* id = (char*)malloc(200 * sizeof(char));
                printf("Introduceti id-ul ofertei:");
                read_line(id);
                char* result = try_to_remove(controller, id, undoL);
                if (check_ok_string(result))
                    printf("Oferta a fost stearsa cu succes!\n");
                else printf("%s", result);
                free(id), free(result);
            }
            if (option == 4)
            {
                if (!get_Repo_Size(get_Controller_Repo(controller)))
                    printf("Nu au fost introduse oferte!\n");
                else
                    printf("%d records from database:\n", get_Repo_Size(get_Controller_Repo(controller))), display_oferte_by_array(get_Repo_Vector(get_Controller_Repo(controller)));
            }
            if (option == 5)
            {
                sub_menu_sort_offerts();
                printf("Introduceti o optiune:");
                char* sub_optiune = (char*)malloc(100 * sizeof(char));
                read_line(sub_optiune);
                while (!validate_option(sub_optiune, 1, 5))
                {
                    printf("Optiunea introdusa este invalida.\n");
                    sub_menu_sort_offerts();
                    printf("Introduceti o optiune:");
                    read_line(sub_optiune);
                    //Sleep(1000);
                }
                int option_s=transform_chars_to_integer(sub_optiune);
                if (option_s == 1)
                {
                    Vector oferte = sort_by_price_asc(controller, compare_Oferta_by_price);
                    display_oferte_by_array(oferte);
                    free(get_Vector_Array(oferte));
                    free(oferte);
                }
                else if (option_s == 2)
                {
                    Vector oferte = sort_by_price_desc(controller, compare_Oferta_by_price);
                    display_oferte_by_array(oferte);
                    free(get_Vector_Array(oferte));
                    free(oferte);
                }
                else if (option_s == 3)
                {
                    Vector oferte = sort_by_tip_asc(controller, compare_Oferta_by_type);
                    display_oferte_by_array(oferte);
                    free(get_Vector_Array(oferte));
                    free(oferte);
                }
                else if (option_s == 4)
                {
                    Vector oferte = sort_by_tip_desc(controller, compare_Oferta_by_type);
                    display_oferte_by_array(oferte);
                    free(get_Vector_Array(oferte));
                    free(oferte);
                }
                free(sub_optiune);
            }
            if (option == 6)
            {
                char* val_mini = (char*)malloc(200 * sizeof(char));
                char* val_maxi = (char*)malloc(200 * sizeof(char));
                printf("Introduceti suprafata minima:");
                read_line(val_mini);
                printf("Introduceti suprafata maxima:");
                read_line(val_maxi);
                if (!check_number_string(val_mini))
                    printf("Valoare minima introdusa nu este un numar intreg pozitiv!\n");
                else if (!check_number_string(val_maxi))
                    printf("Valoare maxima introdusa nu este un numar intreg pozitiv\n");
                else {
                    Vector oferte = filter_by_suprafata(controller, val_mini, val_maxi);
                    printf("%d records from database:\n", get_Vector_Size(oferte)), display_oferte_by_array(oferte);
                    free(get_Vector_Array(oferte));
                    free(oferte);
                }
                free(val_mini);
                free(val_maxi);
            }
            if (option == 7)
            {
                sub_menu_filter_tip_offerts();
                printf("Introduceti o optiune:");
                char* sub_optiune = (char*)malloc(100 * sizeof(char));
                read_line(sub_optiune);
                while (!validate_option(sub_optiune, 1, 4))
                {
                    printf("Optiunea introdusa este invalida.\n");
                    sub_menu_filter_tip_offerts();
                    printf("Introduceti o optiune:");
                    read_line(sub_optiune);
                    //Sleep(1000);
                }
                int option_s=transform_chars_to_integer(sub_optiune);
                printf("%d", option_s);
                if (option_s == 1)
                {
                    Vector oferte = filter_by_tip(controller, "teren");
                    printf("%d records from database:\n", get_Vector_Size(oferte)), display_oferte_by_array(oferte);
                    free(get_Vector_Array(oferte));
                    free(oferte);
                }
                if (option_s == 2)
                {
                    Vector oferte = filter_by_tip(controller, "casa");
                    printf("%d records from database:\n", get_Vector_Size(oferte)), display_oferte_by_array(oferte);
                    free(get_Vector_Array(oferte));
                    free(oferte);
                }
                if (option_s == 3)
                {
                    Vector oferte = filter_by_tip(controller, "apartament");
                    printf("%d records from database:\n", get_Vector_Size(oferte)), display_oferte_by_array(oferte);
                    free(get_Vector_Array(oferte));
                    free(oferte);
                }
                free(sub_optiune);
            }
            if (option == 8)
            {
                char* val_mini = (char*)malloc(200 * sizeof(char));
                char* val_maxi = (char*)malloc(200 * sizeof(char));
                printf("Introduceti pretul minim:");
                read_line(val_mini);
                printf("Introduceti pretul maxim:");
                read_line(val_maxi);
                if (!check_number_string(val_mini))
                    printf("Valoare minima introdusa nu este un numar intreg pozitiv!\n");
                else if (!check_number_string(val_maxi))
                    printf("Valoare maxima introdusa nu este un numar intreg pozitiv\n");
                else {
                    int* size = (int*)malloc(sizeof(int));
                    if(size!=NULL)
                    {
                        Vector oferte=filter_by_pret(controller, val_mini, val_maxi);
                        printf("%d records from database:\n", get_Vector_Size(oferte)), display_oferte_by_array(oferte);
                        free(get_Vector_Array(oferte));
                        free(oferte);
                    }
                    free(size);
                }
                free(val_mini), free(val_maxi);
            }
            if(option == 9)
            {
                undo_ui(controller, undoL);
            }
            if (option == 10)
            {
                printf("Aplication closed succesfully");
                program_run = 0;
                destroy(undoL, (DestroyFunction) destroy_lista);
            }
            if(option == 11)
            {
                filter_by_adresa_cluj_ui(controller);
            }
        }
        else
            printf("Optiune invalida!\n");
        //Sleep(1000);
    }
    free(optiune);
}