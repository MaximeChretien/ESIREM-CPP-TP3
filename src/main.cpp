/*
 *    @author  : Maxime Chretien (MixLeNain)
 *    @mail    : mchretien@linuxmail.org
 *    @project : ESIREM TP3
 *    @summary : Test application of different cryptographic functions
 *    @version : v0.6
 */

#include <iostream>
#include <vector>

using std::cout;
using std::endl;

#include "encrypt.h"
#include "caesar.h"
#include "caesar2.h"
#include "vigenere.h"

int main () {
	// Create crypto objects
	crypto::Encrypt encrypt;
	crypto::Caesar caesar(4);
	crypto::Caesar2 caesar2(4);
	std::vector<int> vigenere1Key = {3, 1, 4, 1, 5};
	crypto::Vigenere vigenere1(vigenere1Key);
	crypto::Vigenere vigenere2("ecologie");

	// Test Encrypt object
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

	cout << endl << endl;

	// Test Caesar object
	cout << "### Test de la classe Caesar ###" << endl;

	cout << "Lecture du fichier test1.txt en texte non chiffré..." << endl;
	if (!caesar.read(true, "./test1.txt")) {
		cout << "Erreur à l'ouverture du fichier" << endl;
		return 1;
	}
	cout << endl;

	cout << "Affichage de la valeur chargée dans le texte non chiffré : " << caesar.get_plain() << endl;
	cout << endl;

	cout << "Cryptage du texte : " << caesar.encode() << endl;
	cout << endl;

	cout << "Affichage de la valeur du texte non chiffré : " << caesar.get_plain() << endl;
	cout << "Affichage de la valeur du texte chiffré : " << caesar.get_cipher() << endl;
	cout << endl;

	cout << "Lecture du fichier test3.txt en texte chiffré..." << endl;
	if (!caesar.read(false, "./test3.txt")) {
		cout << "Erreur à l'ouverture du fichier" << endl;
		return 1;
	}
	cout << endl;

	cout << "Affichage de la valeur chargée dans le texte chiffré : " << caesar.get_cipher() << endl;
	cout << endl;

	cout << "Décryptage du texte : " << caesar.decode() << endl;
	cout << endl;

	cout << "Affichage de la valeur du texte non chiffré : " << caesar.get_plain() << endl;
	cout << "Affichage de la valeur du texte chiffré : " << caesar.get_cipher() << endl;
	cout << endl;

	cout << "Ecriture du texte chiffré dans le fichier result2.txt..." << endl;
	if (!caesar.write(false, "./result2.txt")) {
		cout << "Erreur à l'ouverture du fichier" << endl;
		return 1;
	}

	cout << endl << endl;

	// Test Caesar2 object
	cout << "### Test de la classe Caesar2 ###" << endl;

	cout << "Lecture du fichier test1.txt en texte non chiffré..." << endl;
	if (!caesar2.read(true, "./test1.txt")) {
		cout << "Erreur à l'ouverture du fichier" << endl;
		return 1;
	}
	cout << endl;

	cout << "Affichage de la valeur chargée dans le texte non chiffré : " << caesar2.get_plain() << endl;
	cout << endl;

	cout << "Cryptage du texte : " << caesar2.encode() << endl;
	cout << endl;

	cout << "Affichage de la valeur du texte non chiffré : " << caesar2.get_plain() << endl;
	cout << "Affichage de la valeur du texte chiffré : " << caesar2.get_cipher() << endl;
	cout << endl;

	cout << "Lecture du fichier test4.txt en texte chiffré..." << endl;
	if (!caesar2.read(false, "./test4.txt")) {
		cout << "Erreur à l'ouverture du fichier" << endl;
		return 1;
	}
	cout << endl;

	cout << "Affichage de la valeur chargée dans le texte chiffré : " << caesar2.get_cipher() << endl;
	cout << endl;

	cout << "Décryptage du texte : " << caesar2.decode() << endl;
	cout << endl;

	cout << "Affichage de la valeur du texte non chiffré : " << caesar2.get_plain() << endl;
	cout << "Affichage de la valeur du texte chiffré : " << caesar2.get_cipher() << endl;
	cout << endl;

	cout << "Ecriture du texte chiffré dans le fichier result3.txt..." << endl;
	if (!caesar2.write(false, "./result3.txt")) {
		cout << "Erreur à l'ouverture du fichier" << endl;
		return 1;
	}

	cout << endl << endl;

	// Test first Vigenere object
	cout << "### Test de la classe Vigenere 1 ###" << endl;

	cout << "Lecture du fichier test1.txt en texte non chiffré..." << endl;
	if (!vigenere1.read(true, "./test1.txt")) {
		cout << "Erreur à l'ouverture du fichier" << endl;
		return 1;
	}
	cout << endl;

	cout << "Affichage de la valeur chargée dans le texte non chiffré : " << vigenere1.get_plain() << endl;
	cout << endl;

	cout << "Cryptage du texte : " << vigenere1.encode() << endl;
	cout << endl;

	cout << "Affichage de la valeur du texte non chiffré : " << vigenere1.get_plain() << endl;
	cout << "Affichage de la valeur du texte chiffré : " << vigenere1.get_cipher() << endl;
	cout << endl;

	cout << "Lecture du fichier test5.txt en texte chiffré..." << endl;
	if (!vigenere1.read(false, "./test5.txt")) {
		cout << "Erreur à l'ouverture du fichier" << endl;
		return 1;
	}
	cout << endl;

	cout << "Affichage de la valeur chargée dans le texte chiffré : " << vigenere1.get_cipher() << endl;
	cout << endl;

	cout << "Décryptage du texte : " << vigenere1.decode() << endl;
	cout << endl;

	cout << "Affichage de la valeur du texte non chiffré : " << vigenere1.get_plain() << endl;
	cout << "Affichage de la valeur du texte chiffré : " << vigenere1.get_cipher() << endl;
	cout << endl;

	cout << "Ecriture du texte chiffré dans le fichier result4.txt..." << endl;
	if (!vigenere1.write(false, "./result4.txt")) {
		cout << "Erreur à l'ouverture du fichier" << endl;
		return 1;
	}

	cout << endl << endl;

	// Test second Vigenere object
	cout << "### Test de la classe Vigenere 2 ###" << endl;

	cout << "Lecture du fichier test1.txt en texte non chiffré..." << endl;
	if (!vigenere2.read(true, "./test1.txt")) {
		cout << "Erreur à l'ouverture du fichier" << endl;
		return 1;
	}
	cout << endl;

	cout << "Affichage de la valeur chargée dans le texte non chiffré : " << vigenere2.get_plain() << endl;
	cout << endl;

	cout << "Cryptage du texte : " << vigenere2.encode() << endl;
	cout << endl;

	cout << "Affichage de la valeur du texte non chiffré : " << vigenere2.get_plain() << endl;
	cout << "Affichage de la valeur du texte chiffré : " << vigenere2.get_cipher() << endl;
	cout << endl;

	cout << "Lecture du fichier test6.txt en texte chiffré..." << endl;
	if (!vigenere2.read(false, "./test6.txt")) {
		cout << "Erreur à l'ouverture du fichier" << endl;
		return 1;
	}
	cout << endl;

	cout << "Affichage de la valeur chargée dans le texte chiffré : " << vigenere2.get_cipher() << endl;
	cout << endl;

	cout << "Décryptage du texte : " << vigenere2.decode() << endl;
	cout << endl;

	cout << "Affichage de la valeur du texte non chiffré : " << vigenere2.get_plain() << endl;
	cout << "Affichage de la valeur du texte chiffré : " << vigenere2.get_cipher() << endl;
	cout << endl;

	cout << "Ecriture du texte chiffré dans le fichier result5.txt..." << endl;
	if (!vigenere2.write(false, "./result5.txt")) {
		cout << "Erreur à l'ouverture du fichier" << endl;
		return 1;
	}

	return 0;
}
