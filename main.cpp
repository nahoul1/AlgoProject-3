#include <iostream>
#include <vector>
#include "LetterGrid.h"
#include "WordFinder.h"
using namespace std;

void matchWords(WordFinder wf, LetterGrid lg)
{
    matrix<string> all_words;
    lg.findWords(all_words);
    int p = all_words.rows() - 1;
    cout << all_words.rows() << endl;

    for (int i = 0; i < all_words.rows(); i++) {

        string checking_word = all_words[i][0];

        if ((wf.lookupWords(checking_word, 0,p)) == -1)
        {
            continue; // if the word is not found, continue to the next word
        }
        else{
            cout << "Found: pos_x( " << all_words[i][1] <<" ), pos_y( "<< all_words[i][2] <<" ) –-> wordFound: " << checking_word << endl;
        }
    }
}

void wordSearch()
{
	vector<string> words;

	string gridFile = "input15.txt";
	string glossary;
	cout << "Enter the name of the .txt grid file: ";
	//cin >> gridFile;

	glossary = "Glossary.txt";


	LetterGrid* lg = new LetterGrid(gridFile);
	WordFinder* wf = new WordFinder();

    lg->readletters(gridFile); // read the letters from the file

	wf->readWords(glossary, words);

	int choice;
	cout << "Which type of sort would you like to use? (1)Selection, (2)Quick, or (3)Heap?" << endl;
	cin >> choice;


	time_t start, finish;

	if (choice == 1) {
        cout<< "with checker in place" << endl;
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

	cout << "Time required = " << difftime(finish, start) << " seconds" << endl;

    matchWords(*wf, *lg);


}

int main()
{
    wordSearch();
    return 0;
}
