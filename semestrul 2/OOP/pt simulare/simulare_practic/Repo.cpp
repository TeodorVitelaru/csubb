#include "Repo.h"
#include <fstream>
#include "Errors.h"

void Repo::loadFromFile() {
    ifstream in(this->filename);
    if (!in.is_open()) {
        throw Exception("Fisierul nu a putut fi deschis");
    }
    while (!in.eof()) {
        int nrMatricol;
        string nume;
        string scoala;
        string atelier;
        if (in.eof()) break;
        in >> nrMatricol;
        if (in.eof()) break;
        in >> nume;
        if (in.eof()) break;
        in >> scoala;
        if (in.eof()) break;
        in >> atelier;
        Elev el{nrMatricol, nume, scoala};
        el.set_atelier(atelier);
        cout<<el.get_atelier();
        elevi.push_back(el);
        //Repo::store(el);
    }
    in.close();
}

void Repo::store(Elev& el) {
    for(auto& elev : elevi)
        if(elev.get_nrMatricol() == el.get_nrMatricol())
            throw Exception("Apartamentul exista deja!");
    el.set_atelier(el.get_atelier());
    elevi.push_back(el);
    writeToFile();
}

void Repo::writeToFile() {
    ofstream out(this->filename);
    if (!out.is_open()) {
        throw Exception("Fisierul nu a putut fi deschis");
    }
    for (auto& el : elevi) {
        out << el.get_nrMatricol() << endl;
        out << el.get_nume() << endl;
        out << el.get_scoala() << endl;
        out << el.get_atelier() << endl;
    }
    out.close();
}

const Elev& Repo::get_elev(string nume, string scoala) {
    for (auto& el : elevi) {
        if (el.get_scoala() == scoala && el.get_nume() == nume){
            return el;
        }
    }
    throw Exception("Elevul nu exista!");
}

void Repo::del(Elev& el) {
    int i = 0;
    while (i < elevi.size()) {
        if (elevi.at(i).get_nrMatricol() == el.get_nrMatricol()) {
            elevi.erase(elevi.begin() + i);
            break;
        }
        i++;
    }
    writeToFile();
}
