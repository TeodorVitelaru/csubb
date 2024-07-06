#include "Repo.h"
#include "Validator.h"
#pragma once

class Service {
private:
    Repo& repo;
    Validator& val;
public:
    Service(Repo& repo, Validator& val) : repo{repo}, val{val} {};
    Service(const Service& ot) = delete;
    vector<Tractor>& get_all() {
        return repo.get_all();
    }
    vector<Tractor> sortare();
    void adaugare(int id, string denumire, string tip, int nrRoti);
    vector<string> tipuri();

    vector<Tractor> filtrare_tip(string tip);

};



