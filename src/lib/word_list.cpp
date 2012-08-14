
#include "word_list.hh"

namespace LibCryptAffinity {
	std::map<Text,int> WordList::getWordsContaining(int value){
		std::map<Text,int> result;
		std::map<int, TextCounter>::iterator foundVal;
		while ((foundVal = this->_letter2wordnref.find(value)) 
				!= this->_letter2wordnref.end()) {
			printf("Ajouter mot/ref aux result\n");
		}
		return result;
	}

	void WordList::addWord(Text t, int ref, int len){
		int i;
		printf("addWord %s : %d : %d -> ", t.toString().c_str(), ref, len);
		fflush(stdout);
		std::map<Text, int>::iterator foundVal;
		foundVal = this->_word2int.find(t);
		// 1- verifier que le mot n'existe pas déja
		//    s'il existe, abandonner
		if (foundVal != this->_word2int.end()){
			printf("old\n");
			// le mot existe déja, on laisse tomber alors; 
		} else {
			printf("new\n");
			// le mot n'existe pas, on l'ajoute alors...
			this->_word2int[t]=1;
			
			// 2- pour toute lettre du mot, créer l'association
			//    lettre => (mot, position_dans_le_mot);
			for (i=0; i<t.size(); i++){
				TextCounter tc;
				tc.setText(t);
				tc.setCount(i);
				printf("    + %d -> (%s, %d)\n", t[i], t.toString().c_str(), i);
				this->_letter2wordnref[t[i]]=tc;
			}
		}
	}
}
