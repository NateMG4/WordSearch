#pragma once
#ifndef GRID_H
#define GRID_H
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

class Grid{
public:
    Grid();
    ~Grid();
    void read(string filePath);
    friend ostream& operator<< (ostream& ostr, Grid& g);
    char getChar(int x, int y);
    int numCols;
    int numRows;
    char **matrix;
};

#endif