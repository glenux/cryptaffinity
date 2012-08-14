
#include "text.hh"

#define DEBUG 0
namespace LibCryptAffinity {
	bool TextCounter::operator< (TextCounter b){
		fflush(stdout);
		if (this->_text.size() < b.getText().size()){
			return true;
		} else if (this->_text.size() == b.getText().size()) {
			// cas de l'egalité des tailles
			if (this->_count < b.getCount()){
				return true;
			} else {
				return false;
			}
		} else { 
			// cas du suppérieur
			return false;
		}
	}
	void TextCounter::setText(Text t){
		this->_text = t;
	}
			
	int Text::getCountOf(int c){
		int counter =0;
		int i;
		for (i=0; i<this->size(); i++){
			if ((*this)[i] == c) {
				counter++;
			}
		}
		return counter;
	}

	Text TextCounter::getText(){
		return this->_text;
	}

	void TextCounter::setCount(int i){
		this->_count = i;
	}

	int TextCounter::getCount(){
		return this->_count;
	}

	void TextCounter::setParam(std::list <int> param){
		this->_param = param;
	}

	std::list<int> TextCounter::getParam(){
		return this->_param;
	}

	Text::Text(Alphabet alphabet) : std::vector<int>() , _alphabet(alphabet) {
		// vide au début
	}

	Text::Text() : std::vector<int>() {
		// vide au début
	}

	void Text::setAlphabet(Alphabet alpha) {
		this->_alphabet = alpha;
	}

	Alphabet Text::getAlphabet() { return this->_alphabet; }

	void Text::append(std::string str){
	}

	std::list<TextCounter> Text::getRepeatedPatterns(){
		// on découpe en patterns de 2 à texte / 3
		std::list<TextCounter> result;
		int patternsize;
		int txt_idx;
		int pat_idx;
		bool pattern_active;
		bool * active = new bool[this->size()];
		for (txt_idx=0; txt_idx < this->size(); txt_idx++){
			active[txt_idx] = true;	
		}

		pDEBUG("Text::getRepeatedPatterns","getRepeatedPatterns\n");
		int max_patternsize = (this->size() / 3);
		for (patternsize=max_patternsize; patternsize>1; patternsize--){
			std::map<Text, int> counter;
			std::map<Text, std::list<int> > referencer;
			for (txt_idx = 0; txt_idx < this->size()-patternsize; txt_idx++){
				pattern_active = true;
				Text currentword;
				for (pat_idx = 0; pat_idx<patternsize; pat_idx++){
					if (!active[txt_idx+pat_idx]){ pattern_active=false; }
					currentword.push_back((*this)[txt_idx+pat_idx]);
				}
				if (pattern_active){
					if (counter.find(currentword) == counter.end()){
						//printf("    + defining new word..."); fflush(stdout);
						counter[currentword] = 1;
						referencer[currentword].push_back(txt_idx);
						//printf(" done.\n");
					} else {
						counter[currentword] = counter[currentword]+1;
						referencer[currentword].push_back(txt_idx);
						pDEBUG("Text::getRepeatedPatterns","patternsize = %d , incrementing word %s to %d at %d ...",
								patternsize, 
								currentword.toString().c_str(),
								referencer[currentword].size(),
								txt_idx); 
						fflush(stdout);
						// on désactive les case trouvées
						std::list<int> refs = referencer[currentword];
						std::list<int>::iterator refsIt;
						for(refsIt=refs.begin(); refsIt!=refs.end(); refsIt++){
							for (pat_idx=0; pat_idx<patternsize; pat_idx++){
								// printf("deactivating %d\n",(*refsIt)+pat_idx);
								active[(*refsIt)+pat_idx]=false;
							}
						}
						if (DEBUG) { printf(" done.\n"); }
					}
				} // end "if pattern_active
			}

			// pour chaque mots ajouté,
			std::map<Text, int>::iterator counterIt;
			for (counterIt=counter.begin();
					counterIt!=counter.end();
					counterIt++){
				// si la freq est > 1; on l'ajoute a la liste des
				// mots doublons, avec la freq...
				if (counterIt->second > 1) {
					TextCounter tc;
					tc.setText(counterIt->first);
					tc.setCount(counterIt->second);
					tc.setParam(referencer[counterIt->first]);
					result.push_back(tc);
				}
			}
		}
		printf("out\n");
		result.sort();
		result.reverse();
		return result;
	}

	Text Text::substr(int index, int len){
		Text result;
		int i;
		for (i=index; i<index+len; i++){
			result.push_back((*this)[i]);
		}
		return result;
	}

	std::string Text::toAlphabet(){
		int i;
		std::string s;
		s+="<< ";
		char * c = new char[1024];
		for (i=0; i<this->size(); i++){
			s+=this->_alphabet[(*this)[i]];
		}
		free(c);
		s+=">>";
		return s;
	}

	std::string Text::toString(){
		int i;
		std::string s;
		s+="[ ";
		char * c = new char[1024];
		for (i=0; i<this->size(); i++){
			sprintf(c, "%d ", (*this)[i]);
			s+=c;
		}
		free(c);
		s+="]";
		return s;
	}
}

#undef DEBUG
