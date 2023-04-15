#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "sort_algorithms.h"
#include "d_matrix-1.h"
#include <ctime>
#include <cstdlib>
#include "WordFinder.h"
#include <cstring>


using namespace std;


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




