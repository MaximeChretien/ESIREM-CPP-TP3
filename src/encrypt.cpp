/*
 *    @author  : Maxime Chretien (MixLeNain)
 *    @mail    : mchretien@linuxmail.org
 *    @project : ESIREM TP3
 *    @summary : Base class implementation for crypto functions
 *    @version : v1.1
 */

#include "encrypt.h"

#include <fstream>

namespace crypto {

	Encrypt::Encrypt () : _plain(""), _cipher("") {}

	std::string Encrypt::get_plain() const {
		return _plain;
	}

	std::string Encrypt::get_cipher() const {
		return _cipher;
	}

	bool Encrypt::read(bool isPlain, std::string filename) {
		std::ifstream file(filename.c_str());

		if (!file)
			return false;

		// Check if we import decoded or encoded text
		if (isPlain) {
			getline(file, _plain);
		} else {
			getline(file, _cipher);
		}

		file.close();
		return true;

	}

	bool Encrypt::write(bool isPlain, std::string filename) {
		std::ofstream file(filename.c_str());

		if (!file)
			return false;

		// Check if we export decoded or encoded text
		if (isPlain) {
			file << _plain;
		} else {
			file << _cipher;
		}

		file.close();
		return true;
	}

	std::string Encrypt::encode() {
		_cipher = _plain;
		return _cipher;
	}

	std::string Encrypt::decode() {
		_plain = _cipher;
		return _plain;
	}
}
