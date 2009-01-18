
#include "breakafinity.hh"
#include "ba_cmd.hh"

using namespace BreakAfinity;

int main(int argc, char ** argv){
	BreakAfinity::BreakAfinity br_af;
	
	br_af.init(argc, argv);
	br_af.loadFiles();
	br_af.run();
	return EXIT_SUCCESS;
}
