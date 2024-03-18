#include "Dictionary.h"
Dictionary::Dictionary() {}

int Dictionary::getMaxWordLength(){ return maxWordLength;}
int Dictionary::getMinWordLength(){ return minWordLength;}

void Dictionary::read(string filePath){
    string line;
    ifstream rfile;
    rfile.open(filePath);
    while(getline(rfile, line)){
        words.push_back(line);
    }
}

ostream& operator<< (ostream& ostr, Dictionary& d) {
    for(string word : d.words){
        ostr << word << endl;
    }
    return ostr;
}
void Dictionary::swap(int a, int b){
    string temp = words[a];
    words[a] = words[b];
    words[b] = temp; 
}
void Dictionary::selectionSort(){
    int barWidth = 20;
    cout << "Selection Sort"<< endl;
    int size = words.size();
    int minIndex = 1;
    for(int i = 0; i < words.size()-1; i++){
        for(int j = i+1; j < words.size(); j++){
            if(words[j] < words[minIndex]){
                minIndex = j;
            }
        }
        swap(i, minIndex);
        float progress = ( 1.0*i)/size;
        int numBars = barWidth * progress;
        int spaces = (barWidth - numBars);
        string bar(numBars, '|');
        string space(spaces,' ');
        cout << i << "/" << size << " [" << bar<< space<< "] " << progress * 100 << " %\r";
        cout.flush();

        maxWordLength = max((int) words[minIndex].size(), maxWordLength);
        minWordLength = min((int) words[minIndex].size(), minWordLength);

    }
    cout << endl;
}
string Dictionary::lookup(string word){
    int left = 0;
    int right = words.size()-1;
    while(left <= right){
        int index = floor(left + right) / 2;
        string curr = words[index];
        if(curr < word){
            left = index+1;
        } else if(curr > word){
            right = index-1;
        } else{
            return words[left];
        }
    }
    return "";
}