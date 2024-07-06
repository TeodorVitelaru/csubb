
#include "Service.h"

vector<Melodie> Service::sortare() {
    vector<Melodie> melodii = repo.get_all();
    for (int i = 0; i < melodii.size() - 1; i++) {
        for (int j = i + 1; j < melodii.size(); j++) {
            if (melodii[i].getRank() < melodii[j].getRank()) {
                Melodie aux = melodii[i];
                melodii[i] = melodii[j];
                melodii[j] = aux;
            }
        }
    }
    return melodii;
}