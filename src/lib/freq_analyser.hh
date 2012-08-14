#ifndef _LIBCRYPTAFFINITY_FREQANALYSER_HH
#define _LIBCRYPTAFFINITY_FREQANALYSER_HH

#include "cryptaffinity_global.hh"
#include "cryptaffinity_iface.hh"

#include "text.hh" // body

namespace LibCryptAffinity {

	class FreqAnalyser {
		private:
				
		public:
			std::list<TextCounter> getPriorities(Text t, int keylen, int column);
	};

}
#endif
