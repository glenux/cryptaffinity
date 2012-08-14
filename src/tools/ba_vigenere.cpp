
#include <math.h>
#include "ba_cmd.hh"

#define DEBUG 0

namespace BreakAffinity {

	void BreakAffinity::runVigenere(){
		MathTools mt;
		CodecVigenere codec;
		FreqAnalyser fa;
		Text cypherText = this->_config.getText();
		Text plainText;
		std::list<TextCounter> tc;
		cypherText.setAlphabet(this->_config.getAlphabet());
		int alpha_size = this->_config.getAlphabet().size();

		// 1 - repérer les mots qui se répentent
		pDEBUG("BreakAffinity::run","analysing %s\n",cypherText.toString().c_str());
		KeyVigenere key;
		TextCounter fst;
		TextCounter sec;
		int dist1, dist2;
		int fst_idx1, fst_idx2;
		int sec_idx1, sec_idx2;
		int key_len;
		int key_idx;

		tc = cypherText.getRepeatedPatterns();

		fst = tc.front();
		tc.pop_front();
		sec = tc.front();

		std::list<int> fst_idx = fst.getParam();
		std::list<int> sec_idx = sec.getParam();

		fst_idx1 = fst_idx.front();
		fst_idx.pop_front();
		fst_idx2 = fst_idx.front();

		sec_idx1 = sec_idx.front();
		sec_idx.pop_front();
		sec_idx2 = sec_idx.front();

		dist1 = fst_idx2 - fst_idx1;
		dist2 = sec_idx2 - sec_idx1;

		// 2 - on en déduit la longueur de la clef
		key_len = mt.pgcd(dist1,dist2);
		pDEBUG("BreakAffinity::run","PGCD(%d, %d) = %d\n", dist1, dist2, key_len);

		// 3 - on calcule le décalage par colonne
		std::list<TextCounter>::iterator pI;
		std::vector<int> prio_conf = this->_config.getPriorities();

		for (int i=0; i< prio_conf.size(); i++){
			printf("%d - ",prio_conf[i]);
		}
		printf("\n");
		std::list<KeyVigenere> keyList;
		std::list<KeyVigenere>::iterator lI;

		for (key_idx = 0; key_idx < key_len; key_idx++){
			std::list<TextCounter> prio_list;
			TextCounter firstCypherTC, firstPlainTC;
			int firstCypher, firstPlain;
			int shift;
			prio_list = fa.getPriorities(cypherText, key_len, key_idx); 

			firstCypherTC = prio_list.front();
			firstCypher = firstCypherTC.getText()[0];

			std::list<KeyVigenere> nList;
			for (int i=0; i<2; i++){
				firstPlain = prio_conf[i];
				//printf("Shift column %d from %d to %d\n",
				//key_idx, 
				//firstCypher, 
				//firstPlain);
				//
				// on fixe le décalage a partir de la premiere priorité...
				shift = (alpha_size + firstCypher - firstPlain) % alpha_size; 
				// Cypher = Plain + Key => Key = Cypher - Plain
				if(key_idx==0){ 
					KeyVigenere kv;
					kv.push_back(shift);
					nList.push_back(kv);
				} else {
					for (lI=keyList.begin(); lI!=keyList.end(); lI++){
						KeyVigenere kv=*lI;
						//printf("From %s ",kv.toString().c_str());
						kv.push_back(shift);
						//printf("creating %s\n",kv.toString().c_str());
						nList.push_back(kv);
					}
				}
			}
			keyList.clear();
			for (lI=nList.begin(); lI!=nList.end(); lI++){
				keyList.push_back((*lI));
			}
		}
		// on filtre en fonction des 70%...
		for (lI=keyList.begin(); lI!=keyList.end(); lI++){
			float score = 0;
			key = (*lI);
			printf("Trying key %s\n", key.toString().c_str());

			plainText = codec.decode(cypherText, key);
			plainText.setAlphabet(this->_config.getAlphabet());
			for (int i=0; i<9; i++){
				score += plainText.getCountOf(prio_conf[i]);
			}
			score = score / plainText.size();
			if (fabs(score - this->_config.getFrequencies()) < this->_config.getEpsilon()){
				key.setAlphabet(this->_config.getAlphabet());
				printf("   KEY = %s\n",key.toAlphabet().c_str());
				printf("   PLAIN TEXT(%f) = %s\n",fabs(score-0.7),plainText.toAlphabet().c_str());
			}

		}	
		return ;
	}
}

#undef DEBUG
