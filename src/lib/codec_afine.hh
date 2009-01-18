#ifndef _LIBCRYPAFINITY_CODEC_AFINE_HH
#define _LIBCRYPAFINITY_CODEC_AFINE_HH

#include "codec.hh"
#include "key_afine.hh"

#include "cryptafinity_global.hh"
#include "cryptafinity_iface.hh"


namespace LibCryptAfinity {
	class CodecAfine : public Codec {
		private:
		public:
			CodecAfine();
			
			Text encode(Text t, KeyAfine k);
			Text decode(Text t, KeyAfine k);

	};
}

#endif
