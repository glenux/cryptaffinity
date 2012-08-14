
#include "math_tools.hh"

#define DEBUG 1

namespace LibCryptAffinity {
	
	int MathTools::pgcd(int a, int b){
		int fa = a;
		int fb = b;
		int pgcd;
		int rest;
		int tmp;

		while(b > 0){
			if (a<b){ tmp = a; a=b; b=tmp; }

			rest = a%b;
			//pDEBUG("MathTools::pgcd","%d - %d -> %d\n", a,b,rest);
			a = b;
			b = rest;
		}
			pDEBUG("MathTools::pgcd","%d - %d -> %d\n", fa,fb,a);
		return a;
	}

	int MathTools::ppcm(int a, int b){
	}

	
	std::vector<int> MathTools::pgcd_real(int * reste, int * quotient, int * coef_first, int * coef_second, int pas){
		std::vector<int> result;
		int nreste = reste[0] % reste[1];	
		int nquotient;
		int ncf, ncs; // coef first , coef sec

		if (nreste == 0){
			result.push_back(reste[1]);
			if (pas % 2 == 0) { 
				result.push_back(coef_first[1]);
				result.push_back(-coef_second[1]);
			} else {
				result.push_back(-coef_first[1]);
				result.push_back(coef_second[1]);
			}
			return result;
		} else {
			nquotient = reste[1] / nreste;
			ncf = quotient[1] * coef_first[1] + coef_first[0];
			ncs = quotient[1] * coef_second[1] + coef_second[0];
			
			reste[0] = reste[1];
			reste[1] = nreste;
			
			quotient[0] = quotient[1];
			quotient[1] = nquotient;
			
			coef_first[0] = coef_first[1];
			coef_first[1] = ncf;

			coef_second[0] = coef_second[1];
			coef_second[1] = ncs;
			
			return pgcd_real(reste, quotient, coef_first, coef_second, pas+1);
		}
	}

	std::vector<int> MathTools::pgcd_mod(int a, int b){
		int reste[2];
		int quotient[2];
		int coef_first[2];
		int coef_second[2];
		int i;
		
		//init
		reste[0] = a;
		reste[1] = b;

		quotient[0] = 0;
		quotient[1] = a / b;

		coef_first[0] = 1;
		coef_first[1] = 0;

		coef_second[0] = 0;
		coef_second[1] = 1;
		
		return this->pgcd_real(reste, quotient, coef_first, coef_second, 1);
	}

	int MathTools::inverse(int a, int modulo){ 
		std::vector<int> pgcd_vec;
		int ca, cm, cpgcd;
		pgcd_vec = this->pgcd_mod(a, modulo);

		ca = pgcd_vec[1];
		cm = pgcd_vec[2];
		cpgcd = pgcd_vec[0];
		
		if (cpgcd != 1) {
			// crash
			pDEBUG("MathTools::inverse","CRASHHHHHH");	
		} else {
			while (ca < 0){
				ca = (ca + modulo);
			}
			// ca est positif;
			ca = ca % modulo;
		}
		return ca;
	}
}

#undef DEBUG
