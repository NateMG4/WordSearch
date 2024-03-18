
#pragma once
#ifndef DICTIONARY_H
#define DICTIONARY_H
#include <iostream>
#include <vector>
#include <fstream>
#include <math.h>
using namespace std;
class Dictionary{
public:
    Dictionary();
    void read(string filepath);
    string lookup(string word);
    void selectionSort();
    void quickSort(int left, int right);
    friend ostream& operator<< (ostream& ostr, Dictionary& d);
    void swap(int a, int b);
    int getMaxWordLength();
    int getMinWordLength();
    int numWords = 0;

private:
    vector<string> words;
    int maxWordLength = 0;
    int minWordLength = 0;
};

#endif