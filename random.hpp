#ifndef RANDOM_HPP
#define RANDOM_HPP

#include <random>

namespace tk{
    class random{
            std::mt19937 engine;
            int seed;
        public:
            random(){
                std::random_device r;
                seed = r();
                engine.seed(seed);
            }
            void set_seed(int new_seed){
                seed = new_seed;
                engine.seed(seed);
            };
            int get_seed(){
                return seed;
            }
            int operator()(int start, int end){
                std::uniform_int_distribution<int> dist(start,end);
                return dist(engine);
            }
    };
}

#endif /* RANDOM_HPP */
