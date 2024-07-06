#include "repo.h"
#include <iostream>
#include <fstream>
#include <string>
#include "errors.h"


using namespace std;

void Repo::load_from_file() {
    ifstream in(filename);
    if (!in.is_open()) {
        throw Exception("Fisierul nu a putut fi deschis!");
    }
    while (!in.eof())
    {
        string nume;
        int pret;
        string socluProcesor;
        int numarThreaduri;
        if(in.eof()) break;
        in >> nume;
        if(in.eof()) break;
        in >> numarThreaduri;
        if(in.eof()) break;
        in >> socluProcesor;
        if(in.eof()) break;
        in >> pret;
        Procesor procesor{nume, numarThreaduri, socluProcesor, pret};
        Repo::store(procesor);
    }
}

void Repo::write_to_file() {
    ofstream out(filename);
    if(!out.is_open())
    {
        throw Exception("Fisierul nu a putut fi deschis!");
    }
    for(const Procesor& procesor : listaProcesoare)
    {
        out<<procesor.get_nume()<<endl;
        out<<procesor.get_numarThreaduri()<<endl;
        out<<procesor.get_socluProcesor()<<endl;
        out<<procesor.get_pret()<<endl;
    }
}

void Repo::store(const Procesor &procesor) {
    if(exists(procesor))
        throw Exception("Procesorul cu acest nume exista deja!");
    this->listaProcesoare.push_back(procesor);
    write_to_file();
}

bool Repo::exists(const Procesor &procesor) {
    for(const Procesor& proc : this->listaProcesoare)
    {
        if(proc.get_nume() == procesor.get_nume())
            return true;
    }
    return false;
}

const Procesor& Repo::find(std::string nume) {
    for(const Procesor& proc : this->listaProcesoare)
    {
        if(proc.get_nume() == nume)
            return proc;
    }
    throw Exception("Procesorul cu numele "+nume+" nu exista in lista!");
}

const vector<Procesor>& Repo::get_all() const {
    return this->listaProcesoare;
}

void Repo::del(const Procesor &procesor) {
    int i =0;
    while(i< this->listaProcesoare.size())
    {
        if(listaProcesoare[i].get_nume() == procesor.get_nume())
        {
            this->listaProcesoare.erase(this->listaProcesoare.begin()+i);
            break;
        }
        i++;
    }
    write_to_file();
}

void Repo::modify(const Procesor &procesor) {
    for(int i=0; i<listaProcesoare.size(); i++)
    {
        if(listaProcesoare[i].get_nume() == procesor.get_nume())
        {
            listaProcesoare[i].set_numarThreaduri(procesor.get_numarThreaduri());
            listaProcesoare[i].set_socluProcesor(procesor.get_socluProcesor());
            listaProcesoare[i].set_pret(procesor.get_pret());
        }
    }
    write_to_file();
}
