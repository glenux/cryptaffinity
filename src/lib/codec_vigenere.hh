#ifndef _LIBCRYPAFINITY_CODEC_VIGENERE_HH
#define _LIBCRYPAFINITY_CODEC_VIGENERE_HH

#include "codec.hh"
#include "key_vigenere.hh"

#include "cryptafinity_global.hh"
#include "cryptafinity_iface.hh"


namespace LibCryptAfinity {
	class CodecVigenere : public Codec {
		private:
		public:
			CodecVigenere();

			Text encode(Text t, KeyVigenere k);
			Text decode(Text t, KeyVigenere k);
	};
}
#endif
