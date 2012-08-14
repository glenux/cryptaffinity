
#include "alphabet.hh"

namespace LibCryptAffinity {

	Alphabet::Alphabet() : std::vector<std::string>() { }

	Alphabet::Alphabet(std::string alphaString) : std::vector<std::string>() { 
		int i;
		std::string e;
		for (i = 0; i < alphaString.length(); i++){
			e.erase();
			e+=alphaString[i];
			this->push_back(e);
		}
	}

	ReverseAlphabet Alphabet::getReverse() {
		ReverseAlphabet ra;
		int i;
		std::string c;
		for (i=0; i< this->size(); i++){
			c = (*this)[i];
			ra[c] = i;
			//printf("%d->%s ",i,this->_alphabet[i].c_str());
		}
		//printf("\n");
		return ra;
	}

}
