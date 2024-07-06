#include<stdlib.h>
#include<string.h>
#include <stdio.h>
#include "domain.h"

oferta* creareOferta(char* tip, char* destinatie, char* data_plecare, int pret)
{
    oferta* of = (oferta*)malloc(sizeof(oferta));
    int ok = validareOferta(tip,destinatie, data_plecare, pret);
    int nr_tip = (int) strlen(tip) + 1;
    of->tip = (char*)malloc(nr_tip * sizeof (char));
    strcpy(of->tip, tip);

    int nr_destinatie = (int) strlen(destinatie) + 1;
    of->destinatie = (char*)malloc(nr_destinatie * sizeof (char));
    strcpy(of->destinatie, destinatie);

    int nr_data_plecare = (int) strlen(data_plecare) + 1;
    of->data_plecare = (char*)malloc( nr_data_plecare * sizeof (char));
    strcpy(of->data_plecare, data_plecare);
    if (ok)
    {
        of->pret = pret;
        return of;
    } else
    {
        of->pret = -1;
        return of;
    }
}

void distruge_oferta(oferta* of)
{
    free(of->tip);
    free(of->destinatie);
    free(of->data_plecare);
    free(of);
}

int validareOferta(char* tip, char* destinatie, char* data_plecare, int pret)
{
    if (strcmp(tip, "munte") && strcmp(tip, "mare") && strcmp(tip, "city break"))
        return 0;
    if (strlen(destinatie) > 50)
        return 0;
    if (pret < 0 || pret >= 100000)
        return 0;
    return 1;
}

ListaMea creareLista()
{
    ListaMea l;
    l.lg = 0;
    l.capacitate = 1;
    l.of = (oferta**) malloc(l.capacitate * sizeof(oferta*));
    return l;
}

void distrugeLista(ListaMea* lista)
{
    for(int i=0; i<lista->lg; i++)
    {
        distruge_oferta(lista->of[i]);
    }
    free(lista->of);
}

int lungime(ListaMea* l)
{
    return l->lg;
}

void adaugaSf(ListaMea* l, oferta* of)
{
    if(l->lg == l->capacitate)
    {
        int new_cap = l->capacitate*2;
        oferta** aux = (oferta**)malloc(sizeof(oferta*)*new_cap);
        for(int i=0; i<l->lg; i++)
            aux[i] =l->of[i];
        free(l->of);
        l->of = aux;
        l->capacitate = new_cap;
    }
    l->of[l->lg] = of;
    l->lg++;
}

void stergere(ListaMea* lista, int poz)
{
    distruge_oferta(lista->of[poz]);
    for(int i=poz; i < lista->lg-1; i++)
        lista->of[i] = lista->of[i+1];
    lista->lg--;
}

void modificare(ListaMea* lista, int poz, char* tip, char* destinatie, char* data_plecare, int pret)
{
    free(lista->of[poz]->tip);
    free(lista->of[poz]->destinatie);
    free(lista->of[poz]->data_plecare);
    oferta* old = lista->of[poz];
    int nr_tip = (int) strlen(tip) + 1;
    old->tip = (char*)malloc(nr_tip * sizeof (char));
    strcpy(old->tip, tip);

    int nr_destinatie = (int) strlen(destinatie) + 1;
    old->destinatie = (char*)malloc(nr_destinatie * sizeof (char));
    strcpy(old->destinatie, destinatie);

    int nr_data_plecare = (int) strlen(data_plecare) + 1;
    old->data_plecare = (char*)malloc( nr_data_plecare * sizeof (char));
    strcpy(old->data_plecare, data_plecare);

    old->pret = pret;

    strcpy(lista->of[poz]->tip, tip);
    strcpy(lista->of[poz]->destinatie, destinatie);
    strcpy(lista->of[poz]->data_plecare, data_plecare);

}

int compare_pret(oferta* of1, oferta* of2)
{
    if(of1->pret > of2->pret)
        return 1;
    return 0;
}

int comapare_destinatie(oferta* of1, oferta* of2)
{
    if(strcmp(of1->destinatie,of2->destinatie) > 0)
        return 1;
    return 0;
}

void ordoneaza_pret(ListaMea* lista, char* cum, int(*cmp)(oferta*, oferta*))
{
    if(strcmp(cum, "c") == 0)
    {
        for(int i = 0; i<lista->lg - 1; i++)
        {
            for(int j = i+1; j<lista->lg; j++)
                if (cmp(lista->of[i], lista->of[j]))
                {
                    oferta* cnt = lista->of[i];
                    lista->of[i] = lista->of[j];
                    lista->of[j] = cnt;
                }
        }
    } else if (strcmp(cum, "d") == 0)
    {

        for(int i = 0; i<lista->lg - 1; i++)
        {
            for(int j = i+1; j<lista->lg; j++)
                if (!cmp(lista->of[i], lista->of[j]))
                {
                    oferta* cnt = lista->of[i];
                    lista->of[i] = lista->of[j];
                    lista->of[j] = cnt;
                }
        }
    }
}

void ordoneaza_destinatie(ListaMea* lista, char* cum, int(*cmp)(oferta*, oferta*))
{
    if(strcmp(cum, "c") == 0)
    {
        for(int i = 0; i<lista->lg - 1; i++)
        {

            for(int j = i+1; j<lista->lg; j++)
                if (strcmp(lista->of[i]->destinatie,lista->of[j]->destinatie) > 0)
                {
                    oferta* cnt = lista->of[i];
                    lista->of[i] = lista->of[j];
                    lista->of[j] = cnt;
                }
        }
    } else if (strcmp(cum, "d") == 0)
    {
        for(int i = 0; i<lista->lg - 1; i++)
        {
            for(int j = i+1; j<lista->lg; j++)
                if (strcmp(lista->of[i]->destinatie,lista->of[j]->destinatie) < 0)
                {
                    oferta* cnt = lista->of[i];
                    lista->of[i] = lista->of[j];
                    lista->of[j] = cnt;
                }
        }
    }
}

ListaMea filtreaza_dest_tip(ListaMea* lista, char* criteriu, char* sir)
{
    ListaMea lista_filtrata = creareLista();
    if(strcmp(criteriu, "d") == 0)
    {
        for(int i=0; i<lista->lg; i++)
            if(strcmp(lista->of[i]->destinatie, sir) == 0)
            {
                printf("aici");
                adaugaSf(&lista_filtrata, lista->of[i]);
            }
    } else if(strcmp(criteriu, "t") == 0)
    {
        for(int i=0; i<lista->lg; i++)
            if(strcmp(lista->of[i]->tip, sir) == 0)
            {
                adaugaSf(&lista_filtrata, lista->of[i]);
            }
    }
    return lista_filtrata;
}

ListaMea filtreaza_pret(ListaMea* lista, int pret)
{
    ListaMea lista_filtrata = creareLista();
    for(int i=0; i<lista->lg; i++)
        if(lista->of[i]->pret == pret)
        {
            adaugaSf(&lista_filtrata, lista->of[i]);
        }
    return lista_filtrata;
}


