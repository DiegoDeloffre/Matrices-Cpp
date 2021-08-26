
#include "Matrice.cpp"
#include "CFichier.cpp"


int main(int argc, char** argv)
{
	//si le programme est execute sans arguments
	//on lance un petit programme de demonstration
	if (argc == 1) {
		std::cout << "PROGRAMME DE DEMONSTRATION" << endl;

		CMatrice<double> mat(2, 2);
		mat.MATsetValue(0, 0, 1.4);
		mat.MATsetValue(0, 1, 2.4);
		mat.MATsetValue(1, 0, 3.4);
		mat.MATsetValue(1, 1, 4.4);
		std::cout << "Matrice 1 : " << endl;
		mat.MATafficherMatrice();

		CMatrice<double> mat2(2, 2);
		mat2.MATsetValue(0, 0, 4.4);
		mat2.MATsetValue(0, 1, 3.4);
		mat2.MATsetValue(1, 0, 2.4);
		mat2.MATsetValue(1, 1, 1.4);
		std::cout << "Matrice 2 : " << endl;
		mat.MATafficherMatrice();


		CMatrice<double> matSomme(2, 2);
		matSomme = mat + mat2;
		std::cout << "Matrice 1 + Matrice 2 = " << endl;
		matSomme.MATafficherMatrice();

		CMatrice<double> matProduit(2, 2);
		matProduit = mat * mat2;
		std::cout << "Matrice 1 * Matrice 2 = " << endl;
		matProduit.MATafficherMatrice();

		CMatrice<double> matDiff(2, 2);
		matDiff = mat - mat2;
		std::cout << "Matrice 1 - Matrice 2 = " << endl;
		matDiff.MATafficherMatrice();


		CMatrice<double> matTransposee(2, 2);
		matTransposee = mat.MATTransposee();
		std::cout << "Transposee Matrice 1 = " << endl;
		matTransposee.MATafficherMatrice();

		CMatrice<double> matSommeConst(2, 2);
		matSommeConst = mat + 2.0;
		std::cout << "Matrice 1 + 2.5 = " << endl;
		matSommeConst.MATafficherMatrice();

		CMatrice<double> matProduitConst(2, 2);
		matProduitConst = mat * 2.0;
		std::cout << "Matrice 1 * 2.5 = " << endl;
		matProduitConst.MATafficherMatrice();

		CMatrice<double> matDiffConst(2, 2);
		matDiffConst = mat - 2.0;
		std::cout << "Matrice 1 - 2.5 = " << endl;
		matDiffConst.MATafficherMatrice();

		CMatrice<double> matDivisionConst(2, 2);
		matDivisionConst = mat / 2.0;
		std::cout << "Matrice 1 / 2.5 = " << endl;
		matDivisionConst.MATafficherMatrice();
	}
	else {
		const char* ctypeMatrice = "double";
		const int inbFichiers = argc - 1;
		
		//on cree un tableau ayant autant de cases qu'il y a de fichiers passés en arguments
		//pour stocker les matrices de chaque fichier
		CMatrice<double>* ptabMatrices = (CMatrice<double>*)malloc(sizeof(CMatrice<double>)*inbFichiers);

		//on parcourt tous les fichiers
		for (int iCompteur = 0; iCompteur < inbFichiers; iCompteur++) {
			//on initialise le fichier
			CFichier FICfichier = CFichier(argv[iCompteur+1]); 

			//on verifie le type de la matrice
			if (FICfichier.getTypeMatrice() != ctypeMatrice) {
				//on recopie le tableau du fichier dans un tableau de double que l'on cree
				double ** pTableau = (double**)malloc(sizeof(double*) * FICfichier.getNBLignes());
				for (int iCompteurLignes = 0; iCompteurLignes < FICfichier.getNBLignes(); iCompteurLignes++) {
					// on alloue la memoire pour les colonnes du tableau
					pTableau[iCompteurLignes] = new double[FICfichier.getNBColonnes()];
					for (int iCompteurColonnes = 0; iCompteurColonnes < FICfichier.getNBColonnes(); iCompteurColonnes++) {
						// on affecte les valeurs du tableau en parametres au tableau de la matrice
						pTableau[iCompteurLignes][iCompteurColonnes] = atof(FICfichier.getMatrice()[iCompteurLignes][iCompteurColonnes]);
					}
				}
				//on cree une matrice temporaire avec le tableau rempli
				CMatrice<double> tmp(FICfichier.getNBColonnes(), FICfichier.getNBLignes(), pTableau);
				//on copie la matrice dans le tableau
				ptabMatrices[iCompteur] = tmp;
			}
			else {
				// si le type du fichier n'est pas double on leve une exception
				throw CException(4, "Mauvais type. Seuls les double sont acceptés");
			}
		}

		//on demande la saisie d'une valeur c
		double c;
		cout << "Saisir une valeur : ";
		cin >> c;
		
		//on parcourt toutes les matrices du tableau
		for (int i = 0; i < inbFichiers; i++) {
			//on cree deux matrices d'arrivees pour la somme et le produit
			CMatrice<double> tabMatProduit(ptabMatrices[i].MATgetNbColonnes(), ptabMatrices[i].MATgetNbLignes());
			CMatrice<double> tabMatDiv(ptabMatrices[i].MATgetNbColonnes(), ptabMatrices[i].MATgetNbLignes());
			
			//on calcule et on affiche les resultats
			try
			{
				std::cout << "Matrice " << i + 1 << " * " << c << " = " << endl;
				tabMatProduit = ptabMatrices[i] * c;
				tabMatProduit.MATafficherMatrice();
			}
			catch (std::exception const& e)
			{
				cerr << "ERREUR : " << e.what() << endl;
			}
			
			try
			{
				std::cout << "Matrice " << i + 1 << " / " << c << " = " << endl;
				tabMatDiv = ptabMatrices[i] / c;
				tabMatDiv.MATafficherMatrice();
			}
			catch (std::exception const& e)
			{
				cerr << "ERREUR : " << e.what() << endl;
			}
			
		}
		
		//SOMME DE TOUTES LES MATRICES
		//on cree la matrice d'arrivee pour la somme globale
		CMatrice<double> matSommeGlobale(ptabMatrices[0].MATgetNbColonnes(), ptabMatrices[0].MATgetNbLignes());
		//on additionne les deux premieres matrices
		try
		{
			matSommeGlobale = ptabMatrices[0] + ptabMatrices[1];
		}
		catch (std::exception const& e)
		{
			cerr << "ERREUR : " << e.what() << endl;
		}

		//on parcourt les matrices restantes
		for (int i = 2; i < inbFichiers; ++i) {
			//on additionne au fur et a mesure
			try
			{
				matSommeGlobale = matSommeGlobale + ptabMatrices[i];
			}
			catch (std::exception const& e)
			{
				cerr << "ERREUR : " << e.what() << endl;
			}
		}
		//on affiche le resultat
		std::cout << "Matrice sommme globale : " << endl;
		matSommeGlobale.MATafficherMatrice();
		
		//SOMMME / DIFFERENCE ALTERNE
		//on cree la matrice d'arrivee
		CMatrice<double> matSommeDiffAlterne(ptabMatrices[0].MATgetNbColonnes(), ptabMatrices[0].MATgetNbLignes());
		//on soustrait les deux premières matrices
		try
		{
			matSommeDiffAlterne = ptabMatrices[0] - ptabMatrices[1];
		}
		catch (std::exception const& e)
		{
			cerr << "ERREUR : " << e.what() << endl;
		}

		//on parcourt les matrices restantes
		for (int i = 2; i < inbFichiers; ++i) {
			//en fonction de l'indice de la matrice dans le tableau
			if (i % 2 == 0) {
				//on additionne
				try
				{
					matSommeDiffAlterne = matSommeDiffAlterne + ptabMatrices[i];
				}
				catch (std::exception const& e)
				{
					cerr << "ERREUR : " << e.what() << endl;
				}
			}
			else {
				//on soustrait
				try
				{
					matSommeDiffAlterne = matSommeDiffAlterne - ptabMatrices[i];
				}
				catch (std::exception const& e)
				{
					cerr << "ERREUR : " << e.what() << endl;
				}
			}
		}
		//on affiche le resultat
		std::cout << "Matrice sommme diff alterne : " << endl;
		matSommeDiffAlterne.MATafficherMatrice();

		//PRODUIT DE TOUTES LES MATRICES
		//on cree la matrice d'arrivee
		CMatrice<double> matProduitGlobal(ptabMatrices[0].MATgetNbColonnes(), ptabMatrices[0].MATgetNbLignes());
		//on multiplie les deux premieres matrices
		try
		{
			matProduitGlobal = ptabMatrices[0] * ptabMatrices[1];
		}
		catch (std::exception const& e)
		{
			cerr << "ERREUR : " << e.what() << endl;
		}

		//on parcourt les matrices restantes
		for (int i = 2; i < inbFichiers; ++i) {
			//on multiplie au fur et a mesure
			try
			{
				matProduitGlobal = matProduitGlobal * ptabMatrices[i];
			}
			catch (std::exception const& e)
			{
				cerr << "ERREUR : " << e.what() << endl;
			}
		}
		//on affiche le resultat
		std::cout << "Matrice produit global : " << endl;
		matProduitGlobal.MATafficherMatrice();
	}
	
}