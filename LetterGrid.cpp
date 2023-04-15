#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include"sort_algorithms.h"
#include "d_matrix-1.h"
using namespace std;

//Implement a class called LetterGrid that reads the letters in the grid from a file and stores them in a matrix.
class LetterGrid
{
private:
    string filename;
    matrix<string> grid;
    int mat_size;

public:
    LetterGrid(string file);
    void readletters(ifstream& fin);
    void printGrid();
    void findWords();


};

LetterGrid::LetterGrid(string file) {
    filename = file;
}

void LetterGrid::readletters(ifstream& fin)
{
    int digit;
    char ch; // holds each value read from file
    fstream file;

    file.open(filename.c_str());
    file >> ch;
    mat_size = ch - '0';
    grid.resize(mat_size, mat_size);

    file.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    for (int i = 0; i < mat_size; i++)
    {
        for (int j = 0; j < mat_size; j++)
        {
            fin >> ch;
            if (ch = ' '){
                continue;
            }
            else {
                grid[i][j] = ch;
            }
            // If the read char is not Blank
         }
        }
    }

void LetterGrid::printGrid() {
	int n = wfMatrix.size();
	for (int i = 0; i < n; i++) {
		cout << wfMatrix->at[i] << " ";
	}
}

        cout << endl;

    }



}