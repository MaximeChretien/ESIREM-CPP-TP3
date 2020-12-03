/*
 *    @author  : Maxime Chretien (MixLeNain)
 *    @mail    : mchretien@linuxmail.org
 *    @project : ESIREM TP3
 *    @summary : Vigenere crypto class declaration
 *    @version : v1.0
 */

#ifndef VIGENERE_H
#define VIGENERE_H

#include <string>
#include <vector>

#include "encrypt.h"

namespace crypto {

	class Vigenere : public Encrypt {
	public:
		Vigenere(const std::vector<int> key);
		Vigenere(const std::string key);

		std::string encode();
		std::string decode();

	private:
		std::vector<int> _key;
	};
}

#endif // VIGENERE_H
