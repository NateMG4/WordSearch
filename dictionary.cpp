#include "Dictionary.h"
Dictionary::Dictionary() {}

int Dictionary::getMaxWordLength(){ return maxWordLength;}
int Dictionary::getMinWordLength(){ return minWordLength;}

// initialize dictionary with words from dictionary file
void Dictionary::read(string filePath){
    string line;
    ifstream rfile;
    rfile.open(filePath);
    while(getline(rfile, line)){
        if(line.length() >= 5){
            words.push_back(line);
        }
    }
    numWords = words.size();
}

// print out dictionary
ostream& operator<< (ostream& ostr, Dictionary& d) {
    for(string word : d.words){
        ostr << word << endl;
    }
    return ostr;
}

// swap 2 elements in dictionary vector
void Dictionary::swap(int a, int b){
    string temp = words[a];
    words[a] = words[b];
    words[b] = temp; 
}

// sort dictionary using selection sort
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

        // progress bar
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

// sort dictionary using quick sort
void Dictionary::quickSort(int left, int right){
    if(left > right){
        return;
    }

    string pivot = words[right];
    int i = left-1;
    for(int j=left; j < right-1; j++){
        if(words[j] <= pivot){
            i++;
            swap(i, j);
        }
    }
    int pivotIndex = i+1;
    swap(pivotIndex, right);
    quickSort(left, pivotIndex-1);
    quickSort(pivotIndex+1, right);
}

// sort dictionary using heapSort
void Dictionary::heapSort(){
    Heap<string> h(words);
    words = h.heapSort();

}

// loop up word in sorted dictionary using binary search. 
// Return the word if it is found, and an empty string if not.
string Dictionary::lookup(string word){
    int left = 0;
    int right = words.size()-1;
    while(left <= right){
        int index = floor(left + right) / 2;
        string curr = words[index];
        if(curr == word){
            return curr;
        }else if(curr < word){
            left = index+1;
        } else{
            right = index-1;
        }
    }
    return "";
}