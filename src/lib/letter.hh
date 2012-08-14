#ifndef _LIBCRYPTAFFINITY_LETTER_HH
#define _LIBCRYPTAFFINITY_LETTER_HH

#include "cryptaffinity_global.hh"
#include "cryptaffinity_iface.hh"

#include "alphabet.hh"

namespace LibCryptAffinity {
	class Letter {
		private:
			Alphabet _alphabet;
			int _value;

		public:
			Letter(const Letter &orig);
			Alphabet getAlphabet();
			void setAlphabet(Alphabet alpha);
	};
}

#endif
