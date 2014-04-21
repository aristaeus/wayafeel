#ifndef PHONEME_HPP
#define PHONEME_HPP

#include <string>
#include <vector>

namespace tk{

	class phoneme{
		std::string p;
		static std::vector<std::string> phonemes;
		static std::vector<std::vector<std::string>> pronounce;
	    public:
		static phoneme get_phoneme(tk::random& rand);
		static phoneme get_phoneme(tk::random& rand, tk::phoneme p);
		static void set_phonemes();

		phoneme(std::string s);

		std::string get();
	};
}

#endif
