#include <iostream>
#include <string>
#include <ctime>
#include <vector>
#include "LetterGrid.h"
#include "WordFinder.h"
#include "WordFinder.cpp"
#include "sort_algorithms.h"
#include <cstdlib>
#include <Bits.h>

using namespace std;

void wordSearch() {
	vector<string> words;

	string gridFile;
	string glossary;
	cout << "Enter the name of the .txt grid file: ";
	cin >> gridFile;

	glossary = "Glossary.txt";


	LetterGrid* lg = new LetterGrid(gridFile);
	WordFinder* wf = new WordFinder();


	wf->readWords(glossary, words);

	int choice;
	cout << "Which type of sort would you like to use? (1)Selection, (2)Quick, or (3)Heap?" << endl;
	cin >> choice;


	time_t start, finish;

	if (choice == 1) {
		time(&start);
		wf->sortWords(words);
		time(&finish);
		cout << "Using selection sort..." << endl;
	}
	else if (choice == 2) {
		time(&start);
		wf->sortWordq(words);
		time(&finish);
		cout << "Using quick sort..." << endl;
	}
	else if (choice == 3) {
		time(&start);
		wf->sortWordh(words);
		time(&finish);
		cout << "Using heap sort..." << endl;
	}
	else {
		cout << "Invalid choice" << endl;
		wordSearch();
	}

	//cout << words;

	cout << "Time required = " << difftime(finish, start) << " seconds" << endl;

	//matchWords(*wf, *lg);

};


int main() {
	wordSearch();
}

/*
//mplement a global function matchWords() that is passed the WordFinder and the LetterGrid obects as parameters and prints out candidate words that can be found in the glossary. That is, scan the grid to get all possible words and search each possible word in the glossary, using binary search algorithm from the WordFinder class. If found, print out the word using the format:
void matchWords(WordFinder& wf, LetterGrid& lg) {
    vector<string> words = lg.getWords();
    for (int i = 0; i < words.size(); i++) {
        if (wf.lookupWords(words[i], 0, wf.size() - 1, wf.getWords()) != -1) {
            cout << words[i] << endl;
        }
    }
}



int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
*/