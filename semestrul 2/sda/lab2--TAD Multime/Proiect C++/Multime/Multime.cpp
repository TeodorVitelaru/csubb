#include "Multime.h"
#include "IteratorMultime.h"

#include <iostream>

/*
 * complexitatea timp: teta(1)
 */
Nod::Nod(TElem e, PNod urm) {
    this->e = e;
    this->urm = urm;
}

/*
 * complexitatea timp: teta(1)
 */
TElem Nod::element() {
    return e;
}


/*
 * complexitatea timp: teta(1)
 */
PNod Nod::urmator() {
    return urm;
}

/*
 * complexitatea timp: teta(1)
 */
Multime::Multime() {
	/* de adaugat */
    prim = nullptr;
}

/*
 * complexitatea timp: O(n)
 */
bool Multime::adauga(TElem elem) {
	/* de adaugat */
	if(this->cauta(elem)) {
        return false;
    }
    PNod q = new Nod(elem, nullptr);
    q->urm = prim;
    prim = q;
    return true;
}

/*
 * complexitatea timp: O(n)
 */
bool Multime::sterge(TElem elem) {
	/* de adaugat */
	    if(prim == nullptr) {
        return false;
    }
    if(prim->e == elem) {
        PNod p = prim;
        prim = prim->urm;
        delete p;
        return true;
    }
    PNod p = prim;
    while(p->urm != nullptr) {
        if(p->urm->e == elem) {
            PNod q = p->urm;
            p->urm = q->urm;
            delete q;
            return true;
        }
        p = p->urm;
    }
    return false;
}

/*
 * complexitatea timp: O(n)
 */
bool Multime::cauta(TElem elem) const {
	/* de adaugat */
	PNod p = prim;
    while(p != nullptr) {
        if(p->e == elem) {
            return true;
        }
        p = p->urm;
    }
    return false;
}

/*
 * complexitatea timp: teta(n)
 */
int Multime::dim() const {
	/* de adaugat */
	int n = 0;
    PNod p = prim;
    while(p != nullptr) {
        n++;
        p = p->urm;
    }
    return n;
}

/*
 * complexitatea timp: teta(1)
 */
bool Multime::vida() const {
	/* de adaugat */
	return prim == nullptr;
}

/*
 * Complexitate: O(n)
 * preconditii:
 * -multime: Multime
 * -cond: Conditie
 * postconditii:
 * -multime: Multime
 * subalg filtrare(multime, cond)
 *    daca multi este vida atunci
 *    returneaza
 *    altfel
 *    p<-prim
 *    prev<-null
 *    cat timp p != null executa
 *    daca cond(p->e) = fals atunci
 *     daca prev = null atunci
 *      prim<-p->urm
 *      sterge(p)
 *      p<-prim
 *     altfel
 *      prev->urm<-p->urm
 *      sterge(p)
 *      p<-prev->urm
 *    altfel
 *    prev<-p
 *    p<-p->urm
 *
 */
void Multime::filtreaza(Conditie cond) {
    if(prim == nullptr) {
        return;
    }
    PNod p = prim;
    PNod prev = nullptr;
    while(p != nullptr) {
        if(!cond(p->e)) {
            if(prev == nullptr) {
                prim = p->urm;
                delete p;
                p = prim;
            } else {
                prev->urm = p->urm;
                delete p;
                p = prev->urm;
            }
        } else {
            prev = p;
            p = p->urm;
        }
    }
}

/*
 * complexitatea timp: teta(n)
 */
Multime::~Multime() {
	/* de adaugat */
    while(prim != nullptr) {
        PNod p = prim;
        prim = prim->urm;
        delete p;
    }
}

IteratorMultime Multime::iterator() const {
	return IteratorMultime(*this);
}

