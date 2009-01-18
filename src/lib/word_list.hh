#ifndef _CRYPTAFINIY_WORDLIST_HH
#define _CRYPTAFINIY_WORDLIST_HH

#include <map>
#include "text.hh"

namespace LibCryptAfinity {
	class WordList {
		private:
			std::map<Text, int>  _word2int; // existance du mot
			std::map<int, TextCounter> _letter2wordnref;

		public:
			// texte, reference dans le texte global, longueur
			void addWord(Text t, int ref, int len); 

			// retourne les mots qui contiennent le caractere choisi
			std::map<Text,int> getWordsContaining(int val);
	};
}
#endif
