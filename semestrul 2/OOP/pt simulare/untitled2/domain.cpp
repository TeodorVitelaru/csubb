
#include "domain.h"
#include <string>

using namespace std;

string Procesor::get_nume() const {
    return this->nume;
}

int Procesor::get_pret() const {
    return this->pret;
}

string Procesor::get_socluProcesor() const {
    return this->socluProcesor;
}

int Procesor::get_numarThreaduri() const {
    return this->numarThreaduri;
}

void Procesor::set_pret(int _pret) {
    pret = _pret;
}

void Procesor::set_numarThreaduri(int _numarThreaduri) {
    numarThreaduri = _numarThreaduri;
}

void Procesor::set_nume(string _nume) {
    nume = _nume;
}

void Procesor::set_socluProcesor(string _socluProcesor) {
    socluProcesor = _socluProcesor;
}