#pragma once

class Iterator;

typedef int TComparabil;
typedef TComparabil TElement;

typedef bool (*Relatie)(TElement, TElement);

#define NULL_TELEMENT -1

struct Nod {
    TElement element;
    int next;
};

class LO {
private:
	friend class Iterator;
    int cp=2;
    Nod* v = new Nod[cp];
    int sz=0;
    void resize()
    {
        Nod* aux = new Nod[2 * cp];
        for (int i = 0; i < sz; i++)
            aux[i] = v[i];
        delete[] v;
        v = aux;
        cp*=2;
    }
    Relatie relatie;
    int dimension;
    int start;
    int cautaPrimLiber();
public:
		// constructor
		LO (Relatie r);

		// returnare dimensiune
		int dim() const;

		// verifica daca LO e vida
		bool vida() const;

		// prima pozitie din LO
		Iterator prim() const;

		// returnare element de pe pozitia curenta
		//arunca exceptie daca poz nu e valid
		TElement element(Iterator poz) const;

		// adaugare element in LO a.i. sa se pastreze ordinea intre elemente
		void adauga(TElement e);

		// sterge element de pe o pozitie poz si returneaza elementul sters
		//dupa stergere poz e pozitionat pe elementul de dupa cel sters
		//arunca exceptie daca poz nu e valid
		TElement sterge(Iterator& poz);

		// cauta element si returneaza prima pozitie pe care apare (sau iterator invalid)
		Iterator cauta(TElement e) const;

    //destructor
		~LO();

};
