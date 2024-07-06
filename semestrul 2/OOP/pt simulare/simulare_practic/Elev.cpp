#include "Elev.h"

int Elev::get_nrMatricol() const {
    return nrMatricol;
}

string Elev::get_nume() const {
    return nume;
}

string Elev::get_scoala() const {
    return scoala;
}

void Elev::set_nrMatricol(int _nrMatricol) {
    nrMatricol = _nrMatricol;
}

void Elev::set_nume(string _nume) {
    nume = _nume;
}

void Elev::set_scoala(string _scoala) {
    scoala = _scoala;
}


