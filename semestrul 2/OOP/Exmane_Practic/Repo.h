#include "Parcare.h"
#include <vector>
#pragma once
class Repo {
private:
    vector<Parcare> parcari;
    string filename;

public:
    Repo(string filename) : filename(filename) {
        load_from_file();
    }
    Repo(const Repo& ot) = delete;
    void load_from_file();
    void write_to_file();

    /*
     * Functie care adauga o parcare in lista de parcari
     * @param p - Parcare
     * @return - -
     */
    void store(Parcare& p);

    /*
     * Functie care returneaza toate parcariile
     * @return vector<Parcare> - vector de parcari
     */
    vector<Parcare>& get_all() { return parcari; }

    void modify(Parcare& p);

    void seteaza(Parcare& p)
    {

    }


};



