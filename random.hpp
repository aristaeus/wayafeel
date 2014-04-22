#ifndef RANDOM_HPP
#define RANDOM_HPP

// v 0.1

#include <random>

namespace tk{
	class random{
		std::default_random_engine engine;
		std::random_device rd;
		int seed;
		std::uniform_int_distribution<int>* distribution;
	    public:
		random();
		int operator()(int low, int high);
		void set_seed(int s);
		int get_seed(){ return seed; };
	};
}

#endif
