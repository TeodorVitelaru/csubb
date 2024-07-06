#include "Parcare.h"
#include "Errors.h"
#pragma once

class Validator
{
public:
    void validare(int id, string adresa, int linii, int coloane, string stare)
    {
        string err;
        if (id <= 0)
            err.append("Id invalid!\n");
        if (adresa.size() == 0)
            err.append("Adresa invalida!\n");
        if (linii < 1 || linii > 5)
            err.append("Linii invalid!\n");
        if (coloane < 1 || coloane > 5)
            err.append("Coloane invalid!\n");
        if (stare.size() != linii* coloane)
            err.append("Stare invalida!\n");
        for(int i=0; i<stare.size(); i++)
            if(stare[i]!='X' && stare[i]!='-')
                err.append("Stare invalida!\n");
        if (err.size() > 0)
            throw Exception(err);
    }


};
