#ifndef _LIBCRYPTAFINITY_FREQANALYSER_HH
#define _LIBCRYPTAFINITY_FREQANALYSER_HH

#include "cryptafinity_global.hh"
#include "cryptafinity_iface.hh"

#include "text.hh" // body

namespace LibCryptAfinity {

	class FreqAnalyser {
		private:
				
		public:
			std::list<TextCounter> getPriorities(Text t, int keylen, int column);
	};

}
#endif
