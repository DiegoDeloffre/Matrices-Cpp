#pragma once
#include <iostream>
class CFichier
{
private:
	char* FICcontenuFichier;
	int iFICtailleFichier;
	char* FICtypeMatrice;
	int iFICnbLignes;
	int iFICnbColonnes;
	char*** pFICtableau;

	//Lit le nombre de lignes de la matrice dans le fichier et le stocke dans l'attribut de classe
	void FIClireNbLignes() {
		//on indique la chaine a chercher dans le fichier
		const char* pchaineAChercher = "NBLignes\0";

		//on alloue une zone memoire pour la chaine a recuperer
		char* pchaineTrouvee = (char*)malloc(sizeof(char) * 10);

		//on parcourt tout le fichier
		for (int icurseurFichier = 0; icurseurFichier < iFICtailleFichier; icurseurFichier++) {
			int icurseurRecherche = 0;

			//on saute la chaine a chercher (la valeur qui nous interesse est juste apres)
			while (pchaineAChercher[icurseurRecherche] == FICcontenuFichier[icurseurFichier + icurseurRecherche]) {
				icurseurRecherche++;
			}
			//si il y a un caractere
			if (pchaineAChercher[icurseurRecherche] == '\0') {
				icurseurFichier += icurseurRecherche + 1;
				int icurseurTrouve = 0;
				//tant que l'on est pas a la fin de la ligne
				while (FICcontenuFichier[icurseurFichier] != '\n') {
					//on enregistre la chaine a recuperer caracteres par caracteres
					pchaineTrouvee[icurseurTrouve] = FICcontenuFichier[icurseurFichier];
					icurseurFichier++;
					icurseurTrouve++;
				}
				//on transforme la chaine de caracteres recuperee en entier et on l'associe a l'attribut de la classe
				iFICnbLignes = atoi(pchaineTrouvee);
				//on libere la zone memoire allouee pour la chaine a recuperer
				free(pchaineTrouvee);
				//on quitte le programme
				return;
			}
		}
		//si on arrive ici c'est que la chaine n'a pas pu etre lue
		//on libere la zone memoire allouee pour la chaine a recuperer
		free(pchaineTrouvee);
		//on indique l'erreur
		std::cout << "Le nombre de lignes n'a pas pu etre lu. Le fichier ne respecte surement pas les conventions d'ecritures.";
		exit(-1);
	}

	//Lit le nombre de colonnes de la matrice dans le fichier et le stocke dans l'attribut de classe
	void FIClireNbColonnes() {
		//on indique la chaine a chercher dans le fichier
		const char* pchaineAChercher = "NBColonnes\0";

		//on alloue une zone memoire pour la chaine a recuperer
		char* pchaineTrouvee = (char*)malloc(sizeof(char) * 10);

		//on parcourt tout le fichier
		for (int icurseurFichier = 0; icurseurFichier < iFICtailleFichier; icurseurFichier++) {
			int icurseurRecherche = 0;

			//on saute la chaine a chercher (la valeur qui nous interesse est juste apres)
			while (pchaineAChercher[icurseurRecherche] == FICcontenuFichier[icurseurFichier + icurseurRecherche]) {
				icurseurRecherche++;
			}
			//si il y a un caractere
			if (pchaineAChercher[icurseurRecherche] == '\0') {
				icurseurFichier += icurseurRecherche + 1;
				int icurseurTrouve = 0;
				//tant que l'on est pas a la fin de la ligne
				while (FICcontenuFichier[icurseurFichier] != '\n') {
					//on enregistre la chaine a recuperer caracteres par caracteres
					pchaineTrouvee[icurseurTrouve] = FICcontenuFichier[icurseurFichier];
					icurseurFichier++;
					icurseurTrouve++;
				}
				//on transforme la chaine de caracteres recuperee en entier et on l'associe a l'attribut de la classe
				iFICnbColonnes = atoi(pchaineTrouvee);
				//on libere la zone memoire allouee pour la chaine a recuperer
				free(pchaineTrouvee);
				//on quitte le programme
				return;
			}
		}
		//si on arrive ici c'est que la chaine n'a pas pu etre lue
		//on libere la zone memoire allouee pour la chaine a recuperer
		free(pchaineTrouvee);
		//on indique l'erreur
		std::cout << "Le nombre de colonnes n'a pas pu etre lu. Le fichier ne respecte surement pas les conventions d'ecritures.";
		exit(-1);
	}

	//Lit le type d'objet de la matrice dans le fichier et le stocke dans l'attribut de classe
	void FIClireTypeMatrice() {
		//on indique la chaine a chercher dans le fichier
		const char* pchaineAChercher = "TypeMatrice\0";

		//on alloue une zone memoire pour la chaine a recuperer
		char* pchaineTrouvee = (char*)malloc(sizeof(char) * 10);

		//on parcourt tout le fichier
		for (int icurseurFichier = 0; icurseurFichier < iFICtailleFichier; icurseurFichier++) {
			int icurseurRecherche = 0;
			//on saute la chaine a chercher (la valeur qui nous interesse est juste apres)
			while (pchaineAChercher[icurseurRecherche] == FICcontenuFichier[icurseurFichier + icurseurRecherche]) {
				icurseurRecherche++;
			}
			//si il y a un caractere
			if (pchaineAChercher[icurseurRecherche] == '\0') {
				icurseurFichier += icurseurRecherche + 1;
				int icurseurTrouve = 0;
				//tant que l'on est pas a la fin de la ligne
				while (FICcontenuFichier[icurseurFichier] != '\n') {
					//on enregistre la chaine a recuperer caracteres par caracteres
					pchaineTrouvee[icurseurTrouve] = FICcontenuFichier[icurseurFichier];
					icurseurFichier++;
					icurseurTrouve++;
				}
				//on ajoute le caractere de fin a la chaine que l'on vient de recuperer
				pchaineTrouvee[icurseurTrouve] = '\0';

				//on alloue une zone memoire pour la chaine a stocker en attribut de classe
				FICtypeMatrice = (char*)malloc(sizeof(char) * icurseurTrouve);

				//on stocke la chaine recuperee dans l'attribut de classe
				FICtypeMatrice = pchaineTrouvee;

				//on libere la zone memoire allouee pour la chaine a recuperer
				free(pchaineTrouvee);

				//on quitte le programme
				return;
			}
		}
		//si on arrive ici c'est que la chaine n'a pas pu etre lue
		//on libere la zone memoire allouee pour la chaine a recuperer
		free(pchaineTrouvee);
		//on indique l'erreur
		std::cout << "Le type de la matrice n'a pas pu etre lu correctement. Le fichier ne respecte surement pas les conventions d'ecritures.";
		exit(-1);
	}

	//Lit la matrice dans le fichier et la stocke dans l'attribut de classe
	void FIClireMatrice() {
		//on indique la chaine a chercher dans le fichier
		const char* pchaineAChercher = "Matrice= [\0";

		//on alloue une zone memoire pour la chaine a recuperer
		char* pchaineTrouvee = (char*)malloc(sizeof(char) * 10);

		//on parcourt tout le fichier
		for (int icurseurFichier = 0; icurseurFichier < iFICtailleFichier; icurseurFichier++) {
			int icurseurRecherche = 0;
			//on saute la chaine a chercher (la valeur qui nous interesse est juste apres)
			while (pchaineAChercher[icurseurRecherche] == FICcontenuFichier[icurseurFichier + icurseurRecherche]) {
				icurseurRecherche++;
			}
			//si il y a un caractere
			if (pchaineAChercher[icurseurRecherche] == '\0') {
				//on alloue une zone memoire dans l'attribut de classe pour stocker la matrice
				pFICtableau = (char***)malloc(sizeof(char**) * iFICnbLignes);
				for (int iCompteur = 0; iCompteur < iFICnbLignes; iCompteur++) {
					pFICtableau[iCompteur] = (char**)malloc(sizeof(char*) * iFICnbLignes);
				}

				icurseurFichier += icurseurRecherche + 1;
				int icurseurTrouve = 0;
				int iCompteurLignes = 0;

				//tant que l'on est pas au dernier caractere du fichier
				while (FICcontenuFichier[icurseurFichier] != ']') {
					int iCompteurColonnes = 0;
					//tant que l'on est pas a la fin d'une ligne
					while (FICcontenuFichier[icurseurFichier] != '\n' && FICcontenuFichier[icurseurFichier] != ']') {
						//on alloue une zone memoire pour stocker la premiere valeur de la matrice
						char* pCharAAjouter = (char*)malloc(sizeof(char) * 10);
						int icurseurCharAAjouter = 0;

						//tant que l'on est sur la premiere valeur
						while (FICcontenuFichier[icurseurFichier] != ' ' && FICcontenuFichier[icurseurFichier] != '\n' && FICcontenuFichier[icurseurFichier] != ']') {
							//on enregistre la chaine a recuperer caracteres par caracteres
							pCharAAjouter[icurseurCharAAjouter] = FICcontenuFichier[icurseurFichier];
							icurseurFichier++;
							icurseurCharAAjouter++;
						}
						//on ajoute le caractere de fin a la chaine que l'on vient de recuperer
						pCharAAjouter[icurseurCharAAjouter] = '\0';

						//on alloue une zone memoire et on stocke la chaine recuperee dans l'attribut de classe
						pFICtableau[iCompteurLignes][iCompteurColonnes] = new char[icurseurCharAAjouter];
						pFICtableau[iCompteurLignes][iCompteurColonnes] = pCharAAjouter;

						//si l'on n'est pas a la fin de la ligne, on incremente les curseurs
						if (FICcontenuFichier[icurseurFichier] != '\n') {
							iCompteurColonnes++;
							icurseurFichier++;
						}
					}
					iCompteurLignes++;
					icurseurFichier++;
				}
				//on libere la zone memoire allouee pour la chaine a recuperer
				free(pchaineTrouvee);
				//on quitte le programme
				return;
			}
		}
		//si on arrive ici c'est que la chaine n'a pas pu etre lue
		//on libere la zone memoire allouee pour la chaine a recuperer
		free(pchaineTrouvee);
		//on indique l'erreur
		std::cout << "Les valeurs de la matrice n'ont pas pu etre lues correctement. Le fichier ne respecte surement pas les conventions d'ecritures.";
		exit(-1);
	}

public:
	//Constructeur de CFichier 
	//construit un fichier de chemin pFICcheminFichier
	CFichier(const char* pFICcheminFichier) {
		FILE *FFichier;
		errno_t bError;
		char cChar;
		int iCurseurFichier = 0;

		//on ouvre le fichier en gerant les erreurs d'ouvertures
		if (bError = fopen_s(&FFichier, pFICcheminFichier, "r") != 0) {
			std::cout << "Ouverture du fichier impossible\n";
			exit(-1);
		}
		else {
			//on recupere l'indice de fin de fichier
			fseek(FFichier, 0, SEEK_END);
			iFICtailleFichier = ftell(FFichier);
			fseek(FFichier, 0, SEEK_SET);

			//on alloue une zone memoire pour le contenu du fichier
			FICcontenuFichier = (char*)malloc(sizeof(char) * iFICtailleFichier);

			//tant que l'on est pas a la fin du fichier
			while ((cChar = fgetc(FFichier)) != EOF && iCurseurFichier < iFICtailleFichier)
			{
				//on recupere le contenu caratere par caractere
				FICcontenuFichier[iCurseurFichier] = cChar;
				iCurseurFichier++;
			}
			//on ajoute le caractere de fin de chaine
			FICcontenuFichier[iCurseurFichier] = '\0';

			//on ferme le fichier
			fclose(FFichier);

			//on recupere les attributs en utilisant les fonctions adequates
			FIClireNbLignes();
			FIClireNbColonnes();
			FIClireTypeMatrice();
			FIClireMatrice();
			
		}
	}

	//Renvoie le nombre de lignes de la matrice
	int getNBLignes() {
		return iFICnbLignes;
	}

	//Renvoie le nombre de lignes de la matrice
	int getNBColonnes() {
		return iFICnbColonnes;
	}

	//Renvoie le type de la matrice
	char* getTypeMatrice() {
		return FICtypeMatrice;
	}

	//Renvoie le tableau de valeurs de la matrice
	char*** getMatrice() {
		return (char***)pFICtableau;
	}
};