#ifndef _BREAKAFINITY_CONFIG_HH
#define _BREAKAFINITY_CONFIG_HH

#include <string>
#include <vector>
#include <map>

#include "alphabet.hh"
#include "text.hh"

using namespace LibCryptAfinity;

namespace BreakAfinity {
	class BreakerConfig {
		private:
			bool _modeVigenere;
			int _key_length;

			std::string _alphabet_file;
			std::string _text_file;
			std::string _frequencies_file;
			std::string _priorities_file;
			float _epsilon;

			Alphabet _alphabet;
			std::map<std::string, int> _reverse_alphabet; 
			Text _text;
			//std::map<int, float> _frequencies;
			float _frequencies;
			std::vector<int> _priorities;

		public:
			BreakerConfig();
			bool areParamReady();

			void setEpsilon(float e);
			float getEpsilon();


			void setAlphabetFile(std::string);
			std::string getAlphabetFile();

		//	void setFrequenciesFile(std::string);
		//	std::string getFrequenciesFile();

			void setPrioritiesFile(std::string);
			std::string getPrioritiesFile();

			void setTextFile(std::string);
			std::string getTextFile();

			void loadFiles();

			void reverseAlphabet();

			void setKeyLength(int len);
			int getKeyLength();

			void setMode(char * c);
			bool isModeVigenere();

			Alphabet getAlphabet();

			float getFrequencies();
			void setFrequencies(float f);

			std::vector<int> getPriorities();

			Text getText();
	};

}

#endif
