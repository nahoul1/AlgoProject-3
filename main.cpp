#include <iostream>
#include <string>
#include "LetterGrid.h"
#include "WordFinder.h"

using namespace std;

void wordSearch() {
	vector<string>* words = new vector<string>();

	string gridFile;
	string glossary;
	cout << "Enter the name of the .txt grid file: ";
	cin >> gridFile;

	glossary = "Glossary.txt";

	LetterGrid lg(gridFile);
	WordFinder wf(glossary);

	wf.readFromFile();





}