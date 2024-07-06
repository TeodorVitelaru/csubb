#include <iostream>
#include "repo.h"
using namespace std;

bool Repo::exists(const Oferta &oferta) {
    try{
        find(oferta.get_denumire(), oferta.get_destinatie());
        return true;
    }
    catch (RepoException&)
    {
        return false;
    }
}

const Oferta& Repo::find(std::string denumire, std::string destinatie) {
    for(int i=0; i<allOferte.size(); i++)
    {
        if(allOferte[i].get_denumire() == denumire && allOferte[i].get_destinatie() == destinatie)
            return allOferte[i];
    }
    throw RepoException("Oferta cu denumirea "+denumire+" si destinatia "+destinatie+" nu exista in lista");
}

void Repo::store(const Oferta &oferta) {
    if(exists(oferta))
        throw RepoException("Oferta cu aceaste denumire si acest titlu exista deja!");
    this->allOferte.push_back(oferta);
}


void Repo::del(const int& poz) {
    for(int i=poz; i<allOferte.size()-1; i++)
        allOferte[i] = allOferte[i-1];
    allOferte.pop_back();
}

void Repo::modify(const Oferta &of) {
    for(int i=0; i<allOferte.size(); i++)
        if(allOferte[i].get_denumire() == of.get_denumire() && allOferte[i].get_destinatie() == of.get_destinatie())
        {
            allOferte[i].set_tip(of.get_tip());
            allOferte[i].set_pret(of.get_pret());
        }

}

const VectorulMeu<Oferta>& Repo::get_all_oferte() const {
    return allOferte;
}



