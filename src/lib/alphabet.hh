#ifndef _LIBCRYPAFFINITY_ALPHABET_HH
#define _LIBCRYPAFFINITY_ALPHABET_HH


#include "cryptaffinity_global.hh"
#include "cryptaffinity_iface.hh"

namespace LibCryptAffinity {
	class ReverseAlphabet: public std::map<std::string, int> {
	};

	class Alphabet : public std::vector<std::string> {
		public: 
			Alphabet();
			Alphabet(std::string alphaString);
			ReverseAlphabet getReverse();
	};

}

#endif
