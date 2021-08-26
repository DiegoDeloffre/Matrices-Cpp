#include "CException.cpp"
#include <iostream>

template <typename T>
class CMatrice
{
private:
	int iMATnbColonnes;
	int iMATnbLignes;
	T **pTMATTableau;

public:
	//Constructeur par défaut
	CMatrice();

	//Constructeur de recopie d'une matrice
	CMatrice(CMatrice &MATm1);

	//Constructeur de la matrice
	//Construit une matrice a iMATnbColonnes colonnes et iMATnbLignes lignes
	//et laisse un tableau non rempli
	CMatrice(int inbColonnes, int inbLignes);

	//Constructeur de la matrice
	//Construit une matrice a iMATnbColonnes colonnes et iMATnbLignes lignes
	//et remplit la matrice avec les valeurs de mat
	CMatrice(int inbColonnes, int inbLignes, T** mat);

	//Destructeur de la matrice courante
	//Desalloue le tableau contenant les valeurs
	~CMatrice();

	//Renvoie le nombre de lignes de la matrice courante
	int MATgetNbLignes();

	//Renvoie le nombre de colonnes de la matrice courante
	int MATgetNbColonnes();

	//Affecte le nombre de lignes inbLignes à la matrice courante
	void MATsetNbLignes(int inbLignes);

	//Affecte le nombre de colonnes inbColonnes à la matrice courante
	void MATsetNbColonnes(int inbColonnes);

	//Renvoie une valeur a la ligne iLigne et a la colonne iColonne de la matrice
	T MATgetValue(int iLigne, int iColonne);

	//Affecte la valeur valeur a la ligne iLignes et a la colonne iColonnes de la matrice
	void MATsetValue(int iLigne, int iColonne, T Tvaleur);

	//Affiche une matrice
	void MATafficherMatrice();

	//Calcul de la transposee de la matrice MATm1
	//Renvoie une nouvelle matrice
	T** MATTransposee();

	//Surcharge de l'operateur + entre deux matrices
	//Additionne 2 matrices
	T** operator+(CMatrice const& MATm1);

	//Surcharge de l'operateur + entre une matrice et une constante
	//Additionne 2 matrices
	T** operator+(T Tobj);

	//Surcharge de l'operateur - entre deux matrices
	//Soustrait 2 matrices
	T** operator-(CMatrice const& MATm1);

	//Surcharge de l'operateur + entre une matrice et une constante
	//Additionne 2 matrices
	T** operator-(T Tobj);

	//Surcharge de l'operateur * entre deux matrices
	//Multiplie 2 matrices
	T** operator*(CMatrice const& MATm1);

	//Surcharge de l'operateur * entre une matrice et un objet
	//Multiplie une matrice et un objet
	T** operator*(T obj);

	//Surcharge de l'operateur / entre une matrice et un objet
	//Divise une matrice par un objet
	T** operator/(T obj);

	//Surcharge de l'operateur d'affectation =
	//Permet d'affecter un pointeur de tableau a une matrice
	void operator=(T** tab);

	//Surcharge de l'operateur d'affectation =
	//Permet d'affecter une matrice a une autre
	void operator=(CMatrice<T> MATm1);

};