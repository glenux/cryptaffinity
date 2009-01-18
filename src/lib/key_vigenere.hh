#ifndef _CRYPTAFINIY_KEYVIGENERE_HH
#define _CRYPTAFINIY_KEYVIGENERE_HH

#include "cryptafinity_global.hh"
#include "cryptafinity_iface.hh"

#include "text.hh"
#include "key.hh"

namespace LibCryptAfinity {
	class KeyVigenere : public Key, public Text {
		private:
		public:
			KeyVigenere();

	};
}

#endif
