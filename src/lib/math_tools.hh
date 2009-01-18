#ifndef _LIBCRYPTAFINITY_MATHTOOLS_HH
#define _LIBCRYPTAFINITY_MATHTOOLS_HH

#include "cryptafinity_global.hh"
#include "cryptafinity_iface.hh"

namespace LibCryptAfinity {
	class MathTools {
		private:
			std::vector<int> MathTools::pgcd_real(int * reste, int * quotient, int * coef_first, int * coef_second, int pas);

		public:
			int pgcd(int a, int b);
			int ppcm(int a, int b);

			std::vector<int> MathTools::pgcd_mod(int a, int b);
			
	int MathTools::inverse(int a, int modulo);

	};
}

#endif
