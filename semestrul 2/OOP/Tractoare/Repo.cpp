

#include "Repo.h"
#include <fstream>
#include "Errors.h"


void Repo::load_from_file() {
    ifstream f(this->filename);
    if (!f.is_open()) {
        throw Exception("Eroare la deschiderea fisierului");
    }
    while (!f.eof())
    {
        int id;
        string denumire;
        string tip;
        int nrRoti;
        if(f.eof()) break;
        f >> id;
        if (f.eof()) break;
        f >> denumire;
        if (f.eof()) break;
        f >> tip;
        if (f.eof()) break;
        f >> nrRoti;
        Tractor t{id, denumire, tip, nrRoti};
        this->tractoare.push_back(t);
    }
}

void Repo::write_to_file() {
    ofstream f(this->filename);
    if (!f.is_open()) {
        throw Exception("Eroare la deschiderea fisierului");
    }
    for (const auto& t : this->tractoare) {
        f << t.get_id() << endl << t.get_denumire() << endl << t.get_tip() << endl << t.get_numarRoti() << endl;
    }
}

bool Repo::exists(int id) {
    for (const auto& t : this->tractoare) {
        if (t.get_id() == id) {
            return true;
        }
    }
    return false;
}

void Repo::store(const Tractor& tractor) {
    if (exists(tractor.get_id())) {
        throw Exception("Tractorul exista deja cu acest id!");
    }
    this->tractoare.push_back(tractor);
    write_to_file();
}