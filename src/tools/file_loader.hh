
#include <string>
#include <list>
#include <vector>
#include <map>

#include <glib.h>
#include <glib/gfileutils.h>

#include "alphabet.hh"
#include "text.hh"

using namespace LibCryptAffinity;

namespace BreakAffinity{
	class FileLoader {
		private: 
		public:
			std::vector<int> loadPriorities(
					std::map<std::string, int> reverse_alpha,
					std::string filename);

			std::map<int, float> loadFrequencies(
					std::map<std::string, int> reverse_alpha,
					std::string filename);

			std::vector<std::string> loadFile(std::string filename);

			Alphabet loadAlphabet(std::string filename);

			Text loadText(
					std::map<std::string,int > reverse_alpha,
					std::string filename);

	};
}
