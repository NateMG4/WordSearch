#include "Grid.h"

Grid::Grid(){
    numCols = 0;
    numRows = 0;
}

void Grid::read(string filePath){
    char c;
    ifstream rfile;
    rfile.open(filePath);

    // find grid size
    string sizeString;
    getline(rfile, sizeString);
    int seperator = sizeString.find(' ');
    numRows = stoi(sizeString.substr(0, seperator));
    numCols = stoi(sizeString.substr(seperator+1, sizeString.size()-1));

    // create 2d matrix for grid;
    matrix = new char*[numRows];
    for(int i = 0; i < numCols; i++){
        matrix[i] = new char[numCols];
    }
    
    int num = 0;
    while(rfile >> skipws >> c){
        int y = num/numRows;
        int x = num%numCols;
        matrix[y][x] = c;
        num++;
    }
}
ostream& operator<< (ostream& ostr, Grid& g) {
    for(int y = 0; y < g.numRows; y++){
        for(int x = 0; x < g.numCols; x++){
            ostr << g.matrix[y][x] << " ";
        }
        ostr << endl;
    }
    return ostr;
}
