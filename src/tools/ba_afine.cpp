
#include <math.h>
#include "ba_cmd.hh"

#define DEBUG 1

namespace BreakAfinity {

	void BreakAfinity::runAfine(){
		MathTools mt;
		CodecAfine codec;
		FreqAnalyser fa;
		Text cypherText = this->_config.getText();
		Text plainText;
		int i;
		std::list<TextCounter> tc;
		cypherText.setAlphabet(this->_config.getAlphabet());
		int alpha_size = this->_config.getAlphabet().size();
		std::vector<int> prio_conf = this->_config.getPriorities();

		// générer l'orbite de 26
		std::list<int> orb;
		for (i=1; i<alpha_size; i++){
			if (mt.pgcd(i, alpha_size) == 1) {
				orb.push_back(i);
			}
		}
		
		// 1 - générer l'espace des 312 clefs
		std::list<KeyAfine> keyList;
		std::list<int>::iterator orbIt;

		for (orbIt = orb.begin(); orbIt != orb.end(); orbIt++){
			KeyAfine key;
			key.setCoefA((*orbIt));
			for (i=0; i<alpha_size; i++){
				key.setCoefB(i);
				keyList.push_back(key);
			}
		}
		// on a la liste des clefs...
		// on va tester les frequences...
		std::list<KeyAfine>::iterator kLIt;
		for (kLIt = keyList.begin(); kLIt != keyList.end(); kLIt++){

			float score = 0;
			printf("Trying key %s\n", (*kLIt).toString().c_str());

			plainText = codec.decode(cypherText, *kLIt);	
			plainText.setAlphabet(this->_config.getAlphabet());
			for (int i=0; i<9; i++){
				score += plainText.getCountOf(prio_conf[i]);
			}
			score = score / plainText.size();
			if (fabs(score - this->_config.getFrequencies()) < this->_config.getEpsilon()){
				printf("   KEY = %s\n",(*kLIt).toString().c_str());
				printf("   PLAIN TEXT(%f) = %s\n",fabs(score-0.7),plainText.toAlphabet().c_str());
			}

		}
		
		return ;
	}
}

#undef DEBUG
