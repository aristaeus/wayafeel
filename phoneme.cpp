#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include "random.hpp"
#include "phoneme.hpp"

std::vector<std::string> tk::phoneme::phonemes;
std::vector<std::vector<std::string>> tk::phoneme::pronounce;

tk::phoneme::phoneme(std::string s = "null"){
	p = s;
}

void tk::phoneme::set_phonemes(){
	std::ifstream phoneme_file("./data/phonemes", std::ios::in);
	if(!phoneme_file.is_open()) std::cout << "Phonemes not found.\n";

	std::string line;

	while(std::getline(phoneme_file, line)){
		phonemes.push_back(line);
		std::ifstream file("./data/phoneme/"+line, std::ios::in);
		if(!file.is_open()) std::cout << line << " not found.\n";

		std::vector<std::string> vec;
		std::string var;

		while(std::getline(file, var)) vec.push_back(var);
		pronounce.push_back(vec);

		file.close();
	}

	phoneme_file.close();
}
tk::phoneme tk::phoneme::get_phoneme(tk::random& rand){
	return tk::phoneme(phonemes[rand(0,phonemes.size())]);
}

tk::phoneme tk::phoneme::get_phoneme(tk::random& rand, tk::phoneme p){
	//return tk::phoneme::get_phoneme(rand);
	std::string var;
	while(true){
		var = phonemes[rand(0,phonemes.size())];
		for(int i = 0; i < phonemes.size(); i++){
			if(phonemes[i] == p.get()){
				for(int j = 0; j < pronounce[i].size(); j++){
					if(pronounce[i][j] == var){
						return tk::phoneme(var);
					}
				}
			}
		}
	}
}

std::string tk::phoneme::get(){
	return this->p;
}
