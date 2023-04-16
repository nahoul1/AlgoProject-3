#include <iostream>
#include <fstream>
#include <vector>
#include "d_matrix-1.h"
#include "LetterGrid.h"


using namespace std;

//Implement a class called LetterGrid that reads the letters in the grid from a file and stores them in a matrix.

LetterGrid::LetterGrid(string file) {
    filename = file;

}

void LetterGrid::readletters(string& fin)
{

    ifstream fin;
    int digit;
    int ch; // holds each value read from file
    fstream file;

    file.open(filename.c_str());
    file >> ch;

    cout<< ch << endl;

    mat_size = ch;



    grid.resize(mat_size, mat_size);

    file.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    for (int i = 0; i < mat_size; i++)
    {
        for (int j = 0; j < mat_size; j++)
        {
            fin >> ch;
            if (ch == ' ') {
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
    for (int i = 0; i < mat_size; i++) { // change mat_size
        for (int j = 0; j < mat_size; j++) {
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }
}

void LetterGrid::findWords(matrix<string>& lst_word) {
    string curr_word;
    int col_multiplier, row_multiplier, matrix_index;

    printGrid();

    mat_size = grid.rows();
    //cout<< grid.rows() << endl;

    int number_of_words = 8 * mat_size * mat_size * (mat_size - 5);

    //cout << number_of_words << endl;
    //cout << lst_word.rows() << endl;

    lst_word.resize(number_of_words, 3);


    for (int row = 0; row < mat_size; row++) {
        for (int col = 0; col < mat_size; col++) {

            if (col == 0) {
                col_multiplier = 1;
            }
            else {
                col_multiplier = 80 * col;
            }
            if (row == 0) {
                row_multiplier = 1;
            }
            else {
                row_multiplier = 80 * row;
            }
            matrix_index = col_multiplier * row_multiplier;
            for (int quick = 0; quick < matrix_index * ((mat_size - 5) * 8); quick++) {
                lst_word[quick][1] = char(row);
                lst_word[quick][2] = char(col);
            }


            //look up
            for (int count = 5; count < mat_size; count++) {
                for (int start = 0; start < count; start++) {
                    curr_word += grid[row - start][col];
                }
                lst_word[matrix_index * (count - 5)][0] = curr_word;
            }
            curr_word.clear();


            // look down
            for (int count = 5; count < mat_size; count++) {
                for (int start = 0; start < count; start++) {
                    curr_word += grid[row + start][col];
                }

                lst_word[matrix_index * (count + 5)][0] = curr_word;
            }
            curr_word.clear();


            // look left
            for (int count = 5; count < mat_size; count++) {
                for (int start = 0; start < count; start++) {
                    curr_word += grid[row][col - start];
                }
                lst_word[matrix_index * (count + 15)][0] = curr_word;
            }
            curr_word.clear();


            //look right
            for (int count = 5; count < mat_size; count++) {
                for (int start = 0; start < count; start++) {
                    curr_word += grid[row][col + start];
                }
                lst_word[matrix_index * (count + 25)][0] = curr_word;
            }
            curr_word.clear();


            //look upleft
            for (int count = 5; count < mat_size; count++) {
                for (int start = 0; start < count; start++) {
                    curr_word += grid[row - start][col - start];
                }
                lst_word[matrix_index * (count + 35)][0] = curr_word;
            }
            curr_word.clear();


            // look upright
            for (int count = 5; count < mat_size; count++) {
                for (int start = 0; start < count; start++) {
                    curr_word += grid[row - start][col + start];
                }
                lst_word[matrix_index * (count + 45)][0] = curr_word;
            }
            curr_word.clear();


            // look downleft
            for (int count = 5; count < mat_size; count++) {
                for (int start = 0; start < count; start++) {
                    curr_word += grid[row + start][col - start];
                }
                lst_word[matrix_index * (count + 55)][0] = curr_word;
            }
            curr_word.clear();


            // look downright
            for (int count = 5; count < mat_size; count++) {
                for (int start = 0; start < count; start++) {
                    curr_word += grid[row + start][col + start];
                }
                lst_word[matrix_index * (count + 65)][0] = curr_word;
            }
            curr_word.clear();

        }
    }
}