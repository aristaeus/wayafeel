#include <ctime>
#include <exception>
#include <random>
#include <iostream>
#include "random.hpp"

// v 0.1

tk::random::random(){ // Class constructor.
	try {
		seed = rd();
	}

	catch (std::exception e){
		std::cout << "Exception: " << e.what() << std::endl;
		seed = time(NULL);
	}

	engine.seed(seed);
}

void tk::random::set_seed(int s){
	seed = s;
	engine.seed(seed);
}

int tk::random::operator()(int low, int high){
	try {
		distribution = new std::uniform_int_distribution<int>(low,high);
	}
	catch(std::exception e){
		std::cout << "Exception: " << e.what() << std::endl;
	}

	if(distribution == NULL) return low+4%(high-low); // When random numbers fail to be generated, the system defaults to 4.
	else return (*distribution)(engine);
}
