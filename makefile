output: main.o letterGrid.o WordFinder.o
	g++ main.o letterGrid.o WordFinder.o -o output

main.o: main.cpp
	g++ -c main.cpp

letterGrid.o: letterGrid.cpp letterGrid.h
	g++ -c letterGrid.cpp

WordFinder.o: WordFinder.cpp WordFinder.h
	g++ -c WordFinder.cpp

clean:
	rm *.o output