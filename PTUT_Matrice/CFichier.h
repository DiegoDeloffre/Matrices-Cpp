
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

	void FIClireNbLignes();
	void FIClireNbColonnes();
	void FIClireTypeMatrice();
	void FIClireMatrice();

public:
	CFichier(const char* pFICcheminFichier);
	int getNBLignes();
	int getNBColonnes();
	char* getTypeMatrice();
	char*** getMatrice();
};