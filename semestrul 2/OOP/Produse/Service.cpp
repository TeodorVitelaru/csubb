

#include <map>
#include "Service.h"

vector<Produs> Service::
sortare() {
    vector<Produs> produse = repo.get_all();
    for (int i = 0; i < produse.size() - 1; i++) {
        for (int j = i + 1; j < produse.size(); j++) {
            if (produse[i].getPret() < produse[j].getPret()) {
                Produs aux = produse[i];
                produse[i] = produse[j];
                produse[j] = aux;
            }
        }
    }
    return produse;
}

unordered_map<string, int> Service::tipuri() {
    vector<Produs> produse = repo.get_all();
    unordered_map<string, int> tipuri;
    for (const Produs &p : produse)
        tipuri[p.getTip()]++;
    return tipuri;
}

int Service::nr_prod(std::string tip) {
    vector<Produs> produse = repo.get_all();
    int nr = 0;
    for (const Produs &p : produse)
        if (p.getTip() == tip)
            nr++;
    return nr;
}
