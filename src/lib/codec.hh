#ifndef _LIBCRYPAFFINITY_CODEC_HH
#define _LIBCRYPAFFINITY_CODEC_HH


#include "text.hh"
#include "key.hh"
#include "cryptaffinity_global.hh"
#include "cryptaffinity_iface.hh"

namespace LibCryptAffinity {
	class Codec {
		private:
		public:
			Codec();

			virtual Text encode(Text plaintext, Key key);
			virtual Text decode(Text plaintext, Key key);

	};
}

#endif
