#include "Melodie.h"
#include "Errors.h"
#include <fstream>
#include <iostream>
#include <vector>


class Repo {
private:
    string filename;
    vector<Melodie> melodii;
    public:
    Repo(const string& filename) : filename{filename} {
        load_from_file();
    }
    Repo(const Repo& ot) = delete;
    void load_from_file();
    void write_to_file();
    void store(const Melodie& mel);
    void del(const Melodie& mel);
    void modify(int id, string titlu, int rank);
    Melodie& find(int id);
    vector<Melodie>& get_all()
    {
        return this->melodii;
    }
    int melodii_rank(int rank);

};

