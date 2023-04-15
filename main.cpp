#include <iostream>
#include "WordFinder.cpp"
#include "LetterGrid.cpp"
using namespace std;

//mplement a global function matchWords() that is passed the WordFinder and the LetterGrid obects as parameters and prints out candidate words that can be found in the glossary. That is, scan the grid to get all possible words and search each possible word in the glossary, using binary search algorithm from the WordFinder class. If found, print out the word using the format:
void matchWords(WordFinder& wf, LetterGrid& lg) {
    vector<string> words = lg.getWords();
    for (int i = 0; i < words.size(); i++) {
        if (wf.lookupWords(words[i], 0, wf.size() - 1, wf.getWords()) != -1) {
            cout << words[i] << endl;
        }
    }
}



int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
