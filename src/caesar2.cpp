/*
 *    @author  : Maxime Chretien (MixLeNain)
 *    @mail    : mchretien@linuxmail.org
 *    @project : ESIREM TP3
 *    @summary : Advanced Caesar crypto class declaration
 *    @version : v1.0
 */

#include "caesar2.h"

namespace crypto {

	Caesar2::Caesar2(const int key) : Encrypt(), _key(key) {}

	std::string Caesar2::encode() {
		_cipher = "";

		for(int i = 0; _plain[i] != '\0'; i++) {
			char c = _plain[i];

			if (c >= ' ' && c <= '~') {
				c += _key;
				if (c > '~') {
					c -= '~'-' '+1;
				}
			}

			_cipher += c;
		}

		_cipher += '\0';

		return _cipher;
	}

	std::string Caesar2::decode() {
		_plain = "";

		for(int i = 0; _cipher[i] != '\0'; i++) {
			char c = _cipher[i];

			if (c >= ' ' && c <= '~') {
				c -= _key;
				if (c < ' ') {
					c += '~'-' '+1;
				}
			}

			_plain += c;
		}

		_plain += '\0';

		return _plain;
	}
}
