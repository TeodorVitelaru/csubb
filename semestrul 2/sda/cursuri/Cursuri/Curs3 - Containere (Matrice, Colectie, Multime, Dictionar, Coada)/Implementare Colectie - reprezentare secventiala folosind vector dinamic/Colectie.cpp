#include "Colectie.h"


void Colectie::redim() {
	//alocam un spatiu de capacitate dubla
	//copiem vechile valori in noua zona
	//dublam capacitatea
	//eliberam vechea zona
	//vectorul indica spre noua zona
}

Colectie::Colectie(int cp) {
	//alocam spatiu de memorare pentru vector
	//setam numarul de elemente
}

Colectie::~Colectie() {
}
int Colectie::dim() const{
}
void Colectie::adauga(TElem e) {
}

Iterator Colectie::iterator() {

Iterator::Iterator(const Colectie& _c) : c(_c) {
	//varianta 2
}

void Iterator::prim() {
	//varianta 2
}
bool Iterator::valid() const{
	//varianta 2
}

TElem Iterator::element() const{
	//varianta 2
}

void Iterator::urmator() {
}