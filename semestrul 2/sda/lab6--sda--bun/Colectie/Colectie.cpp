#include "Colectie.h"
#include "IteratorColectie.h"
#include <exception>
#include <iostream>

using namespace std;

//complexitate: theta(1)
int hashCode(TElem e) {
    return abs(e);
}

//complexitate: theta(1)
int Colectie::d(TElem e) const {
    return hashCode(e) % m;
}

//complexitate: theta(m)
Colectie::Colectie() {
	/* de adaugat */
    m = MAX;
    for (int i = 0; i < m; i++) {
        e[i] = NULL_TELEM;
        urm[i] = NULL_TELEM.first;
    }
    primLiber = 0;
}

/*
 * Complexitate:
 * - caz favorabil: theta(1)
 * - caz defavorabil: theta(m)
 * - caz mediu: theta(m)
 * - overall: O(m)
 */
void Colectie::actPrimLiber() {
    primLiber++;
    while (primLiber < m && e[primLiber] != NULL_TELEM)
        primLiber++;
}

/*
 * Complexitate:
 * - caz favorabil: theta(1)
 * - caz defavorabil: theta(m)
 * - caz mediu: theta(m)
 * - overall: O(m)
 */
void Colectie::adauga(TElem elem) {
	/* de adaugat */
    int i = d(elem);
    if (e[i].first == NULL_TELEM.first) {
        e[i].first = elem;
        e[i].second ++;
        if (i == primLiber)
            actPrimLiber();
        return;
    }
    int j = NULL_TELEM.first;
    while (i != NULL_TELEM.first) {
        if(e[i].first == elem) {
            e[i].second ++;
            return;
        }
        j = i;
        i = urm[i];
    }
    if (primLiber >= m)
        throw runtime_error{ "Nu mai exista spatiu pentru adaugarea elementului!" };
    e[primLiber].first = elem;
    e[primLiber].second ++;
    urm[j] = primLiber;
    actPrimLiber();
}

/*
 * Complexitate:
 * - caz favorabil: theta(1)
 * - caz defavorabil: theta(m)
 * - caz mediu: theta(m)
 * - overall: O(m)
 */
bool Colectie::sterge(TElem elem) {
	/* de adaugat */
    if (vida())
        return false;
    int i = d(elem);
    int j = NULL_TELEM.first;
    while (i != NULL_TELEM.first) {
        if (e[i].first == elem) {
            if (e[i].second > 1) {
                // If the frequency is more than 1, decrease it
                e[i].second--;
            } else {
                // If the frequency is 1, remove the element
                if (j == NULL_TELEM.first)
                    urm[d(elem)] = urm[i];
                else
                    urm[j] = urm[i];
                e[i] = NULL_TELEM;
                if (i < primLiber)
                    primLiber = i;
            }
            return true;
        }
        j = i;
        i = urm[i];
    }
    return false; // return false if the element is not found
}

/*
 * Complexitate:
 * - caz favorabil: theta(1)
 * - caz defavorabil: theta(m)
 * - caz mediu: theta(m)
 * - overall: O(m)
 */
bool Colectie::cauta(TElem elem) const {
	/* de adaugat */
    if (vida())
        return false;
    int i = d(elem);
    while (i != NULL_TELEM.first) {
        if (e[i].first == elem)
            return true;
        i = urm[i];
    }
    return false;
}

/*
 * Complexitate:
 * - caz favorabil: theta(1)
 * - caz defavorabil: theta(m)
 * - caz mediu: theta(m)
 * - overall: O(m)
 */
int Colectie::nrAparitii(TElem elem) const {
	/* de adaugat */
    if (vida())
        return 0;
    int i = d(elem);
    while (i != NULL_TELEM.first) {
        if (e[i].first == elem)
            return e[i].second;
        i = urm[i];
    }
    return 0;
}

/*
 * Complexitate: theta(m)
 */
int Colectie::dim() const {
	/* de adaugat */
    int count = 0;
    for (int i = 0; i < m; i++)
        if (e[i] != NULL_TELEM)
        {
            count+= e[i].second;
        }
    return count;
}

/*
 * Complexitate:
 * - caz favorabil: theta(1)
 * - caz defavorabil: theta(m)
 * - caz mediu: theta(m)
 * - overall: O(m)
 */
bool Colectie::vida() const {
	/* de adaugat */
	    for (int i = 0; i < m; i++)
        if (e[i] != NULL_TELEM)
            return false;
    return true;
}

/*
 * Complexitate: theta(1)
 */
IteratorColectie Colectie::iterator() const {
	return  IteratorColectie(*this);
}


Colectie::~Colectie() {
	/* de adaugat */
}

/*
 * Complexitate:
 * - caz favorabil: theta(m)
 * - caz defavorabil: theta(m^2)
 * - caz mediu: theta(m^2)
 * - overall: O(m^2)
 * preconditii: colectie de tip input
 * postconditii: se sterg toate elementele care apar de mai multe ori in colectie
 * subalg StergeToateElementeleRepetite()
 *    count <- 0
 *    pentru i <- 0, m executa
 *      daca e[i] != NULL_TELEM si frecventa(e) > 1 atunci
 *          count <- count + e[i].second
 *          e[i].second <- 1
 *          sterge(e[i].element)
 *      sfarsit daca
 *    sfarsit pentru
 *    returneaza count
 */
int Colectie::StergeToateElementeleRepetitive() {
    int count = 0;
    for (int i = 0; i < m; i++) {
        if (e[i] != NULL_TELEM && e[i].second > 1) {
            count += e[i].second;
            e[i].second = 1;
            sterge(e[i].first);
        }
    }
    return count;
}


