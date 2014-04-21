#include <ctime>
#include "random.hpp"

tk::random::random(){
	engine.seed(rd());
}

void tk::random::seed(int seed){
	engine.seed(seed);
}

int tk::random::operator()(int low, int high){
	distribution = new std::uniform_int_distribution<int>(low,high);
	return (*distribution)(engine);
}
