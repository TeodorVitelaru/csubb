
#include "Service.h"

vector<Tractor> Service::sortare() {
    vector<Tractor> tractoare = repo.get_all();
    for (int i = 0; i < tractoare.size() - 1; i++) {
        for (int j = i + 1; j < tractoare.size(); j++) {
            if (tractoare[i].get_denumire() < tractoare[j].get_denumire()) {
                Tractor aux = tractoare[i];
                tractoare[i] = tractoare[j];
                tractoare[j] = aux;
            }
        }
    }
    return tractoare;
}

void Service::adaugare(int id, string denumire, string tip, int nrRoti) {
    Tractor tractor{ id, denumire, tip, nrRoti };
    val.validare(id, denumire, tip, nrRoti);
    repo.store(tractor);
}

vector<string> Service::tipuri() {
    vector<Tractor> tractoare = repo.get_all();
    vector<string> tipuri;
    for (const Tractor& t : tractoare) {
        bool ok = true;
        for (const string& tip : tipuri)
            if (tip == t.get_tip())
                ok = false;
        if (ok)
            tipuri.push_back(t.get_tip());
    }
    return tipuri;
}

vector<Tractor> Service::filtrare_tip(string tip) {
    vector<Tractor> tractoare = repo.get_all();
    vector<Tractor> rez;
    for (const Tractor& t : tractoare)
        if (t.get_tip() == tip)
        {
            rez.push_back(t);
        }
    return rez;
}
