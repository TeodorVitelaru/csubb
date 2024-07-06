

#include <algorithm>
#include "Service.h"

void Service::adaugare(int id, string adresa, int linii, int col, string stare) {
    Parcare p{id, adresa, linii, col, stare};
    repo.store(p);
    notify();
}

vector<Parcare> Service::sortare() {
    vector<Parcare> all = repo.get_all();
    sort(all.begin(), all.end(), []( Parcare& p1,  Parcare& p2) {
        return p1.get_nr_locuri() < p2.get_nr_locuri();
    });
    return all;
}

void Service::modificare(int id, std::string adresa, int linii, int coloane, std::string stare) {
    val.validare(id, adresa, linii, coloane, stare);
    Parcare p{id, adresa, linii, coloane, stare};
    repo.modify(p);
    notify();
}

string Service::aleator(int linii, int col) {
    string stare;
    int total_length = linii * col;
    for (int i = 0; i < total_length; i++) {
        int nr = rand() % 2;
        if (nr == 0)
            stare += "X";
        else
            stare += "-";
    }
    return stare;
}
