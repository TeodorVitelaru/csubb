#pragma once
#include "Repo.h"

class Service {
private:
    Repo& repo;
public:
    Service() = default;
    Service(Repo& repo) : repo{ repo } {};
    const vector<Elev>& getElevi() {
        return repo.getElevi();
    }
    void sortare_nume();

    const Elev& get_elev(string nume, string scoala)
    {
        return repo.get_elev(nume, scoala);
    }


};



