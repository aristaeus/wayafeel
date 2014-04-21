#include <string>
#include <fstream>
#include <vector>
#include <iostream>
#include "grapheme.hpp"
#include "random.hpp"

std::vector<std::vector<std::string>> tk::grapheme::graphemes;
std::vector<std::string> tk::grapheme::phonemes;

void tk::grapheme::set_graphemes(){
	std::ifstream phoneme_file("./data/phonemes", std::ios::in);
	if(!phoneme_file.is_open()) std::cout << "Phonemes not found.\n";

	std::string line;

	while(std::getline(phoneme_file, line)){
		phonemes.push_back(line);
		std::ifstream file("./data/grapheme/"+line, std::ios::in);
		if(!file.is_open()) std::cout << line << " not found.\n";

		std::vector<std::string> vec;
		std::string var;

		while(std::getline(file, var)) vec.push_back(var);
		graphemes.push_back(vec);

		file.close();
	}

	phoneme_file.close();
}

std::string tk::grapheme::phoneme(tk::phoneme p, tk::random& rand){
	for(int i = 0; i < phonemes.size(); i++){
		if(phonemes[i] == p.get()){
			return graphemes[i][rand(0,graphemes[i].size()-1)];
		}
	}
}
