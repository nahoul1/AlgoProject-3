#include "LetterGrid.h"
#include "d_matrix-1.h"
#include <vector>
#include <fstream>


using namespace std;

LetterGrid::LetterGrid() {

}

void LetterGrid::printGrid() {
	int n = wfMatrix.size();
	for (int i = 0; i < n; i++) {
		cout << wfMatrix->at[i] << " ";
	}
}


void LetterGrid::readLetters(string filename) {
	fstream file;
	string word;
	file.open(filename.c_str());
	while (file > word) {
		wfMatrix->pushback(word);
	}
}