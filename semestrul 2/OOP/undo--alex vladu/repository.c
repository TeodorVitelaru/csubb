#include <string.h>
#include <stdlib.h>
#include "domain.h"
#include <assert.h>
#include "repository.h"
#include "array.h"


Repository create_Repo(int dim)
{
    Repository repo = (Repository)malloc(sizeof(Oferta_Repository));
    if (repo == NULL)
        exit(-1);
    repo->array = create_vector(dim);
    repo->size = 0;
    return repo;
}
void detroy_Repo(Repository repo)
{
    destroy_vector(repo->array, delete_Oferta);
    free(repo);
}
Vector get_Repo_Vector(Repository repo)
{
    return repo->array;
}
int get_Repo_Size(Repository repo)
{
    return repo->size;
}
void set_Repo_Size(Repository repo, int size)
{
    repo->size=size;
}

void add_Oferta_Repo(Repository repo, Oferta to_add)
{
    add_vector(get_Repo_Vector(repo), to_add);
    set_Repo_Size(repo, get_Repo_Size(repo)+1);
}
void edit_Oferta_Repo(Repository repo, int id, Oferta to_replace)
{
    if(id<get_Repo_Size(repo))
        modify_vector_element(get_Repo_Vector(repo), id, to_replace, delete_Oferta);
}
void remove_Ofera_Repo(Repository repo, int id)
{
    if(id<get_Repo_Size(repo))
    {
        remove_vector_element(get_Repo_Vector(repo), id, delete_Oferta);
        set_Repo_Size(repo, get_Repo_Size(repo)-1);
    }
}
void test_repository(Repository repo)
{
    //Functie void care primeste ca parametru un repo
    //Functia testeaza atat add la repo, edit cat si delete;
    add_Oferta_Repo(repo, create_Oferta("apartament", 20, "Sibiu,str.Luncii,nr.14", 250));
    add_Oferta_Repo(repo, create_Oferta("apartament", 30, "Sibiu,str.Luncii,nr.15", 150));
    add_Oferta_Repo(repo, create_Oferta("apartament", 40, "Sibiu,str.Luncii,nr.16", 50));
    assert(get_Repo_Size(repo)==3);
    Oferta element=(Oferta)get_vector_element(get_Repo_Vector(repo), 2);
    assert(get_Oferta_pret(element)==50);
    element= (Oferta)get_vector_element(get_Repo_Vector(repo), 1);
    assert(get_Oferta_suprafata(element) == 30);
    remove_Ofera_Repo(repo, 2);
    remove_Ofera_Repo(repo, 1);
    assert(get_Repo_Size(repo)==1);
    edit_Oferta_Repo(repo, 0, create_Oferta("apartament", 69, "Brasov,str.Luncii,nr.16", 50));
    element = (Oferta)get_vector_element(get_Repo_Vector(repo), 0);
    assert(get_Oferta_suprafata(element)==69);
}