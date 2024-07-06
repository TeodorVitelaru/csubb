#pragma once

typedef int TElem;


#define NULL_TELEMENT 0

struct Triplet
{
    int lin;
    int col;
    TElem val;
};

class Iterator;

class Matrice {

private:
	/* aici e reprezentarea */
    //nr linii
    int nr_lin;
    //nr coloane
    int nr_col;

    int cap; //capacitatea
    int dim; //dimensiunea
    Triplet* v;

    void redim();



public:

    friend class Iterator;

	//constructor
	//se arunca exceptie daca nrLinii<=0 sau nrColoane<=0
	Matrice(int nrLinii, int nrColoane);


	//destructor
	~Matrice(){
        delete[] v;
    };

	//returnare element de pe o linie si o coloana
	//se arunca exceptie daca (i,j) nu e pozitie valida in Matrice
	//indicii se considera incepand de la 0
	TElem element(int i, int j) const;


	// returnare numar linii
	int nrLinii() const;

	// returnare numar coloane
	int nrColoane() const;


	// modificare element de pe o linie si o coloana si returnarea vechii valori
	// se arunca exceptie daca (i,j) nu e o pozitie valida in Matrice
	TElem modifica(int i, int j, TElem);

    Iterator iterator();

};

class Iterator {
private:
    //contine o referinta catre container
    const Matrice& m;

    int curent;

public:
    Iterator(const Matrice&);
    void prim();
    void urmator();
    TElem element() const;
    bool valid() const;
};







