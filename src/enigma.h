/*
 *    @author  : Maxime Chretien (MixLeNain)
 *    @mail    : mchretien@linuxmail.org
 *    @project : ESIREM TP3
 *    @summary : Enigma crypto class declaration
 *    @version : v1.0
 */

#ifndef ENIGMA_H
#define ENIGMA_H

#include <string>
#include <array>

#include "encrypt.h"

namespace crypto {

	class Enigma : public Encrypt {
	public:
		Enigma(const std::array<char, 26> key);

		std::string encode();
		std::string decode();

	private:
		const std::array<char, 26> _key;
	};
}

#endif // ENIGMA_H
