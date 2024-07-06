#pragma once
#include "Errors.h"
#include "Repo.h"

class Service {
private:
    Repo& repo;
public:
    Service() = default;
    Service(Repo& repo) : repo{repo}{}; //constructor

    void stergere(const Apartament& ap);

    const vector<Apartament>& get_all()
    {
        return repo.get_all();
    }

    vector<Apartament> filtrare_suprafata(int min, int max);

    vector<Apartament> filtrare_pret(int min, int max);

};


