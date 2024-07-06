#include "Service.h"
#include <algorithm>
#include "Repo.h"

void Service::sortare_nume() {
    vector<Elev> elevi = repo.getElevi();
    sort(elevi.begin(), elevi.end(), [](const Elev& e1, const Elev& e2) {
        return e1.get_nume() < e2.get_nume();
    });
    repo.set_elevi(elevi);
}
