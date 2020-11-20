/*
 *    @author  : Maxime Chretien (MixLeNain)
 *    @mail    : mchretien@linuxmail.org
 *    @project : ESIREM TP3
 *    @summary : Basic Caesar crypto class declaration
 *    @version : v1.0
 */

#include "caesar.h"

namespace crypto {

	Caesar::Caesar(const int key) : Encrypt(), _key(key) {}

	std::string Caesar::encode() {
		_cipher = "";

		for(int i = 0; _plain[i] != '\0'; i++) {
			char c = _plain[i];

			if (c >= 'a' && c <= 'z') {
				c += _key;
				if (c > 'z') {
					c -= 26;
				}
			}

			_cipher += c;
		}

		_cipher += '\0';

		return _cipher;
	}

	std::string Caesar::decode() {
		_plain = "";

		for(int i = 0; _cipher[i] != '\0'; i++) {
			char c = _cipher[i];

			if (c >= 'a' && c <= 'z') {
				c -= _key;
				if (c < 'a') {
					c += 26;
				}
			}

			_plain += c;
		}

		_plain += '\0';

		return _plain;
	}
}
