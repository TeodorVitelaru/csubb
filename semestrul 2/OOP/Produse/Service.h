#include <unordered_map>
#include "Repo.h"
#include "Validare.h"
#pragma once

class Service : public Observable{
private:
    Repo& repo;
    Validare& valid;
public:
    Service(Repo& repo, Validare& valid) : repo{repo}, valid{valid} {}
    Service(const Service& ot) = delete;
    vector<Produs>& get_all() {
        return repo.get_all();
    }
    vector<Produs> sortare();
    void adauga_produs(int id, string nume, string tip, double pret)
    {
        valid.validateProdus(id, nume, tip, pret);
        Produs p{id, nume, tip, pret};
        repo.store(p);
        notify();
    }

    unordered_map<string,int> tipuri();

    int nr_prod(string tip);


};


