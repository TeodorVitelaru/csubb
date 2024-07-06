#pragma once
typedef void* Telem;
typedef void (*DestroyFunction)(Telem);
typedef struct {
    int size;
    int cap;
    Telem* v;
}Vector_Struct;
typedef Vector_Struct* Vector;

int get_Vector_Size(Vector vec);

Telem* get_Vector_Array(Vector vec);

Vector create_vector(int cap);

Vector copy_vector(Vector vec);

void add_vector(Vector vec, Telem elem);

Telem get_vector_element(Vector vec, int poz);

void modify_vector_element(Vector vec, int poz, Telem elem, void (*delete_element)(void*));

Telem remove_vector_element(Vector vec, int poz, void (*delete_element)(void*));

void destroy_vector(Vector vec, void (*delete_element)(void*));

void destroy(Vector vec, DestroyFunction destrf);

void destroy_lista(Vector vec);