/*
 *    @author  : Maxime Chretien (MixLeNain)
 *    @mail    : mchretien@linuxmail.org
 *    @project : ESIREM TP3
 *    @summary : Test application of different cryptographic functions
 *    @version : v0.2
 */

#include <iostream>

using std::cout;
using std::endl;

#include "encrypt.h"

int main () {
	crypto::Encrypt encrypt;

	cout << "### Test de la classe Encrypt ###" << endl;

	cout << "Lecture du fichier test1.txt en texte non chiffré..." << endl;
	if (!encrypt.read(true, "./test1.txt")) {
		cout << "Erreur à l'ouverture du fichier" << endl;
		return 1;
	}
	cout << endl;

	cout << "Affichage de la valeur chargée dans le texte non chiffré : " << encrypt.get_plain() << endl;
	cout << endl;

	cout << "Cryptage du texte : " << encrypt.encode() << endl;
	cout << endl;

	cout << "Affichage de la valeur du texte non chiffré : " << encrypt.get_plain() << endl;
	cout << "Affichage de la valeur du texte chiffré : " << encrypt.get_cipher() << endl;
	cout << endl;

	cout << "Lecture du fichier test2.txt en texte chiffré..." << endl;
	if (!encrypt.read(false, "./test2.txt")) {
		cout << "Erreur à l'ouverture du fichier" << endl;
		return 1;
	}
	cout << endl;

	cout << "Affichage de la valeur chargée dans le texte chiffré : " << encrypt.get_cipher() << endl;
	cout << endl;

	cout << "Décryptage du texte : " << encrypt.decode() << endl;
	cout << endl;

	cout << "Affichage de la valeur du texte non chiffré : " << encrypt.get_plain() << endl;
	cout << "Affichage de la valeur du texte chiffré : " << encrypt.get_cipher() << endl;
	cout << endl;

	cout << "Ecriture du texte chiffré dans le fichier result1.txt..." << endl;
	if (!encrypt.write(false, "./result1.txt")) {
		cout << "Erreur à l'ouverture du fichier" << endl;
		return 1;
	}

	return 0;
}
