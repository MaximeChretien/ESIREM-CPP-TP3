/*
 *    @author  : Maxime Chretien (MixLeNain)
 *    @mail    : mchretien@linuxmail.org
 *    @project : ESIREM TP3
 *    @summary : Basic Caesar crypto class declaration
 *    @version : v1.1
 */

#include "caesar.h"

namespace crypto {

	Caesar::Caesar(const int key) : Encrypt(), _key(key) {}

	std::string Caesar::encode() {
		_cipher = "";

		for(int i = 0; _plain[i] != '\0'; i++) {
			char c = _plain[i];

			// Encode only ASCII lower case letters
			if (c >= 'a' && c <= 'z') {
				c += _key;
				while (c > 'z') {
					// Make sure we stay in
					// the lower case boundaries
					c -= 26;
				}
			}

			_cipher += c;
		}

		_cipher += '\0'; // Terminate the string

		return _cipher;
	}

	std::string Caesar::decode() {
		_plain = "";

		for(int i = 0; _cipher[i] != '\0'; i++) {
			char c = _cipher[i];

			// Decode only ASCII lower case letter
			if (c >= 'a' && c <= 'z') {
				c -= _key;
				while (c < 'a') {
					// Make sure we stay in
					// the lower case boundaries
					c += 26;
				}
			}

			_plain += c;
		}

		_plain += '\0'; // Terminate the string

		return _plain;
	}
}
