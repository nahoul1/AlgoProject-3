#include "WordFinder.h"
#include <string.h>
#include <vector>
#include <iostream>
#include <fstream>
#include "d_matrix-1.h"
#include "BinarySearchTree.h"

using namespace std;


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


template <typename T>
void sortWords(T words)
{
    selectionSort(words);
}


void lookupWords()
{


}







