#pragma once

#include "domain.h"
#include "array.h"

typedef struct {
    Vector array;
    int size;
}Oferta_Repository;

typedef Oferta_Repository* Repository;

Repository create_Repo(int dim);

void detroy_Repo(Repository repo);

Vector get_Repo_Vector(Repository repo);

int get_Repo_Size(Repository repo);

void set_Repo_Size(Repository repo, int size);

//Functie care void care primeste ca parametru un struct Repo* si un struct Oferta*
//Functia adauga la array-ul din repo oferta;
void add_Oferta_Repo(Repository repo, Oferta to_add);

//Functie care void care primeste ca parametru un struct Repo*, un numar natural(id) si un struct Oferta*
//Functia sterge din memorie elementul de pe pozitia id si pe pozitia id din array se pune noua oferta;
void edit_Oferta_Repo(Repository repo, int id, Oferta to_replace);

//Functie care void care primeste ca parametru un struct Repo*, un numar natural(id) si un struct Oferta*
//Functia sterge din memorie elementul de pe pozitia id si se repozitioneaza tot array-ul din dreapta de id
void remove_Ofera_Repo(Repository repo, int id);

void test_repository(Repository repo);