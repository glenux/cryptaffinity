#ifndef _BREAKAFINITY_CMD_HH
#define _BREAKAFINITY_CMD_HH

#include <string.h>
#include <list>

#include "breakafinity.hh"
#include "ba_config.hh"


namespace BreakAfinity {
	
	class BreakAfinity {
		private:
			BreakerConfig _config;
		public:
			BreakAfinity();
			void init(int argc, char ** argv);
			void loadFiles();
			void run();
			void runAfine();
			void runVigenere();
	};

}

#endif
