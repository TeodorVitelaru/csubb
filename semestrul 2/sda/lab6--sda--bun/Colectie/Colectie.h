#pragma once
#include <utility>

#define NULL_TELEM std::make_pair(-100000,0)
#define MAX 30000
typedef int TElem;
typedef std::pair<TElem , int>TElement;

class IteratorColectie;

class Colectie
{
	friend class IteratorColectie;

private:
	/* aici e reprezentarea */
    int m; //numarul de locatii din tabela de dispersie
    int urm[MAX]; //vectorul legaturilor
    TElement e[MAX]; //vectorul elementelor - vector static
    int primLiber; // locatia primei pozitii libere din tabela
    void actPrimLiber();
    int d(TElem e) const;

public:
		//constructorul implicit
		Colectie();

		//adauga un element in colectie
		void adauga(TElem e);

		//sterge o aparitie a unui element din colectie
		//returneaza adevarat daca s-a putut sterge
		bool sterge(TElem e);

		//verifica daca un element se afla in colectie
		bool cauta(TElem elem) const;

		//returneaza numar de aparitii ale unui element in colectie
		int nrAparitii(TElem elem) const;


		//intoarce numarul de elemente din colectie;
		int dim() const;

		//verifica daca colectia e vida;
		bool vida() const;

		//returneaza un iterator pe colectie
		IteratorColectie iterator() const;

		// destructorul colectiei
		~Colectie();

        int StergeToateElementeleRepetitive();

};

