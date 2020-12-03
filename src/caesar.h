/*
 *    @author  : Maxime Chretien (MixLeNain)
 *    @mail    : mchretien@linuxmail.org
 *    @project : ESIREM TP3
 *    @summary : Basic Caesar crypto class declaration
 *    @version : v1.1
 */

#ifndef CAESAR_H
#define CAESAR_H

#include "encrypt.h"

namespace crypto {

	class Caesar : public Encrypt {
	public:
		Caesar(const int key = 3);

		std::string encode();
		std::string decode();

	private:
		const int _key;
	};
}

#endif // CAESAR_H
