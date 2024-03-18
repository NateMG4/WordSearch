#include <iostream>
#include <vector>
#include <fstream>
#include <math.h>
using namespace std;
class Dictionary{
public:
    Dictionary();
    void read(string filepath);
    bool lookup(string word);
    void selectionSort();
    friend ostream& operator<< (ostream& ostr, Dictionary& d);
    void swap(int a, int b);
private:
    vector<string> words;
};