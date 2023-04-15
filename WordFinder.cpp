#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include"sort_algorithms.h"
using namespace std;

class WordFinder
{
private:
    string filename;
    vector<string>* words;
    //a function to read the words from the glossary file, and store them in a vector

public:
    void readWords(string filename);

    //an overloaded output operator “<< “ to print the word list, e.g., cout << words; prints the entire list of words from the vector.
    friend ostream& operator<<(ostream& out, const WordFinder& wf);

    //a function that sorts the words using SelectionSort algorithm (see the sort_algorithms.h file)
    void sortWords(vector<string>& v);

    //a function to handle word lookups using binary search algorithm.
    template <typename T>
    T lookupWords(string x, int low, int high, vector<T>& v);
};


void WordFinder::readWords(string filename) {
    ifstream fin;
    fin.open(filename);
    if (fin.fail()) {
        cout << "Error opening file" << endl;
        exit(1);
    }

    string word;
    while (fin >> word) {
        words->push_back(word);
    }
    fin.close();
}


// check if it works
ostream& operator<<(ostream& out, const WordFinder& wf) {
    for (int i = 0; i < wf.words->size(); i++) {
        out << wf.words->at(i) << " ";
    }
    return out;
}


void WordFinder::sortWords(vector<string>& v) {
    selectionSort(v);
}

template <typename T>
T WordFinder::lookupWords(string x, int low, int high, vector<T>& v)
{
    // using binary search
    if (low > high) {
        return false;
    }

    else {
        int mid = (low + high) / 2;
        if (v[mid] == x) {
            return mid;
        }
        else if (v[mid] > x) {
            return lookupWords(x, low, mid - 1, v);
        }
        else if (v[mid] < x) {
            return lookupWords(x, mid + 1, high, v);
        }
    }


}




