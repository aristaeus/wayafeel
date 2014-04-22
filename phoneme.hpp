#ifndef PHONEME_HPP
#define PHONEME_HPP

#include <string>
#include <vector>

namespace tk{

	class phoneme{
		std::string p;
		static std::vector<std::string> phonemes;	// Vector of phonemes
		static std::vector<std::vector<std::string>> pronounce;		// Each vector correlates to a particular phoneme, and each element is a pronounceable phoneme that can follow that phoneme.
	    public:
		static phoneme get_phoneme(tk::random& rand);	// Returns a random phoneme.
		static phoneme get_phoneme(tk::random& rand, tk::phoneme p);	// Returns a random phoneme that can come after p.
		static void set_phonemes();	// Initialises the class.

		phoneme(std::string s);		// Constructor. s is a phoneme.

		std::string get();		// Returns the phoneme.
	};
}

#endif
