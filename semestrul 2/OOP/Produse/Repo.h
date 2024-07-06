#pragma once
#include <vector>
#include "Produs.h"
#include "observer.h"

class Repo {
private:
    vector<Produs> produse;
    string filename;
public:
    Repo(const string& filename) : filename{filename} {
        load_from_file();
    }
    Repo(const Repo& ot) = delete;
    void load_from_file();
    void write_to_file();
    void store(const Produs& prod);
    vector<Produs>& get_all()
    {
        return this->produse;
    }
    bool exists(int id);

};



