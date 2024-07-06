#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include "domain.h"
#include "array.h"
char* get_Oferta_tip(Oferta oferta)
{
    return oferta->tip;
}
int get_Oferta_suprafata(Oferta oferta)
{
    return oferta->suprafata;
}
char* get_Oferta_adresa(Oferta oferta)
{
    return oferta->adresa;
}
int get_Oferta_pret(Oferta oferta)
{
    return oferta->pret;
}
void set_Oferta_tip(Oferta oferta, char*tip)
{
    strcpy(oferta->tip, tip);
}
void set_Oferta_suprafata(Oferta oferta, int suprafata)
{
    oferta->suprafata=suprafata;
}
void set_Oferta_adresa(Oferta oferta, char*adresa)
{
    strcpy(oferta->adresa, adresa);
}
void set_Oferta_pret(Oferta oferta, int pret)
{
    oferta->pret=pret;
}
Oferta create_Oferta(char* tip, int suprafata, char* adresa, int pret)
{
    Oferta oferta = (Oferta)malloc(sizeof(Oferta_Struct));
    if(oferta==NULL)
        return NULL;
    oferta->tip = (char*)malloc(200 * sizeof(char));
    oferta->adresa = (char*)malloc(200 * sizeof(char));
    set_Oferta_tip(oferta, tip);
    set_Oferta_suprafata(oferta, suprafata);
    set_Oferta_adresa(oferta, adresa);
    set_Oferta_pret(oferta, pret);
    return oferta;
}

Oferta copy_oferta(Oferta of)
{
    if(of==NULL)
        return NULL;
    return create_Oferta(of->tip, of->suprafata, of->adresa, of->pret);
}

int compare_Oferta_by_price(Telem of1, Telem of2)
{
    Oferta oferta1=(Oferta)of1;
    Oferta oferta2=(Oferta)of2;
    if(oferta1->pret>oferta2->pret)
        return 1;
    if(oferta1->pret<oferta2->pret)
        return -1;
    return 0;
}
int compare_Oferta_by_type(Telem of1, Telem of2)
{
    Oferta oferta1=(Oferta)of1;
    Oferta oferta2=(Oferta)of2;
    return strcmp(oferta1->tip, oferta2->tip);
}
void delete_Oferta(void* oferta)
{
    if(oferta == NULL)
        return;
    Oferta to_remove=(Oferta)oferta;
    free(get_Oferta_tip(to_remove));
    free(get_Oferta_adresa(to_remove));
    free(to_remove);
}
void test_domain()
{
    Oferta oferta=create_Oferta("casa", 75, "Sibiu,str.Luncii,nr.14", 2500);
    Oferta oferta1=create_Oferta("teren", 232, "Sibiu,str.Luncii,nr.200", 9823);
    assert(strcmp(get_Oferta_adresa(oferta), "Sibiu,str.Luncii,nr.14")==0);
    assert(get_Oferta_pret(oferta1)==9823);
    assert(strcmp(get_Oferta_tip(oferta1), "teren") == 0);
    delete_Oferta(oferta);
    delete_Oferta(oferta1);
}