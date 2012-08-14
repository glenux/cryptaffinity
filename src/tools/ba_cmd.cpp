
#include <math.h>
#include "ba_cmd.hh"

#define DEBUG 0

namespace BreakAffinity {
	BreakAffinity::BreakAffinity(){
		// on fixe la config par defaut
		int i;
		i=i+1;
	}

	void BreakAffinity::loadFiles(){
		printf("ALIVE !!!\n");
		this->_config.loadFiles();
		printf("ALIVE ???\n");
	}

	void BreakAffinity::init(int argc, char **argv) {
		int i;

		for (i = 1; i + 1 < argc; i = i + 2){
			char * opt = argv[i]; //GOOD
			char * val = argv[i+1]; //GOOD
			if ( (strcmp(opt, "--alphabet") == 0) || (strcmp(opt,"-a") == 0) ){
				this->_config.setAlphabetFile(val);
				continue;
			}
			if ( (strcmp(opt, "--epsilon") == 0) || (strcmp(opt,"-e") == 0) ){
				this->_config.setEpsilon(atof(val));
				continue;
			}
			if ( (strcmp(opt, "--priorities") == 0) || (strcmp(opt,"-p") == 0) ){
				this->_config.setPrioritiesFile(val);
				continue;
			}
			if ( (strcmp(opt, "--frequencies") == 0) || (strcmp(opt,"-f") == 0) ){
				this->_config.setFrequencies(atof(val)); //File(val);
				continue; 
			}
			if ( (strcmp(opt, "--text") == 0) || (strcmp(opt,"-t") == 0) ){
				this->_config.setTextFile(val);
				continue; 
			}
			if ( (strcmp(opt, "--mode") == 0) || (strcmp(opt,"-m") == 0) ){
				this->_config.setMode(val);
				continue; 
			}
			/*
			   printf("Option = %s, ",argv[i]);
			   printf("value = %s\n",argv[i+1]);		
			   */
		}	

		if (!this->_config.areParamReady())
		{
			printf("\nUsage: %s <options>\n", argv[0]);
			printf("\nWhere options could be:\n");
			printf("-a, --alphabet <file>      Letters ordered by decreasing frequency\n");
			printf("-e, --epsilon <float>      Tolerance for the final key test\n");
			printf("-f, --frequencies <float>  Average frequencies for the 9 first letters\n");
			printf("-m, --mode ( v | a )       Choose the kind of cypher : vigenere or affine.\n");
			printf("-p, --priorities <file>    Letters ordered by decreasing frequency\n");
			printf("-t, --text <file>          Cipher text to decipher\n");
			//printf("-s, --popsize <int>      Population size in each generation\n");

			exit(-1);
		} else {
			printf("continuing...");
		}
	}

	void BreakAffinity::run(){
		// vigenere ou affine ?
		MathTools mt;
		CodecVigenere codec;
		FreqAnalyser fa;
		Text cypherText = this->_config.getText();
		Text plainText;
		std::list<TextCounter> tc;
		cypherText.setAlphabet(this->_config.getAlphabet());
		int alpha_size = this->_config.getAlphabet().size();
		printf("Alive ==\n");
		if (this->_config.isModeVigenere()){
			printf("Selecting Vigenere mode\n");
			this->runVigenere();
		} else {
			printf("Selecting Afine mode\n");
			this->runAfine();
		}
	}
}

#undef DEBUG
