
#include "file_loader.hh"

using namespace LibCryptAfinity;

namespace BreakAfinity {
	std::vector<int> FileLoader::loadPriorities(
			std::map<std::string, int> reverse_alpha, 
			std::string filename){

		std::vector<int> result;
		std::vector<std::string> file;
		int i;
		file = this->loadFile(filename);
		printf("PRIORITIES = "); fflush(stdout);
		for (i=0; i<file.size(); i++){
			printf("%d->%s ", i, file[i].c_str());
			result.push_back(reverse_alpha[file[i]]); //]=i;
		}
		printf("\n");
		return result;
	}

	std::map<int, float> FileLoader::loadFrequencies(
			std::map<std::string, int> reverse_alpha, 
			std::string filename){
		std::map <int, float> result;
		std::vector<std::string> file;
		int i;
		file = this->loadFile(filename);
		printf("FREQUENCIES = "); fflush(stdout);
		for (i=0; i<file.size(); i++){
			printf("%s ", file[i].c_str());
		}
		printf("\n");
		return result;
	}

	std::vector<std::string> FileLoader::loadFile(std::string filename){
		gchar * contentc;
		gsize length;
		GError *error = NULL;
		std::vector<std::string> result;
		std::string contents;
		std::string sub;
		int lf_idx;
		g_file_get_contents(filename.c_str(),
				&contentc,
				&length,
				&error);
		contents = contentc;
		while((lf_idx = contents.find("\n")) != std::string::npos){
			sub = contents.substr(0, lf_idx);	
			//printf("%s",sub.c_str());

			contents.erase(0,lf_idx+1);	
			result.push_back(sub);
		}
		return result;
	}

	Alphabet FileLoader::loadAlphabet(std::string filename){
		std::vector<std::string> file;
		Alphabet result;
		file = this->loadFile(filename);
		int i;
		printf("ALPHABET = "); fflush(stdout);
		for (i=0; i<file.size(); i++){
			printf("%s",file[i].c_str());
			result.push_back(file[i]);
		}
		printf("\n");
		return result;
	}

	Text FileLoader::loadText(
			std::map<std::string,int> reverse_alpha,
			std::string filename){
		Text result;	
		std::vector<std::string> file;
		int i;
		int txtidx;
		file = this->loadFile(filename);
		printf("TEXT = "); fflush(stdout);
		for (i=0; i<file.size(); i++){
			printf("%s",file[i].c_str());
			std::string s = file[i];
			for (txtidx = 0; txtidx< s.length(); txtidx++){
				std::string letter;
				letter += s[txtidx];
				result.push_back(reverse_alpha[letter]);
			}
		}
		printf("\n");
		return result;
	}
}
