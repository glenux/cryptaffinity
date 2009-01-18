#ifndef _LIBCRYPTAFINITY_LETTER_HH
#define _LIBCRYPTAFINITY_LETTER_HH

#include "cryptafinity_global.hh"
#include "cryptafinity_iface.hh"

#include "alphabet.hh"

namespace LibCryptAfinity {
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
