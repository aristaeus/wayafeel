#ifndef RANDOM_HPP
#define RANDOM_HPP

#include <random>

namespace tk{
	class random{
		std::default_random_engine engine;
		std::random_device rd;
		std::uniform_int_distribution<int>* distribution;
	    public:
		random();
		int operator()(int low, int high);
		void seed(int seed);
	};
}

#endif
