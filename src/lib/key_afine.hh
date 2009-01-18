#ifndef _CRYPTAFINIY_KEYAFINE_HH
#define _CRYPTAFINIY_KEYAFINE_HH

#include "cryptafinity_global.hh"
#include "cryptafinity_iface.hh"

#include "key.hh" // declaration
#include "text.hh" // body

namespace LibCryptAfinity {
	class KeyAfine : public Key {
		private:
			int _a;
			int _b;
			
		public:
			void setCoefA(int i);
			void setCoefB(int i);

			int getCoefA();
			int getCoefB();

			std::string toString();
	};
}

#endif
