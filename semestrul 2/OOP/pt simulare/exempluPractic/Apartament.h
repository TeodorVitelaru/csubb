#pragma once
#include <iostream>
#include <string>
using namespace std;

class Apartament {
private:
    int suprafata;
    string strada;
    int pret;
public:
    Apartament() = default;
    Apartament(int suprafata, string strada, int pret) :suprafata{ suprafata }, strada{ strada }, pret{ pret }{};
    Apartament(const Apartament& ot)
    {
        suprafata = ot.suprafata;
        strada = ot.strada;
        pret = ot.pret;
    }

    int get_suprafata() const;
    string get_strada() const;
    int get_pret() const;

    void set_suprafata(int _suprafata);
    void set_strada(string _strada);
    void set_pret(int _pret);

};


