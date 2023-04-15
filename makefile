GCC = g++ 
CFLAGS = -g -Wall
OBJS = main.o LetterGrid.o WordFinder.o
EXE = myClient

myClient: $(OBJS)
	$(GCC) $(OBJS) -o $(EXE) 
	
main.o: main.cpp LetterGrid.h WordFinder.h sort_algorithms.h
	$(GCC) $(CFLAGS) -c main.cpp

LetterGrid.o: LetterGrid.h d_matrix-1.h
	$(GCC) $(CFLAGS) -c Student.cpp

WordFinder.o: WordFinder.h sort_algorithms.h d_matrix-1.h
	$(GCC) $(CFLAGS) -c ListRefBased.cpp

clean:
	rm $(OBJS) $(EXE)
