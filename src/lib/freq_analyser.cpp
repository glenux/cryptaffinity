

#include "freq_analyser.hh"

#define DEBUG 0

namespace LibCryptAffinity {
	std::list<TextCounter> FreqAnalyser::getPriorities(Text text, int keylen, int column){
		std::list<TextCounter> result;
		std::map<Text, int> counter;
		std::map<Text, int>::iterator countIt;
		int i;
		for (i=0; i<text.size();  i += keylen) {
			Text letter;
			letter.push_back(text[i+column]);
			if (counter.find(letter) == counter.end()){
				counter[letter] = 1;
			} else {
				counter[letter] = counter[letter] + 1;
			}
		}
		// on relit le map et on crée la liste...
		pDEBUG("FreqAnaliser","Column %d\n", column);
		for (countIt = counter.begin(); countIt != counter.end(); countIt++){
			TextCounter tc;

			tc.setText(countIt->first);
			tc.setCount(countIt->second);
			pDEBUG("FreqAnalyser","    Letter %s found %d times\n",tc.getText().toString().c_str(), tc.getCount());
			result.push_back(tc);
		}
		result.sort();
		result.reverse();
		return result;
	}
}
