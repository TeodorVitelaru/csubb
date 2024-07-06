#include <algorithm>
#include "Service.h"

void Service::stergere(const Apartament& ap) {
    repo.del(ap);
}

vector<Apartament> Service::filtrare_pret(int min, int max) {
    vector<Apartament> new_vec;
    const vector<Apartament>& v = get_all();
    copy_if(v.begin(), v.end(), back_inserter(new_vec), [min, max](const Apartament& ap){return ap.get_pret() >= min && ap.get_pret() <= max;});
    return new_vec;
}

vector<Apartament> Service::filtrare_suprafata(int min, int max) {
    vector<Apartament> new_vec;
    const vector<Apartament>& v = get_all();
    copy_if(v.begin(), v.end(), back_inserter(new_vec), [min, max](const Apartament& ap){return ap.get_suprafata() >= min && ap.get_suprafata() <= max;});
    return new_vec;
}

void validare_numere(int nr1, int nr2)
{
    if(nr1 > nr2)
        throw Exception("Numerele nu sunt valide!");
    if(nr2 < 0 || nr1 < 0)
        throw Exception("Numerele nu pot fi negative!");
}
