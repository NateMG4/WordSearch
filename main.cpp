#include "Dictionary.h"
#include "Grid.h"
#include <set>
using namespace std;


// find all words in grid g, that are present in dictionary d.
set<string> findMatches(Dictionary d, Grid g){
    set<string> foundWords;
    for(int y = 0; y < g.numRows; y++){
        for(int x = 0; x < g.numCols; x++){
            string testWords[8];
            for(int i = 0; i < max(g.numCols,g.numRows); i++){
                testWords[0] += g.getChar(y+i,x);
                testWords[1] += g.getChar(y,x+i);
                testWords[2] += g.getChar(y-i,x);
                testWords[3] += g.getChar(y,x-i);
                testWords[4] += g.getChar(y+i,x+i);
                testWords[5] += g.getChar(y+i,x-i);
                testWords[6] += g.getChar(y-i,x+i);
                testWords[7] += g.getChar(y-i,x-i);
                for(int j = 0; j < 8; j++){
                    if(testWords[j] == ""){
                        continue;
                    }
                    string w = d.lookup(testWords[j]);
                    if(w != ""){
                        foundWords.insert(w);
                    }
                }
            }
        }
    }

    return foundWords;
}


// Get user input to select grid, the serach grid for words.
void search(int sortAlgorithim){
    Dictionary d;
    d.read("dictionary-2");

    switch(sortAlgorithim){
        case 1:{
            d.selectionSort();
            break;
        }
        case 2:{
            d.quickSort(0, d.numWords-1);
            break;
        }case 3:{
            d.heapSort();
            break;
        }default:{
            std::cout << "invalid selection";
            return;
        }
    }

    cout << d;
    Grid g;
    cout<< "Enter Grid Name: ";
    string gridName;
    cin >> gridName;
    g.read("input15-2");
    cout << g;

    set<string> foundWords = findMatches(d, g);
    for(string word : foundWords){
        cout << word<<endl;
    }
}

int main(){
    cout << "Choose Sorting Algorithim: " << endl
    << "(1) Selection Sort" << endl
    << "(2) Quick Sort" << endl
    << "(3) Heap Sort" << endl
    << "Selection: ";
    int algo;
    cin >> algo;
    search(algo);

    return 0;
}

