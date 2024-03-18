#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

class Grid{
public:
    Grid();
    void read(string filePath);
    friend ostream& operator<< (ostream& ostr, Grid& g);
    int numCols;
    int numRows;
    char **matrix;
};