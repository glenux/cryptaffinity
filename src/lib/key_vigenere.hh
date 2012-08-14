#ifndef _CRYPTAFINIY_KEYVIGENERE_HH
#define _CRYPTAFINIY_KEYVIGENERE_HH

#include "cryptaffinity_global.hh"
#include "cryptaffinity_iface.hh"

#include "text.hh"
#include "key.hh"

namespace LibCryptAffinity {
	class KeyVigenere : public Key, public Text {
		private:
		public:
			KeyVigenere();

	};
}

#endif
