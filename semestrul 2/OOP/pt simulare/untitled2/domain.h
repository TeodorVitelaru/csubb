#pragma once
#include <string>
using namespace std;

class Procesor {
private:
    string nume;
    int numarThreaduri;
    string socluProcesor;
    int pret;
public:
    Procesor() = default;
    Procesor(string nume, int numarThreaduri, string socluProcesor, int pret) : nume{nume}, numarThreaduri{numarThreaduri}, socluProcesor{socluProcesor}, pret{pret} {};
    Procesor(const Procesor& ot)
    {
        nume = ot.nume;
        numarThreaduri = ot.numarThreaduri;
        socluProcesor = ot.socluProcesor;
        pret = ot.pret;
    }

    //Getters
    string get_nume() const;
    int get_numarThreaduri() const;
    string get_socluProcesor() const;
    int get_pret() const;

    //Setters
    void set_nume(string _nume);
    void set_numarThreaduri(int _numarThreaduri);
    void set_socluProcesor(string _socluProcesor);
    void set_pret(int _pret);




};


