#include <string>
#pragma once
using namespace std;

class Tractor {
private:
    int id;
    string denumire;
    string tip;
    int numarRoti;
public:
    Tractor(int id, string denumire, string tip, int numarRoti) : id{id}, denumire{denumire}, tip{tip}, numarRoti{numarRoti} {};
    Tractor(const Tractor& ot) = default;
    int get_id() const {
        return id;
    }
    string get_denumire() const {
        return denumire;
    }
    string get_tip() const {
        return tip;
    }
    int get_numarRoti() const {
        return numarRoti;
    }
    void set_numarRoti(int numarRoti) {
        this->numarRoti = numarRoti;
    }
    void set_tip(string tip) {
        this->tip = tip;
    }
    void set_denumire(string denumire) {
        this->denumire = denumire;
    }
    void set_id(int id) {
        this->id = id;
    }


};



