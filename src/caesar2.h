/*
 *    @author  : Maxime Chretien (MixLeNain)
 *    @mail    : mchretien@linuxmail.org
 *    @project : ESIREM TP3
 *    @summary : Advanced Caesar crypto class declaration
 *    @version : v1.1
 */

#ifndef CAESAR2_H
#define CAESAR2_H

#include <string>

#include "encrypt.h"

namespace crypto {

	class Caesar2 : public Encrypt {
	public:
		Caesar2(const int key = 3);

		std::string encode();
		std::string decode();

	private:
		const int _key;
	};
}

#endif // CAESAR2_H
