#ifndef _LIBCRYPTAFFINITY_MATHTOOLS_HH
#define _LIBCRYPTAFFINITY_MATHTOOLS_HH

#include "cryptaffinity_global.hh"
#include "cryptaffinity_iface.hh"

namespace LibCryptAffinity {

	class MathTools {
		private:
			std::vector<int> pgcd_real(int * reste, int * quotient, int * coef_first, int * coef_second, int pas);

		public:
			int pgcd(int a, int b);
			int ppcm(int a, int b);

			std::vector<int> pgcd_mod(int a, int b);
			
			int inverse(int a, int modulo);

	};
}

#endif
