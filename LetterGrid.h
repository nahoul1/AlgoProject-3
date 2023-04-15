#ifndef LETTERGRID_H
#define LETTERGRID_H

#include "d_matrix-1.h"
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





#endif