#include "Matrice.h"
#include <iostream>
#include <stdexcept>

using namespace std;

//complexitate: teta(dim)
void Matrice::redim()
{
    cap = 2*cap;
    Triplet* aux = new Triplet[cap];
    //copiem elementele in aux
    for(int i=0; i<dim; i++)
        aux[i] = v[i];
    // eliberam vechea zona
    delete[]v;
    v=aux;

}

//complexitate: teta(1)
Matrice::Matrice(int m, int n) {
	/* de adaugat */
    if (m <= 0 || n <= 0)
        throw std::runtime_error("Nu e ok");
    nr_lin = m;
    nr_col = n;
    cap = 5;
    dim = 0;
    v = new Triplet[cap];

}


//complexitate: teta(1)
int Matrice::nrLinii() const{
	/* de adaugat */
    return nr_lin;
}

//complexitate: teta(1)
int Matrice::nrColoane() const{
	/* de adaugat */
    return nr_col;
}


//complexitate
//caz favorabil: teta(1)
//caz defavorabil:: teta(dim)
//caz mediu: teta(dim)
//caz general: O(dim)
TElem Matrice::element(int i, int j) const{
	/* de adaugat */
	//se arunca exceptie daca nu exista poz cautata
    if(i>=nrLinii() || j>=nrColoane() || i<0 || j>0)
    {
        throw std::runtime_error("Nu e ok");
    }
    //se cauta elementul
    for(int cnt=0; cnt<dim; cnt++)
    {
        if(v[cnt].lin == i && v[cnt].col == j)
            return v[cnt]. val;
    }
    return NULL_TELEMENT;
}


//complexitate
//caz favorabil: teta(1)
//caz defavorabil: teta(dim)
//caz general: O(dim)
TElem Matrice::modifica(int i, int j, TElem e) {
    //se arunca exceptie daca nu e pozitiile nu sunt valide in Matrice


    if (i >= nrLinii() || i < 0 || j >= nrColoane() || j < 0) {
        throw exception();
        return NULL_TELEMENT;
    }

    //daca valoarea este 0, eliminam tripletul din vector
    if (e == NULL_TELEMENT) {
        for (int cnt = 0; cnt < dim; cnt++)
        {
            if (v[cnt].lin == i && v[cnt].col == j)
            {
                TElem vecheaValoare = v[cnt].val;

                for (int m = cnt; m < dim - 1; m++)
                    v[m] = v[m + 1];
                dim--;
                return vecheaValoare;
            }
        }
        //daca nu s a gasit, atunci returnam null
        return NULL_TELEMENT;
    }

    //daca valoarea este diferita de 0, modificam
    for (int cnt = 0; cnt < dim; cnt++)
        if (v[cnt].lin == i && v[cnt].col == j) {
            TElem vecheaValoare = v[cnt].val;
            v[cnt].val = e;  //daca il gasim ii schimbam valoarea
            return vecheaValoare;
        }


    //daca nu il gasim, adaugam un nou triplet
    if (dim >= cap)
        redim();

    int cnt = dim;
    while (cnt > 0 && (i < v[cnt - 1].lin || (i == v[cnt - 1].lin && j < v[cnt - 1].col)))
    {
        v[cnt] = v[cnt - 1];
        cnt--;
    }

    //punem noul element pe pozitia corecta in vector si cresc dimensiunea
    v[cnt] = { i, j, e };
    dim++;
    return NULL_TELEMENT;
}

Iterator Matrice::iterator() {
    return Iterator(*this);
}

Iterator::Iterator(const Matrice & _m): m(_m){
    curent = 0;
}

void Iterator::prim() {
    curent = 0;
}

bool Iterator::valid() const {
    return curent < m.dim;
}

TElem Iterator::element() const {
    return m.v[curent].val;
}

void Iterator::urmator() {
    curent++;
}


