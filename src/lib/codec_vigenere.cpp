
#include "codec_vigenere.hh"

namespace LibCryptAfinity {
	CodecVigenere::CodecVigenere() : Codec() {
	}

	Text CodecVigenere::decode(Text t, KeyVigenere k){
		Text result = t;
		int txt_idx;
		int key_idx;
		int i;
		int alpha_size = t.getAlphabet().size();
		for (txt_idx=0; txt_idx<t.size(); txt_idx+=k.size()){
			for (key_idx = 0; key_idx < k.size(); key_idx++) {
				i = txt_idx + key_idx;
				if (i < t.size()){
					int cypher = result[i];
					int key = k[key_idx];
					int plain = (cypher + alpha_size - key) % (alpha_size);
					result[i] = plain;
				}
			}
			
		}
		return result;
	}

	Text CodecVigenere::encode(Text t, KeyVigenere k){
		Text result;
		int txt_idx;
		int key_idx;
		int i;
		int alpha_size = t.getAlphabet().size();
		for (txt_idx=0; txt_idx<t.size(); txt_idx+=k.size()){
			for (key_idx = 0; key_idx < k.size(); key_idx++) {
				i = txt_idx + key_idx;
				if (i < t.size()){
					int plain = result[i];
					int key = k[key_idx];
					int cypher = (plain + key) % (alpha_size);
					result[i] = cypher;

				}
			}
			
		}
		return result;
	}

}
