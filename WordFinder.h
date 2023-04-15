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
    string filename;
    //vector<string> words;
    //a function to read the words from the glossary file, and store them in a vector

public:
    template <typename T>
    void readWords(string filename, vector<T>& v);

    //an overloaded output operator “<< “ to print the word list, e.g., cout << words; prints the entire list of words from the vector.
    template <typename T>
    friend ostream& operator<<(ostream& out, vector<T>& v);

    //a function that sorts the words using SelectionSort algorithm (see the sort_algorithms.h file)
    void sortWords(vector<string>& v);

    void sortWordq(vector<string>& v);

    void sortWordh(vector<string>& v);

    //a function to handle word lookups using binary search algorithm.
    template <typename T>
    T lookupWords(string x, int low, int high, vector<T>& v);
};


#endif
