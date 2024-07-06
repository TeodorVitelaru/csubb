#include <exception>
#include "Iterator.h"
#include "DO.h"

using namespace std;

/*
 * Complexitate: Theta(1)
 */
Iterator::Iterator(const DO& d) : dict(d){
	/* de adaugat */
    if (dict.vid()) {
        current = -1;
    } else {
        current = dict.root;
    }
}

/*
 * Complexitate: O(h), unde h este inaltimea arborelui
 */
void Iterator::prim(){
	/* de adaugat */
    current = dict.root;
    if (current != -1) {
        while (dict.elems[current].left != -1) {
            current = dict.elems[current].left;
        }
    }
}

/*
 * Complexitate: O(h), unde h este inaltimea arborelui
 */
void Iterator::urmator(){
	/* de adaugat */
    if (!valid()) {
        throw exception();
    }

    if (dict.elems[current].right != -1) {
        current = dict.elems[current].right;
        while (dict.elems[current].left != -1) {
            current = dict.elems[current].left;
        }
    } else {
        int parent = -1;
        int aux = dict.root;
        while (aux != current) {
            if (dict.rel(dict.elems[current].info.first, dict.elems[aux].info.first)) {
                parent = aux;
                aux = dict.elems[aux].left;
            } else {
                aux = dict.elems[aux].right;
            }
        }
        current = parent;
    }
}

/*
 * Complexitate: Theta(1)
 */
bool Iterator::valid() const{
	/* de adaugat */
    return current != -1;
}

/*
 * Complexitate: Theta(1)
 */
TElem Iterator::element() const{
	/* de adaugat */
    if (!valid()) {
        throw exception();
    }
    return dict.elems[current].info;
}


