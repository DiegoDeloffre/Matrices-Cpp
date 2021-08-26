#include <exception>
using namespace std;

class CException : public exception
{
private:
	int iEXCnumero;				//Numéro de l'erreur
	const char* pcEXCphrase;	//Description de l'erreur
public:
	CException(int numero = 0, const char* phrase = "") throw()
		:iEXCnumero(numero), pcEXCphrase(phrase)
	{}

	//Renvoie le message d'erreur
	virtual const char* what() const throw()
	{
		return pcEXCphrase;
	}

	virtual ~CException() throw()
	{}


};