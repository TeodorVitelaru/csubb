#include "Tractor.h"
#include "Errors.h"
#pragma once

class Validator
{
    public:
    void validare(int id, string denumire, string tip, int nrRoti)
    {
        string errors;
        if (id < 0)
            errors.append("Id invalid\n");
        if (denumire.size() == 0)
            errors.append("Denumire invalida\n");
        if (tip.size() == 0)
            errors.append("Tip invalid\n");
        if (nrRoti <2 || nrRoti > 16 || nrRoti % 2 != 0)
            errors.append("Numar roti invalid\n");
        if (errors.size() > 0)
            throw Exception(errors);
    }
};