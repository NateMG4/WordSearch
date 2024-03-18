#include "Dictionary.h"
#include "Grid.h"
#include <set>

set<string> findMatches(Dictionary d, Grid g){
    set<string> foundWords;
    for(int y = 0; y < g.numRows; y++){
        for(int x = 0; x < g.numCols; x++){
            string testWords[8];
            for(int i = 0; i < x+1; i++){
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
                        testWords[j] = "";
                    }
                }
            }
        }
    }

    return foundWords;
}

int main(){
    Dictionary d;
    d.read("dictionary-2");
    // d.selectionSort();
    d.quickSort(0, d.numWords-1);
    // d.heapSort();
    // cout << d.lookup("outnumbering") << endl;
    // cout << d.lookup("gjalksdjg");
    // cout << d;

    Grid g;
    g.read("input15-2");
    cout << g;

    set<string> foundWords = findMatches(d, g);
    for(string word : foundWords){
        cout << word<<endl;
    }
    return 0;
}

