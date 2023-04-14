#include "WordFinder.h"
#include <string.h>
#include <vector>
#include <iostream>
#include <fstream>
#include "d_matrix-1.h"
#include "sort_algorithms.h"

using namespace std;



template <typename T>
void sortWords(T words)
{
    selectionSort(words);
}


void lookupWords(string x, int low, int high, const WordFinder& wf)
{
    // using binary search
    if (low > high) {
        return false;
    }
    else {
        int mid = (low + high) / 2;
        if (wf[mid] == x) {
            return mid;
        }
        else if (wf[mid] > x) {
            return lookupWords(x, low, mid - 1, wf);
        }
        else if (wf[mid] < x) {
            return lookupWords(x, mid + 1, high, wf)
        }
    }
        

}


ostream operator<<(ostream& out, const WordFinder& wf) {
    int n = wf.size();

    for (int i = 0; i < n; i++) {
        cout << wf.at[i] << " ";
    }
}


void readFromFile(string filename) {
    fstream file;
    string word;
    file.open(filename.c_str());
    while (file > word{
        words.pushback(word);
    }
    file.close();
}


/*
WordFinder::WordFinder()
{
    wfMatrix.resize(0,0);
    vector<T>* words;
    BinarySearchTree<string>* lookup = new BinarySearchTree<string>();
    for (int i = 0; i < words; i++)
    {
        for (int j = 0; j < wfMatrix.cols(); j++)
        {
            lookup.add(wfMatrix[i][j]);
        }
    }
}


template<typename T>
vector<T> WordFinder::Words()
{
    return words;
}


void WordFinder::initializeWords(ifstream& fin)
{
    int N;
    fin >> N;
    wfMatrix.resize(N,N);
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            fin >> wfMatrix[i][j];
        }
    }
}
*/
