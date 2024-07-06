#pragma once

#include <iostream>
#include "Repo.h"


class Service {
private:
    Repo& repo;
public:
    Service(Repo& repo) : repo{repo} {};
    Service(const Service& ot) = delete;
    void sterge_melodie(int id)
    {
        repo.del(repo.find(id));
    }
    vector<Melodie>& get_all() const
    {
        return repo.get_all();
    }
    vector<Melodie> sortare();

    void modifica_melodie(int id, string titlu, int rank)
    {
        repo.modify(id, titlu, rank);
    }

    bool ultima_melodie(int id)
    {
        Melodie& mel = repo.find(id);
        string artist = mel.getArtist();
        vector<Melodie>& all = repo.get_all();
        int cnt=0;
        for(auto& m : all)
            if(m.getArtist() == artist)
                cnt++;
        if(cnt == 1)
            return true;
        return false;
    }

    const vector<Melodie>& sortare() const
    {
        vector<Melodie>& all = repo.get_all();
        for(int i=0; i<all.size()-1; i++)
            for(int j=i+1; j<all.size(); j++)
                if(all[i].getRank() < all[j].getRank())
                    swap(all[i], all[j]);
        return all;
    }

    vector<int> rank_fr() {
        int rank = 0;
        vector<int> fr;
        for (int i = 0; i < 10; ++i) {
            int nr = 0;
            for (auto &m: get_all())
                if (m.getRank() == rank)
                    nr++;
            fr.push_back(nr);
            rank++;
        }
        return fr;
    }

};


