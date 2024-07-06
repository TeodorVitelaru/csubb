#include <iostream>
#include "service.h"
using namespace std;

void Service::adaugare_oferta(std::string denumire, std::string destinatie, std::string tip, int pret) {
    Oferta of{denumire, destinatie, tip, pret};
    val.validateOferta(destinatie, destinatie, tip, pret);
    repo.store(of);
}

void Service::modificare_oferta(const std::string &denumire, const std::string &destinatie, const std::string &tip,
                                int pret) {
    val.validateOferta(destinatie, destinatie, tip, pret);
    Oferta new_of{denumire, destinatie, tip, pret};
    repo.modify(new_of);
}

void Service::stergere_oferta(int poz) {
    repo.del(poz);
}

Oferta Service::cautare_oferte(const std::string &denumire, const std::string &destinatie) {
    return repo.find(denumire, destinatie);
}

void Service::sortare_generica(int (*fct)(const Oferta&, const Oferta &), int ord) {
    if(ord==1)
    {
        for(int i=0; i<repo.get_all_oferte().size()-1; i++)
            for(int j=i+1; j< repo.get_all_oferte().size(); j++)
                if(fct(repo.get_all_oferte()[i], repo.get_all_oferte()[j]) == 1)
                {
                    auto aux = repo.allOferte[i];
                    repo.allOferte[i] = repo.allOferte[j];
                    repo.allOferte[j] = aux;
                }
    }
    else{
        for(int i=0; i<repo.get_all_oferte().size()-1; i++)
            for(int j=i+1; j< repo.get_all_oferte().size(); j++)
                if(fct(repo.get_all_oferte()[i], repo.get_all_oferte()[j]) == 0)
                {
                    auto aux = repo.allOferte[i];
                    repo.allOferte[i] = repo.allOferte[j];
                    repo.allOferte[j] = aux;
                }
    }
}

vector<Oferta> Service::filtrare_destinatie(const std::string &destinatie) {
    vector<Oferta> new_vec;
    const vector<Oferta>& v = get_all_oferte();
    for(int i=0; i<v.size(); i++)
        if(v[i].get_destinatie() == destinatie)
            new_vec.push_back(v[i]);
    return new_vec;
}

vector<Oferta> Service::filtrare_pret(const int &pret) {
    vector<Oferta> new_vec;
    const vector<Oferta>& v = get_all_oferte();
    for(int i=0; i<v.size(); i++)
        if(v[i].get_pret() <= pret)
            new_vec.push_back(v[i]);
    return new_vec;
}