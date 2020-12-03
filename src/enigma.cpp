/*
 *    @author  : Maxime Chretien (MixLeNain)
 *    @mail    : mchretien@linuxmail.org
 *    @project : ESIREM TP3
 *    @summary : Enigma crypto class declaration
 *    @version : v1.0
 */

#include "enigma.h"

#include <algorithm>

namespace crypto {

	Enigma::Enigma(const std::array<char, 26> key) : Encrypt(), _key(key) {}

	std::string Enigma::encode() {
		long unsigned int index1 = 0;
		long unsigned int index2 = 0;
		int pos = 0;
		bool upper = false, valid = false;

		_cipher = "";

		for(int i = 0; _plain[i] != '\0'; i++) {
			upper = false;
			valid = false;
			char c = _plain[i];

			// Encode only ASCII letters
			if (c >= 'a' && c <= 'z') {
				pos = c - 'a';
				valid = true;
			} else if (c >= 'A' && c <= 'Z') {
				pos = c - 'A';
				upper = true;
				valid = true;
			}

			// If valid, caculate the position in the second rotor
			// and get the corresponding letter
			if (valid) {
				pos = (index1+index2+pos)%26;
				c = _key.at(pos);
			}

			// Put the letter in upper case if needed
			if (upper) {
				c += 'A'-'a';
			}

			_cipher += c;

			// Move to next key
			if(++index2 == 26) {
				index2 = 0;
				if (++index1 == 26) {
					index1 = 0;
				}
			}
		}

		_cipher += '\0'; // Terminate the string

		return _cipher;
	}

	std::string Enigma::decode() {
		std::array<char, 26> alphabet = {'a', 'b', 'c', 'd', 'e', 'f',
						'g', 'h', 'i', 'j', 'k', 'l',
						'm', 'n', 'o', 'p', 'q', 'r',
						's', 't', 'u', 'v', 'w', 'x',
						'y', 'z'};
		long unsigned int index1 = 0;
		long unsigned int index2 = 0;
		int pos = 0;
		bool upper = false, valid = false;

		_plain = "";

		for(int i = 0; _cipher[i] != '\0'; i++) {
			upper = false;
			valid = false;
			char c = _cipher[i];

			// Decode only ASCII elements
			if (c >= 'a' && c <= 'z') {
				valid = true;
			} else if (c >= 'A' && c <= 'Z') {
				c += 'a'-'A';
				upper = true;
				valid = true;
			}

			// If valid calculate the position in the alphabet
			// correponding to the position in the second rotor
			// and get the corresponding letter
			if (valid) {
				auto itr = std::find(_key.begin(), _key.end(), c);
				pos = std::distance(_key.begin(), itr);
				pos -= (index1+index2);
				pos = (26 + (pos%26)) % 26;
				c = alphabet.at(pos);
			}

			// Put the letter in upper case if needed
			if (upper) {
				c += 'A'-'a';
			}

			_plain += c;

			// Move to next key
			if(++index2 == 26) {
				index2 = 0;
				if (++index1 == 26) {
					index1 = 0;
				}
			}
		}

		_plain += '\0'; // Terminate the string

		return _plain;
	}
}
