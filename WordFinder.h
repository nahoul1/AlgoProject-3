#include <string.h>
#include <iostream>
#include <fstream>
#include "sort_algorithms.h"
#include "d_matrix-1.h"
#include <string.h>

#ifndef WORDFINDER_H
#define WORDFINDER_H

class WordFinder
{
private:
    template <typename T>
    vector<T>* words = new vector<T>();
    matrix<string>* wfMatrix = new matrix<string>();
    string filename;

    BinarySearchTree<string>* lookup = new BinarySearchTree<string>();


public:
    WordFinder(string file);
    vector<T> Words();
    void initializeWords(ifstream& fin);
    friend ostream& operator<<(ostream& out, const WordFinder& wf);
    void sortWords();
    void lookupWords();
    void readFromFile();

};



void matchWords(WordFinder& wf, LetterGrid& lg);

void wordSearch();

#endif
