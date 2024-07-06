#include "Iterator.h"
#include "DO.h"
#include <iostream>

#include <exception>
using namespace std;

/*
 * Complexitate: Theta(1)
 */
DO::DO(Relatie r) {
	/* de adaugat */
    rel = r;
    root = -1;
    size = 0;
    for(int i = 0; i < MAX; i++) {
        elems[i].left = -1;
        elems[i].right = -1;
        elems[i].info.first = NULL_TVALOARE;
        elems[i].info.second = NULL_TVALOARE;
    }
}

/*
 * Complexitate:
 *- caz favorabil: Theta(1)
 *- caz defavorabil: Theta(n)
 *- caz mediu: Theta(n)
 *- overall: O(n)
 */
//adauga o pereche (cheie, valoare) in dictionar
//daca exista deja cheia in dictionar, inlocuieste valoarea asociata cheii si returneaza vechea valoare
//daca nu exista cheia, adauga perechea si returneaza null
TValoare DO::adauga(TCheie c, TValoare v) {
	/* de adaugat */
    if(size == 0) {
        elems[0].info.first = c;
        elems[0].info.second = v;
        root = 0;
        size++;
        return NULL_TVALOARE;
    }
    int current = root;
    while(current != -1) {
        if(c == elems[current].info.first) {
            TValoare oldValue = elems[current].info.second;
            elems[current].info.second = v;
            return oldValue;
        } else if(rel(c, elems[current].info.first)) {
            if(elems[current].left == -1) {
                elems[size].info.first = c;
                elems[size].info.second = v;
                elems[current].left = size;
                size++;
                return NULL_TVALOARE;
            }
            current = elems[current].left;
        } else if(rel(elems[current].info.first, c)) {
            if(elems[current].right == -1) {
                elems[size].info.first = c;
                elems[size].info.second = v;
                elems[current].right = size;
                size++;
                return NULL_TVALOARE;
            }
            current = elems[current].right;
        }
    }
    return NULL_TVALOARE;
}

/*
 * Complexitate:
 * - caz favorabil: Theta(1)
 * - caz defavorabil: Theta(n)
 * - caz mediu: Theta(n)
 * - overall: O(n)
 */
//cauta o cheie si returneaza valoarea asociata (daca dictionarul contine cheia) sau null
TValoare DO::cauta(TCheie c) const {
	/* de adaugat */
    int current = root;
    while(current != -1) {
        if(c == elems[current].info.first) {
            return elems[current].info.second;
        } else if(rel(c, elems[current].info.first)) {
            current = elems[current].left;
        } else if(rel(elems[current].info.first, c)) {
            current = elems[current].right;
        }
    }
    return NULL_TVALOARE;
}

/*
 * Complexitate:
 * - caz favorabil: Theta(1)
 * - caz defavorabil: Theta(n)
 * - caz mediu: Theta(n)
 * - overall: O(n)
 */
//sterge o cheie si returneaza valoarea asociata (daca exista) sau null
TValoare DO::sterge(TCheie c) {
	/* de adaugat */
    int current = root;
    int parent = -1;
    bool isLeftChild = false;

    // Find the node with the given key
    while (current != -1) {
        if (c == elems[current].info.first) {
            break;
        } else if (rel(c, elems[current].info.first)) {
            parent = current;
            isLeftChild = true;
            current = elems[current].left;
        } else {
            parent = current;
            isLeftChild = false;
            current = elems[current].right;
        }
    }

    // If the key is not found, return NULL_TVALOARE
    if (current == -1) {
        return NULL_TVALOARE;
    }

    TValoare oldValue = elems[current].info.second;

    // Case 1: The node has no children
    if (elems[current].left == -1 && elems[current].right == -1) {
        if (current == root) {
            root = -1;
        } else if (isLeftChild) {
            elems[parent].left = -1;
        } else {
            elems[parent].right = -1;
        }
    }
        // Case 2: The node has one child
    else if (elems[current].right == -1) {
        if (current == root) {
            root = elems[current].left;
        } else if (isLeftChild) {
            elems[parent].left = elems[current].left;
        } else {
            elems[parent].right = elems[current].left;
        }
    } else if (elems[current].left == -1) {
        if (current == root) {
            root = elems[current].right;
        } else if (isLeftChild) {
            elems[parent].left = elems[current].right;
        } else {
            elems[parent].right = elems[current].right;
        }
    }
        // Case 3: The node has two children
    else {
        // Find the in-order predecessor
        int pred = elems[current].left;
        while (elems[pred].right != -1) {
            pred = elems[pred].right;
        }

        // Replace the node with the in-order predecessor
        elems[current].info = elems[pred].info;

        // Remove the in-order predecessor
        if (elems[pred].left != -1) {
            elems[pred].info = elems[elems[pred].left].info;
            elems[pred].left = -1;
        } else {
            elems[pred].info.first = NULL_TVALOARE;
            elems[pred].info.second = NULL_TVALOARE;
        }
    }

    size--;
    return oldValue;

}

//returneaza numarul de perechi (cheie, valoare) din dictionar
int DO::dim() const {
	/* de adaugat */
    return size;
}

//verifica daca dictionarul e vid
bool DO::vid() const {
	/* de adaugat */
    return size == 0;
}

// Complexitate: Theta(n)
/*
 * Subalgortim goleste(do)
 * preconditii:
 * - do: DO cu elemente
 * postconditii:
 * - do=0, se sterg toate elementele
 * sublagoritm goleste(do)
 *     cat timp !vid(do) executa
 *          sterge(do, do.radacina.valoare)
 *     sf_cat timp
 * sf_subalgoritm
 */
void DO::goleste() {
    while (!vid()) {
        sterge(elems[root].info.first);
    }
}

Iterator DO::iterator() const {
	return  Iterator(*this);
}


DO::~DO() {
	/* de adaugat */
}
