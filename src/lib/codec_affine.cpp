
#include "codec_affine.hh"
#include "math_tools.hh"

namespace LibCryptAffinity {
	CodecAfine::CodecAfine() : Codec() {
	}

	Text CodecAfine::decode(Text cypher, KeyAfine key){
		Text result = cypher;
		MathTools mt;
		int i;
		for (i=0; i<cypher.size(); i++){
			// A must be the inverse of the real coefficient
			result[i] = (mt.inverse(key.getCoefA(), cypher.getAlphabet().size()) * (cypher[i] + cypher.getAlphabet().size() - key.getCoefB())) 
				% cypher.getAlphabet().size();
		}
		return result;
	}

	Text CodecAfine::encode(Text plain, KeyAfine key){
		Text result = plain;
		int i;
		for (i=0; i<plain.size(); i++){
			result[i] = (plain[i] * key.getCoefA() + key.getCoefB()) % plain.getAlphabet().size();
		}
		return result;
	}
}
