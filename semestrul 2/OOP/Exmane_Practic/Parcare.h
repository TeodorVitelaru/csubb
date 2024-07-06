#pragma once
#include <string>
#include <iostream>
using namespace std;

class Parcare {
private:
    int id;
    string adresa;
    int linii;
    int coloane;
    string stare;
public:
    Parcare(int id, string adresa, int linii, int coloane, string stare): id(id), adresa(adresa), linii(linii), coloane(coloane), stare(stare) {};
    int getLinii() const { return linii; }
    int getColoane() const { return coloane; }
    string getStare() const { return stare; }
    int get_nr_locuri() const
    {
        return linii * coloane;
    }
    void set_stare(const string& stare1) {
        cout<<"setare stare"<<stare1<<"\n";
        this->stare = stare1;
        cout<<"setare stare"<<stare<<"\n";
    }
    void set_id(int id1) {
        this->id = id1;
    }
    int get_id() const {
        return id;
    }
    string getAdresa() const {
        return adresa;
    }
    void set_adresa(string adresa1) {
        this->adresa = adresa1;
    }

    void set_linii(int linii1) {
        this->linii = linii1;
    }

    void set_coloane(int coloane1) {
        this->coloane = coloane1;
    }



};


