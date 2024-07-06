#include "Service.h"

void Service::adaugare_procesor(std::string nume, int numarThreaduri, std::string socluProcesor, int pret) {
    Procesor procesor{nume, numarThreaduri, socluProcesor, pret};
    repo.store(procesor);
}
