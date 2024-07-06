#include "Produs.h"
#pragma once
#include "Errors.h"

class Validare
{
public:
    void validateProdus(int id, string nume, string tip, double pret)
    {
        string errors;

        if (id < 0) errors.append("Id-ul este invalid!\n");
        if (nume.size() == 0) errors.append("Numele este invalid!\n");
        if (tip.size() == 0) errors.append("Tipul este invalid!\n");
        if (pret < 1.00 || pret > 100.00) errors.append("Pretul este invalid!\n");
        if (errors.size() != 0) throw Exception(errors);

    }
};