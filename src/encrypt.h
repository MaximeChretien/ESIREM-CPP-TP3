/*
 *    @author  : Maxime Chretien (MixLeNain)
 *    @mail    : mchretien@linuxmail.org
 *    @project : ESIREM TP3
 *    @summary : Base class declaration for crypto functions
 *    @version : v1.1
 */

#ifndef ENCRYPT_H
#define ENCRYPT_H

#include <string>

namespace crypto {

	class Encrypt {
	public:
		Encrypt();

		std::string get_plain() const;
		std::string get_cipher() const;

		bool read(bool isPlain, std::string filename);
		bool write(bool isPlain, std::string filename);

		std::string encode();
		std::string decode();

	protected:
		std::string _plain;
		std::string _cipher;
	};
}

#endif // ENCRYPT_H
