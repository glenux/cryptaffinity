#ifndef _LIBCRYPAFINITY_ALPHABET_HH
#define _LIBCRYPAFINITY_ALPHABET_HH


#include "cryptafinity_global.hh"
#include "cryptafinity_iface.hh"

namespace LibCryptAfinity {
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
