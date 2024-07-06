#pragma once
#include "array.h"
#include "domain.h"
#include <stdlib.h>
#include <stdio.h>
int get_Vector_Size(Vector vec)
{
    return vec->size;
}


Telem* get_Vector_Array(Vector vec)
{
    return vec->v;
}


Vector create_vector(int cap)
{
    Vector vec = (Vector)malloc(sizeof(Vector_Struct));
    if(vec==NULL)
        return NULL;
    vec->size = 0;
    vec->cap = cap;
    vec->v = (Telem*)malloc(vec->cap * sizeof(Telem));
    return vec;
}

Vector copy_vector(Vector vec)
{
    Vector new_vect = create_vector(vec->cap);
    for(int i=0; i<vec->size; i++)
    {
        add_vector(new_vect, copy_oferta(vec->v[i]));
    }
    //printf("%d%d\n", new_vect->size, vec->size);
    return new_vect;
}

void add_vector(Vector vec, Telem elem)
{
    if (vec->size >= vec->cap)
    {
        int new_cap = vec->cap * 2;
        Telem* aux = malloc(sizeof(Telem) * new_cap);
        for (int i = 0; i < vec->size; i++)
            aux[i] = vec->v[i];
        free(vec->v);
        vec->v = aux;
        vec->cap = new_cap;
    }
    vec->v[vec->size] = elem;
    vec->size++;


    //if (get_Vector_Size(vec) == vec->cap)
        //vec->v = resize_vector(vec->v, vec->size, 2 * vec->cap);
    //vec->v[vec->size++] = elem;
}
Telem get_vector_element(Vector vec, int poz)
{
    if (poz < get_Vector_Size(vec) )
        return vec->v[poz];
    return NULL;
}
void modify_vector_element(Vector vec, int poz, Telem elem, void (*delete_element)(void*))
{
    if (poz < vec->size)
        delete_element(vec->v[poz]), vec->v[poz]=elem;
}
Telem remove_vector_element(Vector vec, int poz, void (*delete_element)(void*))
{
    Telem elem = vec->v[poz];
    if(poz<vec->size)
    {
        delete_element(vec->v[poz]);
        for (int i = poz; i < get_Vector_Size(vec) -1 ; i++)
            vec->v[i] = vec->v[i + 1];
        vec->size--;
    }
    return elem;
}
void destroy_vector(Vector vec, void(*delete_element)(void*))
{
    //printf("aiiicici");
    for (int i = 0; i < get_Vector_Size(vec); i++)
    {
        //printf("%d", i);
        delete_element(vec->v[i]);
    }
    //printf("\n");
    free(vec->v);
    free(vec);
}

void destroy(Vector vec, DestroyFunction destrf)
{
    for (int i = 0; i < get_Vector_Size(vec); i++)
    {
        Telem p = vec->v[i];
        destrf(p);
    }
    free(vec->v);
    free(vec);
}

void destroy_lista(Vector vec)
{
    destroy_vector(vec, delete_Oferta);
}

