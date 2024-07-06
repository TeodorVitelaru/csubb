
#include "Repo.h"

void Repo::load_from_file() {
    ifstream in(filename);
    if (!in.is_open())
        throw Exception("Eroare la deschiderea fisierului!!!");
    while(!in.eof())
    {
        int id;
        string titlu;
        string artist;
        int rank;
        if (in.eof()) break;
        in>>id;
        if (in.eof()) break;
        in>>titlu;
        if (in.eof()) break;
        in>>artist;
        if (in.eof()) break;
        in>>rank;
        Melodie of{id, titlu, artist, rank};
        Repo::store(of);
    }
}

void Repo::write_to_file() {
    ofstream out(filename);
    if (!out.is_open())
        throw Exception("Eroare la deschiderea fisierului!!!");
    for (const Melodie &of: this->get_all()) {
        out << of.getId() << endl;
        out << of.getTitlu() << endl;
        out << of.getArtist() << endl;
        out << of.getRank() << endl;
    }
}

void Repo::store(const Melodie &mel) {
    melodii.push_back(mel);
    write_to_file();
}

void Repo::del(const Melodie &mel) {
    int i = 0;
    while (i < melodii.size()) {
        if (melodii.at(i).getId() == mel.getId()) {
            melodii.erase(melodii.begin() + i);
            break;
        }
        i++;
    }
    write_to_file();
}

Melodie& Repo::find(int id) {
    for (Melodie& mel : melodii)
        if (mel.getId() == id)
            return mel;
    throw Exception("Nu exista melodia cu id-ul dat!");
}

void Repo::modify(int id, std::string titlu, int rank) {
    for(auto& m : melodii)
        if(m.getId() == id)
        {
            m.setTitlu(titlu);
            m.setRank(rank);
        }
    write_to_file();
}

int Repo::melodii_rank(int rank) {
    int cnt = 0;
    for(auto& m : melodii)
        if(m.getRank() == rank)
            cnt++;
    return cnt;
}

