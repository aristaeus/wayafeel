#include <iostream>
#include <vector>
#include <string>
#include "random.hpp"
#include "phoneme.hpp"
#include "grapheme.hpp"

int main(int argc, char* argv []){
	int seed;
	tk::random rand;
	
	if(argc < 2){		// If a seed was not provided.
		std::cout << "Enter seed (enter 0 for a random seed): ";
		std::cin >> seed;
		if (seed != 0) rand.set_seed(seed);		// Set the seed.
	} else {		// If a seed was provided.
		seed = *argv[1] - 48;
		for(int i = 1; argv[1][i] != '\0'; i++){
			seed *= 10;
			seed += argv[1][i] - 48; 
		}
		rand.set_seed(seed);		// Set the seed.
	}
	
	std::cout << "Seed: " << rand.get_seed() << std::endl;

	const int length = rand(2,10);		// Print the length in phonemes of the word.
	std::cout << "Length: " << length << std::endl << "Phoneme: ";

	tk::phoneme::set_phonemes();		// Load the phoneme files.
	tk::grapheme::set_graphemes();		// Load the grapheme files.

	std::vector<tk::phoneme> word;		// Get the first phoneme.
	word.push_back(tk::phoneme::get_phoneme(rand));
	std::cout << "/" << word[0].get();


	for(int i = 1; i < length; i++){	// Get the remaining phonemes.
		word.push_back(tk::phoneme::get_phoneme(rand, word[i-1]));
		std::cout << "/" << word[i].get();
	}
	std::cout << "/\n";

	std::cout << "Grapheme: ";

	for(int i = 0; i < length; i++){	// Print the word in graphemes.
		std::cout << tk::grapheme::phoneme(word[i], rand);
	}
	std::cout << std::endl;

	return 0;
}

