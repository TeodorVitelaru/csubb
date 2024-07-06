#pragma once
#include <string>
#include "Errors.h"
using namespace std;


class Melodie {
private:
    int id;
    string titlu;
    string artist;
    int rank;
public:
    Melodie(int id, const string &titlu, const string &artist, int rank): id{id}, titlu{titlu}, artist{artist}, rank{rank}{};

    Melodie(const Melodie& ot)
    {
        id = ot.id;
        titlu = ot.titlu;
        artist = ot.artist;
        rank = ot.rank;
    }

    int getId() const
    {
        return id;
    }

    void setId(int id){
        this->id = id;
    }

    const string &getTitlu() const
    {
        return titlu;
    }

    void setTitlu(const string &titlu)
    {
        this->titlu = titlu;
    }

    const string &getArtist() const
    {
        return artist;
    }

    void setArtist(const string &artist)
    {
        this->artist = artist;
    }

    int getRank() const
    {
        return rank;
    }

    void setRank(int rank)
    {
        this->rank = rank;
    }
};


