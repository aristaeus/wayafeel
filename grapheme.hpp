#ifndef GRAPHEME_HPP
#define GRAPHEME_HPP

#include <string>
#include <vector>
#include "random.hpp"
#include "phoneme.hpp"

namespace tk{

	class grapheme {
		static std::vector<std::vector<std::string>> graphemes;
		static std::vector<std::string> phonemes;
	    public:
		static void set_graphemes();
		static std::string phoneme(tk::phoneme p, tk::random& rand);
	};

}

#endif
