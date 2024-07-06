#include "domain.h"
#include "teste.h"
#include <assert.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "ui.h"

void test_all()
{
    testCreareOferta();
    testDistrugeOferta();
    testValidareOferta();
    testCreareLista();
    testDistrugeLista();


    testAdauga();

    testSterge();
    testLungime();
    testModifica();
    testOrdoneaza_pret();
    testOrdoneaza_destinatie();
    testFiltreaza_tip_dest();
    testFiltreaza_pret();


    printf("SUCCES TESTE\n");
}

void testCreareOferta()
{
    oferta* of = creareOferta("mare", "Alba", "2021/01/02", 123);
    assert(strcmp(of->tip, "mare") == 0);
    assert(strcmp(of->destinatie, "Alba") == 0);
    assert(of->pret == 123);
    distruge_oferta(of);
    oferta* of2 = creareOferta("gresit", "gresit", "2021/02/02", 123);
    assert(of2->pret == -1);
    distruge_oferta(of2);
}

void testDistrugeOferta()
{
    oferta* of = creareOferta("mare", "Alba", "2021/01/02", 123);
    assert(strcmp(of->tip, "mare") == 0);
    assert(strcmp(of->destinatie, "Alba") == 0);
    distruge_oferta(of);
}

void testValidareOferta()
{
    assert(validareOferta("mare", "alba", "2021/01/01", 123) == 1);
    assert(validareOferta("gresit", "alba", "2021/01/01", 123) == 0);
    assert(validareOferta("munte", "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa", "2021/01/01", 123) == 0);
    assert(validareOferta("city break", "alba", "2021/01/01", 100000) == 0);
    assert(validareOferta("gresit", "alba", "2021/01/01", -10) == 0);
}

void testCreareLista()
{
    ListaMea test_lista = creareLista();
    assert(test_lista.lg == 0);
    assert(lungime(&test_lista) == 0);
    distrugeLista(&test_lista);
    assert(test_lista.lg == 0);

}

void testDistrugeLista()
{
    ListaMea test_lista1 = creareLista();
    assert(test_lista1.lg == 0);
    adaugaSf(&test_lista1, creareOferta("munte", "alba", "2021/01/01", 123));
    assert(test_lista1.lg == 1);
    distrugeLista(&test_lista1);
}

void testLungime()
{
    ListaMea lista = creareLista();
    assert(lungime(&lista) == 0);
    oferta* of = creareOferta("munte", "alba", "2021/01/01", 123);
    adaugaSf(&lista, of);
    assert(lungime(&lista) == 1);
    stergere(&lista, 0);
    assert(lungime(&lista) == 0);
    distrugeLista(&lista);
}

void testAdauga()
{
    ListaMea lista = creareLista();
    assert(lungime(&lista) == 0);
    adaugaSf(&lista, creareOferta("munte", "alba", "2021/01/01", 123));
    assert(lungime(&lista) == 1);
    adaugaSf(&lista, creareOferta("mare", "cluj", "2021/01/01", 1000));
    assert(lungime(&lista) == 2);
    adaugaSf(&lista, creareOferta("city break", "alba", "2021/01/01", 650));
    assert(lungime(&lista) == 3);
    distrugeLista(&lista);
}

void testSterge()
{
    ListaMea lista = creareLista();
    assert(lungime(&lista) == 0);
    adaugaSf(&lista, creareOferta("munte", "alba", "2021/01/01", 123));
    assert(lungime(&lista) == 1);
    stergere(&lista, 0);
    assert(lungime(&lista) == 0);
    adaugaSf(&lista, creareOferta("mare", "cluj", "2021/01/01", 1450));
    adaugaSf(&lista, creareOferta("munte", "alba", "2021/01/01", 123));
    assert(lungime(&lista) == 2);
    assert(strcmp(lista.of[0]->tip, "mare") == 0);
    assert(lista.of[0]->pret == 1450);
    stergere(&lista, 0);
    assert(strcmp(lista.of[0]->tip, "munte") == 0);
    assert(lista.of[0]->pret == 123);
    distrugeLista(&lista);
}

void testModifica()
{
    ListaMea lista = creareLista();
    assert(lungime(&lista) == 0);
    adaugaSf(&lista, creareOferta("munte", "alba", "2021/01/01", 123));
    adaugaSf(&lista, creareOferta("mare", "cluj", "2023/01/01", 1500));
    assert(lista.of[1]->pret == 1500);
    assert(strcmp(lista.of[1]->tip, "mare") == 0);
    assert(strcmp(lista.of[1]->destinatie, "cluj") == 0);
    modificare(&lista, 1, "city break", "Botosani", "2023/10/10", 1000);
    assert(strcmp(lista.of[1]->tip, "city break") == 0);
    assert(lista.of[1]->pret == 1000);
    assert(strcmp(lista.of[1]->destinatie, "Botosani") == 0);
    distrugeLista(&lista);
}

void testOrdoneaza_pret()
{
    ListaMea lista = creareLista();
    assert(lungime(&lista) == 0);
    adaugaSf(&lista, creareOferta("munte", "alba", "2021/01/01", 123));
    adaugaSf(&lista, creareOferta("mare", "cluj", "2023/01/01", 1500));
    assert(lista.of[0]->pret == 123);
    assert(strcmp(lista.of[0]->tip, "munte") == 0);
    assert(lista.of[1]->pret == 1500);
    assert(strcmp(lista.of[1]->tip, "mare") == 0);
    ordoneaza_pret(&lista, "d", compare_pret);
    //print_lista(&lista);
    assert(lista.of[0]->pret == 1500);
    assert(strcmp(lista.of[0]->tip, "mare") == 0);
    assert(lista.of[1]->pret == 123);
    assert(strcmp(lista.of[1]->tip, "munte") == 0);
    //mare si munte si city break
    adaugaSf(&lista, creareOferta("city break", "cluj", "2023/01/01", 500));
    ordoneaza_pret(&lista, "c", compare_pret);
    //print_lista(&lista);
    assert(lista.of[0]->pret == 123);
    assert(strcmp(lista.of[0]->tip, "munte") == 0);
    assert(lista.of[1]->pret == 500);
    assert(strcmp(lista.of[1]->tip, "city break") == 0);
    assert(lista.of[2]->pret == 1500);
    distrugeLista(&lista);
}

void testOrdoneaza_destinatie()
{
    ListaMea lista = creareLista();
    assert(lungime(&lista) == 0);
    adaugaSf(&lista, creareOferta("munte", "alba", "2021/01/01", 123));
    adaugaSf(&lista, creareOferta("mare", "cluj", "2023/01/01", 1500));
    assert(lista.of[0]->pret == 123);
    assert(strcmp(lista.of[0]->destinatie, "alba") == 0);
    assert(lista.of[1]->pret == 1500);
    assert(strcmp(lista.of[1]->destinatie, "cluj") == 0);
    ordoneaza_destinatie(&lista, "d", comapare_destinatie);
    assert(lista.of[0]->pret == 1500);
    assert(strcmp(lista.of[0]->destinatie, "cluj") == 0);
    assert(lista.of[1]->pret == 123);

    adaugaSf(&lista, creareOferta("munte", "botosani", "2021/01/01", 1234));
    ordoneaza_destinatie(&lista, "c", comapare_destinatie);
    assert(lista.of[0]->pret == 123);
    assert(strcmp(lista.of[0]->destinatie, "alba") == 0);
    assert(lista.of[1]->pret == 1234);
    assert(strcmp(lista.of[1]->destinatie, "botosani") == 0);
    assert(lista.of[2]->pret == 1500);
    assert(strcmp(lista.of[2]->destinatie, "cluj") == 0);
    distrugeLista(&lista);

}

void testFiltreaza_tip_dest()
{
    ListaMea lista = creareLista();
    assert(lungime(&lista) == 0);
    adaugaSf(&lista, creareOferta("mare", "alba", "2021/01/01", 123));
    adaugaSf(&lista, creareOferta("mare", "cluj", "2023/01/01", 1500));
    adaugaSf(&lista, creareOferta("munte", "cluj", "2023/01/01", 1500));
    assert(lungime(&lista) == 3);
    ListaMea lista_filtrata = filtreaza_dest_tip(&lista, "t", "mare");
    assert(lungime(&lista_filtrata) == 2);
    assert(strcmp(lista_filtrata.of[0]->destinatie, "alba") == 0);
    free(lista_filtrata.of);
    ListaMea lista_filtrata2 = filtreaza_dest_tip(&lista, "t", "munte");
    assert(lungime(&lista_filtrata2) == 1);
    free(lista_filtrata2.of);
    ListaMea lista_filtrata3 = filtreaza_dest_tip(&lista, "d", "cluj");
    assert(lungime(&lista_filtrata3) == 2);
    assert(strcmp(lista_filtrata3.of[0]->tip, "mare") == 0);
    assert(strcmp(lista_filtrata3.of[1]->tip, "munte") == 0);
    free(lista_filtrata3.of);
    distrugeLista(&lista);

}


void testFiltreaza_pret()
{
    ListaMea lista = creareLista();
    assert(lungime(&lista) == 0);
    adaugaSf(&lista, creareOferta("mare", "alba", "2021/01/01", 123));
    adaugaSf(&lista, creareOferta("mare", "cluj", "2023/01/01", 1500));
    adaugaSf(&lista, creareOferta("munte", "cluj", "2023/01/01", 1500));
    ListaMea lista_filtrata = filtreaza_pret(&lista, 123);
    assert(lungime(&lista_filtrata) == 1);
    ListaMea lista_filtrata2 = filtreaza_pret(&lista, 1500);
    assert(lungime(&lista_filtrata2) == 2);
    assert(strcmp(lista_filtrata2.of[0]->tip, "mare") == 0);
    assert(strcmp(lista_filtrata2.of[1]->tip, "munte") == 0);
    distrugeLista(&lista);
    free(lista_filtrata.of);
    free(lista_filtrata2.of);
}
