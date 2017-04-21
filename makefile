all: wayafeel

wayafeel: main.o phoneme.o grapheme.o
	g++ -o wayafeel main.o phoneme.o grapheme.o -std=c++11 -g

main.o: main.cpp
	g++ -c main.cpp -std=c++11 -g

phoneme.o: phoneme.cpp
	g++ -c phoneme.cpp -std=c++11 -g

grapheme.o: grapheme.cpp
	g++ -c grapheme.cpp -std=c++11 -g

clean: rm_o
	rm wayafeel

rm_o:
	rm *.o
