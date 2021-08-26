#include <iostream>
#include "Matrice.h"

template <typename T>
//Constructeur par défaut
CMatrice<T>::CMatrice() {

}

template <typename T>
//Constructeur de recopie d'une matrice
CMatrice<T>::CMatrice(CMatrice &MATm1) {
	// on recupere et on affecte le nombre de lignes et de colonnes
	this->iMATnbColonnes = MATm1.MATgetNbColonnes();
	this->iMATnbLignes = MATm1.MATgetNbLignes();

	// on alloue la memoire pour les lignes du nouveau tableau
	this->pTMATTableau = (T**)malloc(sizeof(T*) * this->iMATnbLignes);

	// on remplit le tableau de la nouvelle matrice
	// avec les valeurs de l'ancien tableau de l'ancienne matrice
	for (int iCompteurLignes = 0; iCompteurLignes < this->iMATnbLignes; iCompteurLignes++) {
		// on alloue la memoire pour les colonnes du nouveau tableau
		this->pTMATTableau[iCompteurLignes] = new T[this->iMATnbColonnes];
		for (int iCompteurColonnes = 0; iCompteurColonnes < iMATnbColonnes; iCompteurColonnes++) {
			this->pTMATTableau[iCompteurLignes][iCompteurColonnes] = MATm1.pTMATTableau[iCompteurLignes][iCompteurColonnes];
		}
	}
}

template <typename T>
//Constructeur de la matrice
//Construit une matrice a iMATnbColonnes colonnes et iMATnbLignes lignes
CMatrice<T>::CMatrice(int inbColonnes, int inbLignes) {
	// on affecte le nombre de lignes et de colonnes
	this->iMATnbColonnes = inbColonnes;
	this->iMATnbLignes = inbLignes;

	// on alloue la memoire pour les lignes du tableau
	pTMATTableau = (T**)malloc(sizeof(T*) * this->iMATnbLignes);
	for (int iCompteurLignes = 0; iCompteurLignes < this->iMATnbLignes; iCompteurLignes++) {
		// on alloue la memoire pour les colonnes du tableau
		pTMATTableau[iCompteurLignes] = new T[this->iMATnbColonnes];
	}
}

template <typename T>
CMatrice<T>::CMatrice(int inbColonnes, int inbLignes, T** mat) {
	// on affecte le nombre de lignes et de colonnes
	this->iMATnbColonnes = inbColonnes;
	this->iMATnbLignes = inbLignes;

	// on alloue la memoire pour les lignes du tableau
	pTMATTableau = (T**)malloc(sizeof(T*) * this->iMATnbLignes);
	for (int iCompteurLignes = 0; iCompteurLignes < this->iMATnbLignes; iCompteurLignes++) {
		// on alloue la memoire pour les colonnes du tableau
		pTMATTableau[iCompteurLignes] = new T[this->iMATnbColonnes];
		for (int iCompteurColonnes = 0; iCompteurColonnes < this->iMATnbColonnes; iCompteurColonnes++) {
			// on affecte les valeurs du tableau en parametres au tableau de la matrice
			this->MATsetValue(iCompteurLignes, iCompteurColonnes, mat[iCompteurLignes][iCompteurColonnes]);
		}
	}
}

template <typename T>
//Destructeur de la matrice courante
//Desalloue le tableau contenant les valeurs
CMatrice<T>::~CMatrice() {

	for (int indexLigne = 0; indexLigne < this->iMATnbLignes; indexLigne++) {
		delete [] pTMATTableau[indexLigne];
	}
	free(pTMATTableau);
}

template <typename T>
//Renvoie le nombre de lignes de la matrice courante
int CMatrice<T>::MATgetNbLignes() {
	return this->iMATnbLignes;
}

template <typename T>
//Renvoie le nombre de colonnes de la matrice courante
int CMatrice<T>::MATgetNbColonnes() {
	return this->iMATnbColonnes;
}

template <typename T>
//Affecte le nombre de lignes inbLignes à la matrice courante
void CMatrice<T>::MATsetNbLignes(int inbLignes) {
	this->iMATnbLignes = inbLignes;
}

template <typename T>
//Affecte le nombre de colonnes inbColonnes à la matrice courante
void CMatrice<T>::MATsetNbColonnes(int inbColonnes) {
	this->iMATnbColonnes = inbColonnes;
}

template <typename T>
//Renvoie une valeur a la ligne iLigne et a la colonne iColonne de la matrice
T CMatrice<T>::MATgetValue(int iLigne, int iColonne) {
	return this->pTMATTableau[iLigne][iColonne];
}

template <typename T>
//Affecte la valeur valeur a la ligne iLignes et a la colonne iColonnes de la matrice
void CMatrice<T>::MATsetValue(int iLigne, int iColonne, T Tvaleur) {
	pTMATTableau[iLigne][iColonne] = Tvaleur;
}

template <typename T>
//Affiche une matrice
void CMatrice<T>::MATafficherMatrice() {
	std::cout << "[ ";
	for (int iCompteurLignes = 0; iCompteurLignes < this->iMATnbLignes; iCompteurLignes++) {
		for (int iCompteurColonnes = 0; iCompteurColonnes < this->iMATnbColonnes - 1; iCompteurColonnes++) {
			std::cout << MATgetValue(iCompteurLignes, iCompteurColonnes) << ", ";
		}
		std::cout << MATgetValue(iCompteurLignes, this->iMATnbColonnes - 1);

		// si on est a la derniere ligne (fin de la matrice)
		if (iCompteurLignes == this->iMATnbLignes - 1) {
			std::cout << "]";
		}
		std::cout << "\n";
		std::cout << "  ";
	}
	std::cout << "\n";
}

template <typename T>
//Calcul de la transposee de la matrice MATm1
//Renvoie une nouvelle matrice
T** CMatrice<T>::MATTransposee() {
	T** pTmatrice = (T**)malloc(sizeof(T*) * this->iMATnbLignes);
	for (int iCompteurLignes = 0; iCompteurLignes < this->iMATnbColonnes; iCompteurLignes++) {
		pTmatrice[iCompteurLignes] = new T[this->iMATnbColonnes];
		for (int iCompteurColonnes = 0; iCompteurColonnes < this->iMATnbLignes; iCompteurColonnes++) {
			pTmatrice[iCompteurLignes][iCompteurColonnes] = pTMATTableau[iCompteurColonnes][iCompteurLignes];
		}
	}
	return pTmatrice;
}

template <typename T>
//Surcharge de l'operateur + entre deux matrices
//Additionne 2 matrices
T** CMatrice<T>::operator+(CMatrice const& MATm1) {

	if ((MATm1.iMATnbLignes != this->iMATnbLignes) || (MATm1.iMATnbColonnes != this->iMATnbColonnes)) {
		throw CException(1, "Taille incompatible");
	}

	T** pTmatrice = (T**)malloc(sizeof(T*) * this->iMATnbLignes);
	for (int iCompteurLignes = 0; iCompteurLignes < MATm1.iMATnbLignes; iCompteurLignes++) {
		pTmatrice[iCompteurLignes] = new T[this->iMATnbColonnes];
		for (int iCompteurColonnes = 0; iCompteurColonnes < MATm1.iMATnbColonnes; iCompteurColonnes++) {
			pTmatrice[iCompteurLignes][iCompteurColonnes] = MATm1.pTMATTableau[iCompteurLignes][iCompteurColonnes] + this->pTMATTableau[iCompteurLignes][iCompteurColonnes];
		}
	}
	return pTmatrice;
}

//Surcharge de l'operateur + entre une matrice et une constante
//Additionne 2 matrices
template <typename T>
T** CMatrice<T>::operator+(T Tobj) {
	T** pTmatrice = (T**)malloc(sizeof(T*) * this->iMATnbLignes);
	for (int iCompteurLignes = 0; iCompteurLignes < this->iMATnbLignes; iCompteurLignes++) {
		pTmatrice[iCompteurLignes] = new T[this->iMATnbColonnes];
		for (int iCompteurColonnes = 0; iCompteurColonnes < this->iMATnbColonnes; iCompteurColonnes++) {
			pTmatrice[iCompteurLignes][iCompteurColonnes] = this->pTMATTableau[iCompteurLignes][iCompteurColonnes] + Tobj;
		}
	}
	return pTmatrice;
}

template <typename T>
//Surcharge de l'operateur - entre deux matrices
//Soustrait 2 matrices
T** CMatrice<T>::operator-(CMatrice const& MATm1) {

	if ((MATm1.iMATnbLignes != this->iMATnbLignes) || (MATm1.iMATnbColonnes != this->iMATnbColonnes)) {
		throw CException(1, "Taille incompatible");
	}

	T** pTmatrice = (T**)malloc(sizeof(T*) * this->iMATnbLignes);
	for (int iCompteurLignes = 0; iCompteurLignes < MATm1.iMATnbLignes; iCompteurLignes++) {
		pTmatrice[iCompteurLignes] = new T[this->iMATnbColonnes];
		for (int iCompteurColonnes = 0; iCompteurColonnes < MATm1.iMATnbColonnes; iCompteurColonnes++) {
			pTmatrice[iCompteurLignes][iCompteurColonnes] = this->pTMATTableau[iCompteurLignes][iCompteurColonnes] - MATm1.pTMATTableau[iCompteurLignes][iCompteurColonnes];
		}
	}
	return pTmatrice;
}

//Surcharge de l'operateur + entre une matrice et une constante
//Additionne 2 matrices
template <typename T>
T** CMatrice<T>::operator-(T Tobj) {
	T** pTmatrice = (T**)malloc(sizeof(T*) * this->iMATnbLignes);
	for (int iCompteurLignes = 0; iCompteurLignes < this->iMATnbLignes; iCompteurLignes++) {
		pTmatrice[iCompteurLignes] = new T[this->iMATnbColonnes];
		for (int iCompteurColonnes = 0; iCompteurColonnes < this->iMATnbColonnes; iCompteurColonnes++) {
			pTmatrice[iCompteurLignes][iCompteurColonnes] = this->pTMATTableau[iCompteurLignes][iCompteurColonnes] - Tobj;
		}
	}
	return pTmatrice;
}

template <typename T>
//Surcharge de l'operateur * entre deux matrices
//Multiplie 2 matrices
T** CMatrice<T>::operator*(CMatrice const& MATm1) {

	if (this->iMATnbColonnes != MATm1.iMATnbLignes) {
		throw CException(1, "Taille incompatible -> On ne peut pas multiplier ces deux matrices");
	}

	T** pTmatrice = (T**)malloc(sizeof(T*) * this->iMATnbLignes);
	for (int iCompteur = 0; iCompteur < this->iMATnbLignes; iCompteur++) {
		pTmatrice[iCompteur] = new T[this->iMATnbColonnes];
		for (int iCompteurLignes = 0; iCompteurLignes < this->iMATnbLignes; iCompteurLignes++) {
			pTmatrice[iCompteur][iCompteurLignes] = 0;
			for (int iCompteurColonnes = 0; iCompteurColonnes < this->iMATnbColonnes; iCompteurColonnes++) {
				pTmatrice[iCompteur][iCompteurLignes] += this->pTMATTableau[iCompteur][iCompteurColonnes] * MATm1.pTMATTableau[iCompteurColonnes][iCompteurLignes];
			}
		}
	}
	return pTmatrice;
}

template <typename T>
//Surcharge de l'operateur * entre une matrice et un objet
//Multiplie une matrice et un objet
T** CMatrice<T>::operator*(T obj) {
	T** pTmatrice = (T**)malloc(sizeof(T*) * this->iMATnbLignes);
	for (int iCompteurLignes = 0; iCompteurLignes < this->iMATnbLignes; iCompteurLignes++) {
		pTmatrice[iCompteurLignes] = new T[this->iMATnbColonnes];
		for (int iCompteurColonnes = 0; iCompteurColonnes < this->iMATnbColonnes; iCompteurColonnes++) {
			pTmatrice[iCompteurLignes][iCompteurColonnes] = this->pTMATTableau[iCompteurLignes][iCompteurColonnes] * obj;
		}
	}
	return pTmatrice;
}

template <typename T>
//Surcharge de l'operateur / entre une matrice et un objet
//Divise une matrice par un objet
T** CMatrice<T>::operator/(T obj) {

	if (obj == 0) {
		throw CException(2, "Tentative de division par 0");
	}

	T** pTmatrice = (T**)malloc(sizeof(T*) * this->iMATnbLignes);
	for (int iCompteurLignes = 0; iCompteurLignes < this->iMATnbLignes; iCompteurLignes++) {
		pTmatrice[iCompteurLignes] = new T[this->iMATnbColonnes];
		for (int iCompteurColonnes = 0; iCompteurColonnes < this->iMATnbColonnes; iCompteurColonnes++) {
			pTmatrice[iCompteurLignes][iCompteurColonnes] = this->pTMATTableau[iCompteurLignes][iCompteurColonnes] / obj;
		}
	}
	return pTmatrice;
}


template <typename T>
//Surcharge de l'operateur d'affectation =
//Permet d'affecter un pointeur de tableau à une matrice
void CMatrice<T>::operator=(T** tab) {
	// on alloue la memoire pour les lignes du tableau
	pTMATTableau = (T**)malloc(sizeof(T*) * this->iMATnbLignes);
	for (int iCompteurLignes = 0; iCompteurLignes < this->iMATnbLignes; iCompteurLignes++) {
		// on alloue la memoire pour les colonnes du tableau
		this->pTMATTableau[iCompteurLignes] = new T[this->iMATnbColonnes];
		for (int iCompteurColonnes = 0; iCompteurColonnes < this->iMATnbColonnes; iCompteurColonnes++) {
			// on affecte les valeurs du tableau en parametres au tableau de la matrice
			MATsetValue(iCompteurLignes, iCompteurColonnes, tab[iCompteurLignes][iCompteurColonnes]);
		}
	}
}


template <typename T>
//Surcharge de l'operateur d'affectation =
//Permet d'affecter une matrice a une autre
void CMatrice<T>::operator=(CMatrice<T> MATm1) {
	// on recupere et on affecte le nombre de lignes et de colonnes
	this->iMATnbColonnes = MATm1.MATgetNbColonnes();
	this->iMATnbLignes = MATm1.MATgetNbLignes();

	// on alloue la memoire pour les lignes du nouveau tableau
	this->pTMATTableau = (T**)malloc(sizeof(T*) * this->iMATnbLignes);

	// on remplit le tableau de la nouvelle matrice
	// avec les valeurs du tableau de l'ancienne matrice
	for (int iCompteurLignes = 0; iCompteurLignes < this->iMATnbLignes; iCompteurLignes++) {
		// on alloue la memoire pour les colonnes du nouveau tableau
		this->pTMATTableau[iCompteurLignes] = new T[this->iMATnbColonnes];
		for (int iCompteurColonnes = 0; iCompteurColonnes < iMATnbColonnes; iCompteurColonnes++) {
			this->pTMATTableau[iCompteurLignes][iCompteurColonnes] = MATm1.pTMATTableau[iCompteurLignes][iCompteurColonnes];
		}
	}
}
