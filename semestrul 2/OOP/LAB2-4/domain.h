//
// Created by Admin on 2024-03-08.
//

#ifndef LAB2_4_DOMAIN_H
#define LAB2_4_DOMAIN_H

typedef struct
{
    char* tip;
    char* destinatie;
    char* data_plecare;
    int pret;
}oferta;

typedef struct
{
    oferta** of;
    int lg; //lungime
    int capacitate; //capacitate
}ListaMea;


/*
 * Functie creaza oferta de tip struct
 * @param: tip-char din multimea {mare,munte,city break}, destinatie-char, data_plecare-char, pret-int --- campurile ofertei
 * @return: oferta de tip struct
 */
oferta* creareOferta(char* tip, char* destinatie, char* data_plecare, int pret);


/*
 * Functia distruge oferta
 * @param: of-oferta ce trebuie distrusa
 * @return: nimic
 */
void distruge_oferta(oferta* of);


/*
 * Functie distruge lista curenta de elemente
 * @param: lista-lista de elemente
 * @return: -
 */
void distrugeLista(ListaMea* lista);


/*
 * Functia valideaza datele pentru oferta
 * @param: tip-char, destinatie-char, data_plecare-char, pret-int --- campurile ofertei
 * @return: 1 sau 0 daca datele introduse sunt corecte sau incorecte
 */
int validareOferta(char* tip, char* destinatie, char* data_plecare, int pret);

/*
 * Functia creaza lista de oferta
 * @param: nu are paremtrii
 * @return: lista vida de oferte de tip struct
 */
ListaMea creareLista();


/*
 * Functia returneaza lungimea listei
 * @param: lista de oferte de tip struct
 * @return: numarul de elemnte din lista
 */
int lungime(ListaMea* l);


/*
 * Functia adauga la sfarsitul listei o oferta
 * @param: l-lista de oferte, of-oferta data
 * @return: nu se returneaza nimic
 */
void adaugaSf(ListaMea* l, oferta* of);


/*
 * Sterge oferta de pe o pozitie
 * @param: lista-lista de oferte, poz-pozitia ofertei de sters
 * @return: nimic
 */
void stergere(ListaMea* lista, int poz);


/*
 * Modifica oferta de pe o pozitie
 * @param: lista-lista de oferte, poz-pozitia ofertei de modiciat, tip, destinatie, data_plecare, pret-datele ofertei
 * @return: nimic
 */
void modificare(ListaMea* lista, int poz, char* tip, char* destinatie, char* data_plecare, int pret);


int compare_pret(oferta* of1, oferta* of2);

int comapare_destinatie(oferta* of1, oferta* of2);

/*
 * Ordoneaza lista in functie de pret
 * @param: lista-lista de oferte, cum-modul in care se sorteaza
 * @return: nimic
 */
void ordoneaza_pret(ListaMea* lista, char* cum, int(*cmp)(oferta*, oferta*));


/*
 * Ordoneaza lista in functie de destinatie
 * @param: lista-lista de oferte, cum-modul in care se sorteaza
 * @return: nimic
 */
void ordoneaza_destinatie(ListaMea* lista, char* cum, int(*cmp)(oferta*, oferta*));


/*
 * Filtreaza lista de oferte dupa destinatie sau tip
 * @param: lista-lista de oferte, criteriu-destinatie sau tip, sir-sirul de caractere dupa care se filtreaza
 * @return: noua lista de oferte care indepliensc conditiile vrute de utilizator
 */
ListaMea filtreaza_dest_tip(ListaMea* lista, char* criteriu, char* sir);


/*
 * Filtreaza lista de oferte dupa pret
 * @param: lista-lista de oferte, pret-pretul dupa care se filtreaza
 * @return: o noua lista de oferte care au pretul dat
 */
ListaMea filtreaza_pret(ListaMea* lista, int pret);

#endif //LAB2_4_DOMAIN_H
