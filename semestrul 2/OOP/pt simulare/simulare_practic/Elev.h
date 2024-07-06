#pragma once
#include <iostream>
#include <string>

using namespace std;

class Elev {
private:
    int nrMatricol;
    string nume;
    string scoala;
    string atelier;
public:
    Elev() = default;
    Elev(int nrMatricol, string nume, string scoala) :nrMatricol{ nrMatricol }, nume{ nume }, scoala{ scoala }{};
    Elev(const Elev& ot)
    {
        nrMatricol = ot.nrMatricol;
        nume = ot.nume;
        scoala = ot.scoala;
        atelier = ot.atelier;
    }

    int get_nrMatricol() const;
    string get_nume() const;
    string get_scoala() const;

    void set_nrMatricol(int _nrMatricol);
    void set_nume(string _nume);
    void set_scoala(string _scoala);

    void set_atelier(string _atelier) { atelier = _atelier; }

    string get_atelier() const
    {
        return  atelier;
    }




};



