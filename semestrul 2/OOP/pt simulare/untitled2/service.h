#pragma once
#include <iostream>
#include "repo.h"
#include <vector>
using namespace std;

class Service {
private:
    Repo& repo;
public:
    Service(Repo& repo) : repo{ repo } {};
    Service(const Service& ot) = delete;
    void adaugare_procesor(string nume, int numarThreaduri, string socluProcesor, int pret);
    void stergere_procesor(string nume);
    const vector<Procesor>& get_all_proc()
    {
        return repo.get_all();
    }
    const Procesor& find(string nume)
    {
        return repo.find(nume);
    }
};



