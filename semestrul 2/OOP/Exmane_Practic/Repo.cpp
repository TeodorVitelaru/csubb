
#include "Repo.h"
#include "Errors.h"
#include <fstream>
#include <iostream>

void Repo::load_from_file() {
        ifstream f(filename);
        if(!f.is_open())
            throw Exception("Fisierul nu exista!");

        int id;
        int linii;
        int coloane;
        string stare;
        string adresa;

        while(f >> id >> adresa>> linii >> coloane>> stare) {
            Parcare p{id, adresa, linii, coloane, stare};
            this->parcari.push_back(p);
        }
}

void Repo::write_to_file() {
    ofstream f(filename);
    if(!f.is_open())
        throw Exception("Fisierul nu exista!");
    for(auto& p : parcari) {
        f<< p.get_id()<< endl<< p.getAdresa()<<endl<< p.getLinii() << endl << p.getColoane() << endl << p.getStare() << endl;

    }
}

void Repo::store(Parcare &p) {
    parcari.push_back(p);
    write_to_file();
}

void Repo::modify(Parcare &p) {
    for(auto& parcare : parcari) {
        if(parcare.get_id() == p.get_id()) {
            parcare.set_stare(p.getStare());
            parcare.set_adresa(p.getAdresa());
            parcare.set_linii(p.getLinii());
            parcare.set_coloane(p.getColoane());
            write_to_file();
            return;
        }
    }
    throw Exception("Parcarea nu exista!");
}
