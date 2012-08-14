#ifndef _LIBCRYPAFFINITY_TEXT_HH
#define _LIBCRYPAFFINITY_TEXT_HH

#include "cryptaffinity_global.hh"
#include "cryptaffinity_iface.hh"

#include "alphabet.hh"

namespace LibCryptAffinity {
	class TextCounter;
	
	class Text : public std::vector<int> {
		private:
			Alphabet _alphabet;
			ReverseAlphabet _reverse_alphabet;

		public:
			Text();
			Text(Alphabet alphabet);
			
			void setAlphabet(Alphabet alpha);
			Alphabet getAlphabet();

			// on considere le texte comme
			void append(std::string str);	
			Text substr(int start, int len);
			std::string toString();
			std::string toAlphabet();

			int getCountOf(int c);
			std::list<TextCounter> getRepeatedPatterns();
	};

	class TextCounter {
		private:
		Text _text;
		int _count;
		std::list<int> _param;
		
		public:
			void setText(Text t);
			Text getText();

			void setCount(int c);
			int getCount();

			void setParam(std::list<int> param);
			std::list<int> getParam();

			bool operator< (TextCounter b);
	};

}

#endif

