#include "LetterGrid.h"
#include "d_matrix-1.h"
#include <vector>
#include <fstream>


using namespace std;

LetterGrid::LetterGrid(string filename) {
	
}

void LetterGrid::printGrid() {
	int r = wfMatrix->rows();
	int c = wfMatrix->cols();
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cout << wfMatrix->at[i][j] << " ";
		}
		
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