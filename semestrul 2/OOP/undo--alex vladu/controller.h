#pragma once
#include "repository.h"
typedef struct {
    Repository repo;
}Oferta_Controller;

typedef Oferta_Controller* Controller;

Controller create_Controller(Repository repo);

void destroy_Controller(Controller controller);

Repository get_Controller_Repo(Controller controller);


/*
//Functie care primeste ca parametru un sir de caractere
//Functia returneaza numarul intreg reprezentat in scrierea normala a sirului de caractere;
*/
int transform_chars_to_integer(const char* amount_text);

//Functie primeste ca parametru controller si sirurile de caractere: tip, suprafata, adresa, pret:
//Functia returneaza un sir de caractere
//Functia returneaza OK daca s-a putut adauga oferta cu datele respective
//Functia returneaza EROARE daca nu au fost introduse corect;
char* try_to_add_oferta(Controller controller, char* tip, char* suprafata, char* adresa, char* pret, Vector undoL);

//Functie primeste ca parametru controller si sirurile de caractere: id, tip, suprafata, adresa, pret:
//Functia returneaza un sir de caractere
//Functia returneaza OK daca s-a putut edita oferta cu datele respective
//Functia returneaza EROARE daca nu au fost introduse corect;
char* try_to_edit(Controller controller, char* id_string, char* tip, char* suprafata, char* adresa, char* pret, Vector undoL);

//Functie primeste ca parametru controller si un sir de caractere(id oferta)
//Functia returneaza un sir de caractere
//Functia returneaza OK daca s-a putut sterge oferta cu id-ul respectiv
//Functia returneaza EROARE daca nu exista
char* try_to_remove(Controller controller, char* id_string, Vector undoL);


//Functia primeste ca parametru controller
//Functia returneaza un array de oferte sortate ascendent dupa pret
Vector sort_by_price_asc(Controller controller, int(*cmp)(void*, void*));

//Functia primeste ca parametru controller
//Functia returneaza un array de oferte sortate descendent dupa pret
Vector sort_by_price_desc(Controller controller, int(*cmp)(void*, void*));


//Functia primeste ca parametru controller
//Functia returneaza un array de oferte sortate ascendent dupa pret
Vector sort_by_tip_asc(Controller controller, int(*cmp)(void*, void*));

//Functia primeste ca parametru controller
//Functia returneaza un array de oferte sortate descendent dupa tip
Vector sort_by_tip_desc(Controller controller, int(*cmp)(void*, void*));

//Functia primeste ca parametru controller, un tip dupa care se filtreaza
//Size-ul care se intoarce ca parametru reprezinta numarul de oferte care respecta tipul dat
//Functia returneaza un array de oferte sortate descendent dupa tip
Vector filter_by_tip(Controller controller, char* tip);

Vector filter_by_adresa_cluj(Controller controller);

//Functia primeste ca parametru un controller, un sir de caractere care reprezinta valoare minima ca text
//alt sir de caractere care reprezinta valoarea maxima ca text si un size care se va intoarce reprezentant 
//cate elemente au respectat filtrarea dupa suprafata in [min, max]
Vector filter_by_suprafata(Controller controller, char* mini_txt, char* maxi_txt);

////Functia primeste ca parametru un controller, un sir de caractere care reprezinta valoare minima ca text
//alt sir de caractere care reprezinta valoarea maxima ca text si un size care se va intoarce reprezentant 
//cate elemente au respectat filtrarea dupa pret in [min, max]
Vector filter_by_pret(Controller controller, char* mini_txt, char* maxi_txt);

Vector create_undo_list();
Vector return_last_element(Vector vec);
void destroy_last_element(Vector vec);

void test_controller();