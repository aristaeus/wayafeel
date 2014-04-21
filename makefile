all: main.o phoneme.o random.o grapheme.o
	g++ -o phoneme main.o phoneme.o grapheme.o random.o -std=c++11 -g

main.o: main.cpp
	g++ -c main.cpp -std=c++11 -g

phoneme.o: phoneme.cpp
	g++ -c phoneme.cpp -std=c++11 -g

grapheme.o: grapheme.cpp
	g++ -c grapheme.cpp -std=c++11 -g

random.o: random.cpp
	g++ -c random.cpp -std=c++11 -g

clean:
	rm *.o
