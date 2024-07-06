#include "Tractor.h"
#include <vector>
#pragma once

class Repo {
private:
    vector<Tractor> tractoare;
    string filename;
public:
    Repo(const string& filename) : filename{filename} {
        load_from_file();
    }
    Repo(const Repo& ot) = delete;
    void load_from_file();
    void write_to_file();
    void store(const Tractor& tractor);
    bool exists(int id);
    void modify(Tractor& tractor, string tip);
    vector<Tractor>& get_all()
    {
        return this->tractoare;
    }

};


