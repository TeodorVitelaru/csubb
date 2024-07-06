#include <stdexcept>
#include "Iterator.h"
#include "LO.h"

//teta(1)
Iterator::Iterator(const LO& lo) : lo(lo){
	/* de adaugat */
    curent = lo.start;
}

//teta(1)
void Iterator::prim(){
	/* de adaugat */
    curent = lo.start;
}

//teta(1)
void Iterator::urmator(){
	/* de adaugat */
    if(!valid())
    {
        throw std::runtime_error("Iteratorul nu este valid");
    }
    curent = lo.v[curent].next;
}

//complexitate: teta(1)
bool Iterator::valid() const{
	/* de adaugat */
	return curent != -1;
}

//teta(1)
TElement Iterator::element() const{
	/* de adaugat */
	if(!valid())
    {
        throw std::runtime_error("Iteratorul nu este valid");
    }
    return lo.v[curent].element;
}

/*
 * complexitate: teta(k)
 * preconditii:
 * - k este un numar pozitiv
 * postconditii:
 * -
 * subalg avanseazaKpasi()
 *   1.daca k<=0 atunci arunca exceptie
 *   2.sf daca
 *   3.daca iteratorul nu este valid atunci arunca exceptie
 *   4.sf daca
 *   5.cat timp k>0 si iteratorul este valid executa
 *   6. curent <- [curent].next
 *   7. k <- k-1
 *   8.sf cat timp
 *   9.daca k>0 atunci
 *   10. curent <- null
 *   11.sf daca
 *   12.sf algoritm
 *
 */
void Iterator::avanseazaKPasi(int k)
{
    if(k <= 0)
    {
        throw std::runtime_error("Numarul de pasi trebuie sa fie pozitiv");
    }
    if(!valid())
    {
        throw std::runtime_error("Iteratorul nu este valid");
    }
    while(k > 0 && valid())
    {
        curent = lo.v[curent].next;
        k--;
    }
    if(k > 0)
    {
        curent = -1;
    }
}


