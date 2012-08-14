
#include "breakaffinity.hh"
#include "ba_cmd.hh"

using namespace BreakAffinity;

int main(int argc, char ** argv){
	::BreakAffinity::BreakAffinity br_af;
	
	br_af.init(argc, argv);
	br_af.loadFiles();
	br_af.run();
	return EXIT_SUCCESS;
}
