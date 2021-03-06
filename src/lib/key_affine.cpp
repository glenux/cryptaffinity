
#include "key_affine.hh"

#include "cryptaffinity_global.hh"
#include "cryptaffinity_iface.hh"

namespace LibCryptAffinity {
	
	int KeyAfine::getCoefA(){
		return this->_a;
	}
	int KeyAfine::getCoefB(){
		return this->_b;
	}

	void KeyAfine::setCoefA(int i){
		this->_a = i;
	}

	void KeyAfine::setCoefB(int i){
		this->_b = i;
	}

	std::string KeyAfine::toString(){
		std::string s;
		s="( ";
		char * c= new char[200];
		sprintf(c,"%d",this->_a);
		s+=c;
		s+=", ";
		sprintf(c,"%d",this->_b);
		s+=c;
		s+=")";
		
		return s;
	}
}

