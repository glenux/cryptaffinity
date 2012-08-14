#ifndef _LIBCRYPAFFINITY_CODEC_AFINE_HH
#define _LIBCRYPAFFINITY_CODEC_AFINE_HH

#include "codec.hh"
#include "key_affine.hh"

#include "cryptaffinity_global.hh"
#include "cryptaffinity_iface.hh"


namespace LibCryptAffinity {
	class CodecAfine : public Codec {
		private:
		public:
			CodecAfine();
			
			Text encode(Text t, KeyAfine k);
			Text decode(Text t, KeyAfine k);

	};
}

#endif
