#include "IteratorColectie.h"
#include "Colectie.h"

/*
 * Complexitate: theta(1)
 */
IteratorColectie::IteratorColectie(const Colectie& c): col(c) {
	/* de adaugat */
    curent = 0;
    frecv = 0;
    deplasare();
}

/*
 * Complexitate: theta(1)
 */
void IteratorColectie::prim() {
	/* de adaugat */
    curent = 0;
    frecv = 0;
    deplasare();
}

/*
 * Complexitate: theta(1)
 */
void IteratorColectie::urmator() {
	/* de adaugat */
    if (frecv == col.e[curent].second) {
        curent++;
        frecv = 0;
    }
    frecv++;
    deplasare();
}


bool IteratorColectie::valid() const {
	/* de adaugat */
	return curent < col.m;
}

/*
 * Complexitate: theta(1)
 */
void IteratorColectie::deplasare() {
    while (curent < col.m && (col.e[curent] == NULL_TELEM || frecv == col.e[curent].second)) {
        curent++;
        frecv = 0; // reset frecv each time curent is incremented
    }
}

/*
 * Complexitate: theta(1)
 */
TElem IteratorColectie::element() const {
	/* de adaugat */
    return col.e[curent].first;
}
