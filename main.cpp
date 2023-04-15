#include <iostream>
#include <string>
#include <ctime>
#include <vector>
#include "LetterGrid.h"
#include "WordFinder.h"
#include "WordFinder.cpp"
#include "sort_algorithms.h"
#include <cstdlib>

using namespace std;

template <typename T>
T matchWords(WordFinder& wf, LetterGrid& lg) {
	matrix<string> all_words;
	lg.findWords(all_words);
	int p = all_words.rows() - 1;
	int h = wf.lookupWords(all_words[2][2], 0, p);

	for (int i = 0; i < all_words.rows(); i++) {
		if ((wf.lookupWords(all_words[i][0], 0, p)) != -1) {
			cout << all_words[i][0] << endl;
		}
	}
}


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

	
	void matchWords(*wf, *lg);

};


int main() {
	wordSearch();
}
