#ifndef WORDFINDER_H
#define WORDFINDER_H

class WordFinder
{

private:
    string filename;
    vector<string> vords;
    //a function to read the words from the glossary file, and store them in a vector

public:
    WordFinder();
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
    int lookupWords(string x, int low, int high);

};


#endif
