#include "IteratorMultime.h"
#include "Multime.h"

/*
 * complexitatea timp: teta(1)
 */
IteratorMultime::IteratorMultime(const Multime& m) : multime(m){
	/* de adaugat */
    curent = m.prim;
}

/*
 * complexitatea timp: teta(1)
 */
void IteratorMultime::prim() {
	/* de adaugat */
    curent = multime.prim;
}

/*
 * complexitatea timp: teta(1)
 */
void IteratorMultime::urmator() {
	/* de adaugat */
    curent = curent->urmator();
}

/*
 * complexitatea timp: teta(1)
 */
TElem IteratorMultime::element() const {
	/* de adaugat */
	return curent->element();
}

/*
 * complexitatea timp: teta(1)
 */
bool IteratorMultime::valid() const {
	/* de adaugat */
	return curent != nullptr;
}
