#ifndef _LIBCRYPAFFINITY_CODEC_VIGENERE_HH
#define _LIBCRYPAFFINITY_CODEC_VIGENERE_HH

#include "codec.hh"
#include "key_vigenere.hh"

#include "cryptaffinity_global.hh"
#include "cryptaffinity_iface.hh"


namespace LibCryptAffinity {
	class CodecVigenere : public Codec {
		private:
		public:
			CodecVigenere();

			Text encode(Text t, KeyVigenere k);
			Text decode(Text t, KeyVigenere k);
	};
}
#endif
