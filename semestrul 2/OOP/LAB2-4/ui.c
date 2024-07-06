

#include<stdio.h>
#include<string.h>
#include "ui.h"
#include "domain.h"

void print_menu()
{
    printf("MENIU\n");
    printf("COMENZI DISONIBILE:");
    printf("a-adauga, m-modifica, s-sterge, p-printeaza lista, o-ordoneaza, f-filtreaza, i-iesire\n");
}

void print_oferta(oferta* of)
{
    printf("tip: %s, destinatie: %s, data plecarii: %s, pret:%d", of->tip, of->destinatie, of->data_plecare, of->pret);
}

void print_lista(ListaMea* lista)
{
    if(lista->lg > 0)
    {
        for(int i=0; i<lista->lg; i++)
        {
            printf("%d. ", i);
            print_oferta(lista->of[i]);
            printf("\n");
        }
        printf("\n");
    }
    else
    {
        printf("Lista este goala!\n");
    }
}

void read(char *string)
{
    fflush(stdin);
    fgets(string, 50, stdin);
    string[strlen(string)-1]='\0';
}

void adaugare_ui(ListaMea* lista)
{
    char tip[15], dest[50], data[50];
    int pret;
    printf("Introduceti tip:");
    read(tip);
    //scanf("%[^\n]%*c", tip);
    //scanf("%[^\n]%*c", tip);
    printf("Introduceti destinatie:");
    read(dest);
    printf("Introduceti data plecarii:");
    read(data);
    printf("Introduceti pretul:");
    scanf("%d", &pret);
    oferta* of = creareOferta(tip, dest, data, pret);
    if (of->pret == -1)
    {
        printf("EROARE! ADAUGARE NEREUSITA!\n");
    } else
    {
        adaugaSf(lista, of);
        printf("SUCCES!ADAUGARE REUSITA\n");
    }

}

void stergere_ui(ListaMea* lista)
{
    int poz;
    printf("Introduceti pozitia ofertei:");
    scanf("%d", &poz);
    if (poz<lista->lg)
    {
        stergere(lista, poz);
        printf("SUCCES! STERGERE REUSITA!\n");
    }else
    {
        printf("EROARE! STERGERE NEREUSITA!\n");
    }
}

void modificare_ui(ListaMea* lista)
{
    int poz, pret;
    char tip[15], dest[50], data[50];
    printf("Introduceti pozitia elementului de modificat:");
    scanf("%d", &poz);
    printf("Introduceti tip:");
    read(tip);
    printf("Introduceti destinatie:");
    read(dest);
    printf("Introduceti data plecarii:");
    read(data);
    printf("Introduceti pretul:");
    scanf("%d", &pret);
    oferta* of = creareOferta(tip, dest, data, pret);
    if (of->pret == -1 || poz >= lista->lg)
    {
        printf("EROARE! MODIFICARE NEREUSITA!\n");
    } else
    {
        modificare(lista, poz, tip, dest, data, pret);
        printf("SUCCES! MODIFICARE REUSITA!\n");
    }
}

void ordonare_ui(ListaMea* lista, int iesire)
{
    char mod[50];
    char cum[50];

    printf("Introduceti modul (c-crescator, d-descrescator):");
    read(cum);
    //nu ma lasa sa citesc inainte mod si dupa cum

    printf("Introduceti dupa ce sa fie ordonata lista (p-pret, d-destinatie):");
    read(mod);

    if(strcmp(mod, "p") == 0)
    {
        ordoneaza_pret(lista, cum, compare_pret);
        printf("%d\n", iesire);
        printf("SUCCES!Ordonare realizata!");
    }else if(strcmp(mod, "d") == 0)
    {
        ordoneaza_destinatie(lista, cum, comapare_destinatie);
        printf("SUCCES!Ordonare realizata!");
    } else
    {
        printf("EROARE!\n");
    }
    printf("%d\n", iesire);
}

void filtrare_ui(ListaMea* lista)
{
    char criteriu[3];
    printf("Intrduceti criteriu(d-destinatie, t-tip, p-pret):");
    read(criteriu);
    if (strcmp(criteriu, "p") == 0)
    {
        int pret;
        printf("Introduceti sirul:");
        scanf("%d", &pret);
        ListaMea lista_filtrata = filtreaza_pret(lista, pret);
        printf("Lista filtrata este:\n");
        print_lista(&lista_filtrata);
    } else if(strcmp(criteriu, "t") == 0 || strcmp(criteriu, "d") == 0)
    {
        char sir[50];
        printf("Introduceti sirul:");
        read(sir);
        ListaMea lista_filtrata = filtreaza_dest_tip(lista, criteriu, sir);
        printf("Lista filtrata este:\n");
        print_lista(&lista_filtrata);

    }
}

void run()
{
    ListaMea lista = creareLista();
    int iesire = 0;
    char cmd[50];
    while (1)
    {
        print_menu();
        printf("Introduceti comanda: ");
        read(cmd);
        if (strcmp(cmd, "i") == 0)
        {
            iesire = 1;
            distrugeLista(&lista);
            return;
        } else if(strcmp(cmd, "a") == 0)
        {
            adaugare_ui(&lista);
        } else if(strcmp(cmd, "p") == 0)
        {
            print_lista(&lista);
        } else if(strcmp(cmd, "s") == 0)
        {
            stergere_ui(&lista);
        } else if(strcmp(cmd, "m") == 0)
        {
            modificare_ui(&lista);
        } else if(strcmp(cmd, "o") == 0)
        {
            ordonare_ui(&lista, iesire);
            printf("%d", iesire);
        } else if(strcmp(cmd, "f") == 0)
        {
            filtrare_ui(&lista);
        }
    }
}