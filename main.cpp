#include <iostream>
#include <vector>
#include <string>
#include "random.hpp"
#include "phoneme.hpp"
#include "grapheme.hpp"

int main(){
	int seed;
	std::cout << "Enter seed (enter -1 for a random seed): ";
	std::cin >> seed;
	
	tk::random rand;
	if (seed > 0) rand.seed(seed);
	const int length = rand(2,10);
	std::cout << "Length: " << length << std::endl << "Phoneme: ";

	tk::phoneme::set_phonemes();
	tk::grapheme::set_graphemes();

	std::vector<tk::phoneme> word;
	word.push_back(tk::phoneme::get_phoneme(rand));
	std::cout << "/" << word[0].get();


	for(int i = 1; i < length; i++){
		word.push_back(tk::phoneme::get_phoneme(rand, word[i-1]));
		std::cout << "/" << word[i].get();
	}
	std::cout << "/\n";

	std::cout << "Grapheme: ";

	for(int i = 0; i < length; i++){
		std::cout << tk::grapheme::phoneme(word[i], rand);
	}
	std::cout << std::endl;

	return 0;
}
