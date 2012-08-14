#ifndef _BREAKAFFINITY_CMD_HH
#define _BREAKAFFINITY_CMD_HH

#include <string.h>
#include <list>

#include "breakaffinity.hh"
#include "ba_config.hh"


namespace BreakAffinity {
	
	class BreakAffinity {
		private:
			BreakerConfig _config;
		public:
			BreakAffinity();
			void init(int argc, char ** argv);
			void loadFiles();
			void run();
			void runAfine();
			void runVigenere();
	};

}

#endif
