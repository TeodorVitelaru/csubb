#include "Apartament.h"
using namespace std;

int Apartament::get_suprafata() const {
    return suprafata;
}

string Apartament::get_strada() const {
    return strada;
}

int Apartament::get_pret() const {
    return pret;
}

void Apartament::set_suprafata(int _suprafata) {
    suprafata = _suprafata;
}

void Apartament::set_strada(string _strada) {
    strada = _strada;
}

void Apartament::set_pret(int _pret) {
    pret = _pret;
}


