#include <string.h>
#include <iostream>
#include <fstream>
#include "sort_algorithms.h"

#ifndef WORDFINDER_H
#define WORDFINDER_H

class WordFinder
{
private:
    matrix<string>* wfMatrix = new matrix<string>();
    string filename;

public:
    WordFinder(string file);
    vector<T> Words();
    void initializeWords(ifstream& fin);
    friend ostream& operator<<(ostream& out, const WordFinder& wf);
    void sortWords();
    void lookupWords();
    void readFromFile();

};


#endif
