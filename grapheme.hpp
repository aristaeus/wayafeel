#ifndef GRAPHEME_HPP
#define GRAPHEME_HPP

#include <string>
#include <vector>
#include "random.hpp"
#include "phoneme.hpp"

namespace tk{

	class grapheme {
		static std::vector<std::vector<std::string>> graphemes;	// Contains graphemes for each phoneme.
		static std::vector<std::string> phonemes;		// List of phonemes.
	    public:
		static void set_graphemes();	// Populates vectors.
		static std::string phoneme(tk::phoneme p, tk::random& rand);	// Selects a random grapheme for phoneme p.
	};

}

#endif
