#include <iostream>
#include <fstream>
#include <vector>
#include "sort_algorithms.h"
#include "WordFinder.h"

using namespace std;

WordFinder::WordFinder() {
    filename = "Glossary.txt";
    readWords(filename, vords);
}

template <typename T>
void WordFinder::readWords(string filename, vector<T>& v) {
    ifstream fin;
    fin.open(filename.c_str());
    if (fin.fail()) {
        cout << "Error opening file" << endl;
        exit(1);
    }

    string word;
    while (fin >> word) {
        word[0] = tolower(word[0]);
        v.push_back(word);
        vords.push_back(word);
    }
    fin.close();

}


// check if it works
template <typename T>
ostream& operator<<(ostream& out, vector<T>& v) {
    for (int i = 0; i < v.size(); i++) {
        out << v.at(i) << " ";
    }
    return out;
}


void WordFinder::sortWords(vector<string>& v) {
    selectionSort(v);
}


void WordFinder::sortWordq(vector<string>& v) {
    int n = v.size();
    quickSort(v, 0, n - 1);
}


void WordFinder::sortWordh(vector<string>& v) {

    heapSort(v);
}


int WordFinder::lookupWords(string x, int low, int high)
{
    // using binary search

    if (low > high) {
        return -1;
    }

    else {
        int mid = (low + high) / 2;
        if (vords[mid] == x) {
            return mid;
        }
        else if (vords[mid] > x) {
            return lookupWords(x, low, mid - 1);
        }
        else if (vords[mid] < x) {
            return lookupWords(x, mid + 1, high);
        }
        else {
            return -1;
        }
    }


}




