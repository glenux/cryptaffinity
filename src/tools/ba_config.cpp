
#include "ba_config.hh"
#include "file_loader.hh"

namespace BreakAfinity {
	void BreakerConfig::setMode(char * m){
		switch(m[0]){
			case 'v':
			case 'V':
				this->_modeVigenere = true;
				break;
			case 'a':
			case 'A':
				this->_modeVigenere = false;
				break;
			default:
				this->_modeVigenere = true;
				break;
		}

	}

	bool BreakerConfig::isModeVigenere(){
		return this->_modeVigenere;
	}

	BreakerConfig::BreakerConfig(){
		this->_key_length = -1;
		this->_modeVigenere = true;
	}

	Alphabet BreakerConfig::getAlphabet(){
		return this->_alphabet;
	}

	void BreakerConfig::setFrequencies(float f){
		this->_frequencies = f;
	}

	float BreakerConfig::getFrequencies(){
		return this->_frequencies;
	}

	void BreakerConfig::setEpsilon(float e){
		this->_epsilon = e;
	}

	float BreakerConfig::getEpsilon(){
		return this->_epsilon;
	}

	bool BreakerConfig::areParamReady(){
		printf("Testing parameters\n");
		if ( (this->_text_file.length() > 0)
				/* && (this->_frequencies_file.length() > 0) */
				&& (this->_priorities_file.length() > 0)
				&& (this->_alphabet_file.length() > 0)
				&& (this->_epsilon > 0) && (this->_epsilon < 1)
		   ) { 
			printf("Param OK !\n");
			return true; }
		else {
			return false;
		}
	}

	void BreakerConfig::loadFiles(){
		FileLoader filo;
		printf("Loading alphabet..."); fflush(stdout);
		this->_alphabet = filo.loadAlphabet(this->_alphabet_file);
		printf("Building reverse alphabet...\n"); fflush(stdout);
		this->_reverse_alphabet = this->_alphabet.getReverse();
		printf("Loading text..."); fflush(stdout);
		this->_text = filo.loadText(this->_reverse_alphabet,
				this->_text_file);
		printf("Loading priorities..."); fflush(stdout);
		this->_priorities = filo.loadPriorities(this->_reverse_alphabet,
				this->_priorities_file);
		//printf("Loading frequencies..."); fflush(stdout);
		//this->_frequencies = filo.loadFrequencies(
		//		this->_reverse_alphabet,
		//		this->_frequencies_file);
	}

	void BreakerConfig::setTextFile(std::string filename){
		if (filename.length()<1){
			printf("Error: incorrect text file name '%s'",filename.c_str());
		} else {
			printf("Text file = %s\n", filename.c_str());
			this->_text_file = filename;
		}
	}

	std::string BreakerConfig::getTextFile(){
		return this->_text_file;
	}

	void BreakerConfig::setAlphabetFile(std::string filename){
		if (filename.length()<1){
			printf("Error: incorrect alphabet file name '%s'",filename.c_str());
		} else {
			printf("Alphabet file = %s\n", filename.c_str());
			this->_alphabet_file = filename;
		}
	}

	std::string BreakerConfig::getAlphabetFile(){
		return this->_alphabet_file;
	}

	/*
	   void BreakerConfig::setFrequenciesFile(std::string filename){
	   if (filename.length()<1){
	   printf("Error: incorrect frequencies file name '%s'",filename.c_str());
	   } else {
	   printf("Frequencies file = %s\n", filename.c_str());
	   this->_frequencies_file = filename;
	   }
	   }*/

	/* std::string BreakerConfig::getFrequenciesFile(){
	   return this->_frequencies_file;
	   } */

	void BreakerConfig::setPrioritiesFile(std::string filename){
		if (filename.length()<1){
			printf("Error: incorrect priorities file name '%s'",filename.c_str());
		} else  {
			printf("Priorities file = %s\n", filename.c_str());
			this->_priorities_file = filename;
		}
	}

	std::string BreakerConfig::getPrioritiesFile(){
		return this->_priorities_file;
	}

	void BreakerConfig::setKeyLength(int len){
		if (len < 1){
			printf("Error: incorrect key length '%d'",len);

		} else {
			printf("Key length = %d\n", len);
			this->_key_length = len;
		}
	}

	Text BreakerConfig::getText(){
		return this->_text;
	}

	std::vector<int> BreakerConfig::getPriorities(){
		return this->_priorities;

		/*
		   std::list<TextCounter> result;
		   std::map<int,int>::iterator prioIt;

		   for (prioIt = this->_priorities.begin(); 
		   prioIt != this->_priorities.end();
		   prioIt++){
		   TextCounter tc;

		   result.push_back(tc);	//FIXME: fill the tc	
		   }
		   return result;*/
	}

}
