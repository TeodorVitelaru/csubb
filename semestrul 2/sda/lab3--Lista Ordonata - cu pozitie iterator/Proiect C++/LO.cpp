#include "Iterator.h"
#include "LO.h"

#include <iostream>
using namespace std;

#include <exception>

int LO::cautaPrimLiber() {
    for (int i = 0; i < cp; i++) {
        if (v[i].element == NULL_TELEMENT) {
            return i;
        }
    }
    return sz;
}

//teta(1)
LO::LO(Relatie r){
	/* de adaugat */
    relatie = r;
    dimension = 0;
    start = -1;
}

//teta(1)
// returnare dimensiune
int LO::dim() const {
	/* de adaugat */
    return dimension;
}

//teta(1)
// verifica daca LO e vida
bool LO::vida() const {
	/* de adaugat */
    return dimension == 0;
}

//teta(1)
// prima pozitie din LO
Iterator LO::prim() const {
	/* de adaugat */
    Iterator it(*this);
    it.prim();
    return it;

}

//teta(1)
// returnare element de pe pozitia curenta
//arunca exceptie daca poz nu e valid
TElement LO::element(Iterator poz) const {
	/* de adaugat */
    if(!poz.valid())
    {
        throw std::runtime_error("Iteratorul nu este valid");
    }
    return poz.element();
}


//O(n)
//sterge element de pe o pozitie poz si returneaza elementul sters
//dupa stergere poz e pozitionat pe elementul de dupa cel sters
//arunca exceptie daca poz nu e valid
TElement LO::sterge(Iterator& poz) {
	/* de adaugat */
       if(!poz.valid())
        {
            throw std::runtime_error("Iteratorul nu este valid");
        }
        TElement e = poz.element();
        int go = start;
        if(go == poz.curent)
        {
            start = v[go].next;
            v[go].element = NULL_TELEMENT;
            dimension--;
            poz.urmator();
            return e;
        }
        while(v[go].next != poz.curent)
        {
            go = v[go].next;
        }
        v[go].next = v[poz.curent].next;
        v[poz.curent].element = NULL_TELEMENT;
        dimension--;
        poz.urmator();
        return e;
}

//O(n)
// cauta element si returneaza prima pozitie pe care apare (sau iterator invalid)
Iterator LO::cauta(TElement e) const {
    /* de adaugat */
    Iterator it(*this);
    while(it.valid())
    {
        if(it.element() == e)
        {
            return it;
        }
        it.urmator();
    }
    return it;
}

//O(n)
// adaugare element in LO
void LO::adauga(TElement e) {
	/* de adaugat */
    if(dimension == 0)
    {
        sz=0;
        v[0].element = e;
        v[0].next = -1;
        start = 0;
        dimension++;
        sz++;
        if(sz == cp)
        {
            resize();
        }
        return;
    }
    dimension++;
    int primLiber = cautaPrimLiber();
    if(primLiber == sz)
    {
        v[sz].element = e;
        v[sz].next = -1;
        sz++;
        if(sz == cp)
        {
            resize();
        }
    }
    else
    {
        v[primLiber].element = e;
    }
    int go = start;
    if(!relatie(v[go].element, e))
    {
        v[primLiber].next = start;
        start = primLiber;
        return;
    }
    while(v[go].next != -1 && relatie(v[v[go].next].element, e))
    {
        go = v[go].next;
    }
    v[primLiber].next = v[go].next;
    v[go].next = primLiber;
}


//teta(n)
//destructor
LO::~LO() {
	/* de adaugat */
    delete[] v;
}
