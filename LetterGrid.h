#ifndef LETTERGRID_H
#define LETTERGRID_H

#include "d_matrix-1.h"

class LetterGrid
{
private:
	matrix<string>* wfMatrix = new matrix<string>();
public:
	LetterGrid(string filename);
	void printGrid(string file);
	void readLetters(string filename);
};




#endif