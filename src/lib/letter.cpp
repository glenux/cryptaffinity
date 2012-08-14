#include "letter.hh"

namespace LibCryptAffinity {

	Letter::Letter(const Letter &orig){
		this->_alphabet = orig._alphabet;
	}

	Alphabet Letter::getAlphabet() {
		return this->_alphabet;
	}

	void Letter::setAlphabet(Alphabet alpha) {
		this->_alphabet = alpha;
	}
}

