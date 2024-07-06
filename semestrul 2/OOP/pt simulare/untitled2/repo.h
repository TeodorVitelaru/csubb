#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "domain.h"

using namespace std;

class Repo
{
private:
    vector<Procesor> listaProcesoare;
    string filename;
    void load_from_file();
    void write_to_file();
public:
    //Constructor
    Repo(string filename) : filename{filename}{
        cout<<"aici";
        load_from_file();
    };
    Repo(const Repo& ot) = delete;

    void store(const Procesor& procesor);

    void del(const Procesor& procesor);

    void modify(const Procesor& procesor);

    const vector<Procesor>& get_all() const;

    const Procesor& find(string nume);

    bool exists(const Procesor& procesor);

    ~Repo() = default;


};