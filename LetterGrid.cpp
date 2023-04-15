#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "d_matrix-1.h"
#include "LetterGrid.h"

using namespace std;

//Implement a class called LetterGrid that reads the letters in the grid from a file and stores them in a matrix.


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

    //file.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    for (int i = 0; i < mat_size; i++)
    {
        for (int j = 0; j < mat_size; j++)
        {
            fin >> ch;
            if (ch = ' ') {
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
    for (int i = 0; i < mat_size; i++) {
        for (int j = 0; j < mat_size; j++) {
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }
}


/*
void LetterGrid::findWords() {
    for (int row = 0; row < mat_size; row++) {
        for (int col = 0; col < mat_size; col++) {

            string curr_word;
            bool up, down, left, right, upleft, upright, downleft, downright;
            up = true;
            down = true;
            left = true;
            right = true;
            upleft = true;
            upright = true;
            downleft = true;
            downright = true;


            if (row == 0) {
                up = false;
                upleft = false;
                upright = false;

                if (col == 0) {
                    left = false;
                    upleft = false;
                    downleft = false;
                }

                if (col = mat_size - 1) {
                    right = false;
                    upright = false;
                    downright = false;
                }

                if (row = mat_size - 1) {
                    down = false;
                    downleft = false;
                    downright = false;
                }

                if (up == true) {
                    for (int count = 5; count < mat_size; count++) {
                        for (int start = 0; start < count; start++) {
                            curr_word += grid[row][col];
                        }
                    }
                }




            }

            cout << endl;

        }



    }
}
*/