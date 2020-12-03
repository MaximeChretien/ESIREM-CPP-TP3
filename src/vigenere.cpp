/*
 *    @author  : Maxime Chretien (MixLeNain)
 *    @mail    : mchretien@linuxmail.org
 *    @project : ESIREM TP3
 *    @summary : Vigenere crypto class declaration
 *    @version : v1.1
 */

#include "vigenere.h"

namespace crypto {

	Vigenere::Vigenere(const std::vector<int> key) : Encrypt(), _key(key) {}

	Vigenere::Vigenere(const std::string key) : Encrypt() {
		// Fill the _key vector with the letters places in the alphabet
		for (long unsigned int i = 0; key[i] != '\0'; i++) {
			_key.push_back(key[i]-'a'+1);
		}
	}

	std::string Vigenere::encode() {
		long unsigned int index = 0;

		_cipher = "";

		for(int i = 0; _plain[i] != '\0'; i++) {
			char c = _plain[i];

			// Encode only ASCII elements
			if (c >= ' ' && c <= '~') {
				c += _key.at(index);
				while (c > '~') {
					// If key number is really high we have
					// to make sure to stay in the boundaries
					c -= '~'-' '+1;
				}
			}

			_cipher += c;

			// Move to next key
			if(++index == _key.size()) {
				index = 0;
			}
		}

		_cipher += '\0'; // Terminate the string

		return _cipher;
	}

	std::string Vigenere::decode() {
		long unsigned int index = 0;
		_plain = "";

		for(int i = 0; _cipher[i] != '\0'; i++) {
			char c = _cipher[i];

			// Decode only ASCII elements
			if (c >= ' ' && c <= '~') {
				c -= _key.at(index);
				while (c < ' ') {
					// If key number is really high we have
					// to make sure to stay in the boundaries
					c += '~'-' '+1;
				}
			}

			_plain += c;

			// Move to next key
			if(++index == _key.size()) {
				index = 0;
			}
		}

		_plain += '\0'; // Terminate the string

		return _plain;
	}
}
