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
    vector<T>* words = new vector<T>();
    BinarySearchTree<string>* lookup = new BinarySearchTree<string>();

public:
    WordFinder(int N = 0);
    vector<T> Words();
    void initializeWords(ifstream& fin);
    friend ostream& operator<<(ostream& out, const WordFinder& wf);
    void sortWords();
    void lookupWords(string x, int low, int high, const WordFinder& wf);
    void readFromFile(string filename);

};


#endif
