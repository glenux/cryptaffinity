#ifndef _LIBCRYPAFINITY_CODEC_HH
#define _LIBCRYPAFINITY_CODEC_HH


#include "text.hh"
#include "key.hh"
#include "cryptafinity_global.hh"
#include "cryptafinity_iface.hh"

namespace LibCryptAfinity {
	class Codec {
		private:
		public:
			Codec();

			virtual Text encode(Text plaintext, Key key);
			virtual Text decode(Text plaintext, Key key);

	};
}

#endif
