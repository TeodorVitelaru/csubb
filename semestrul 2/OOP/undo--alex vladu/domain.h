#pragma once
#include "array.h"
typedef struct {
    char* tip;
    int suprafata;
    char* adresa;
    int pret;
}Oferta_Struct;

typedef Oferta_Struct* Oferta;

char* get_Oferta_tip(Oferta oferta);

int get_Oferta_suprafata(Oferta oferta);

char* get_Oferta_adresa(Oferta oferta);

int get_Oferta_pret(Oferta oferta);

void set_Oferta_tip(Oferta oferta, char* tip);

void set_Oferta_suprafata(Oferta oferta, int suprafata);

void set_Oferta_adresa(Oferta oferta, char* adresa);

void set_Oferta_pret(Oferta oferta, int pret);

int compare_Oferta_by_price(Telem of1, Telem of2);

int compare_Oferta_by_type(Telem of1, Telem of2);

//Functie care primeste toate datele corecte si creeaza o ofera noua, apoi o returneaza
Oferta create_Oferta(char* tip, int suprafata, char* adresa, int pret);

Oferta copy_oferta(Oferta of);

//Functie care primeste ca parametru un pointer void si sterge ce e acolo din memorie;
void delete_Oferta(void* oferta);

//Functie care testeaza domeniul
void test_domain();