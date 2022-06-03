/**
 * @file Sudoku.cpp
 * @author Yohanes
 * @date 2022-05-26
 **/

#include <iostream>
#include <fstream>
#include <istream>
#include <ostream>

#include "Sudoku.h"
using namespace std;

/*
//output method to output sudoku puzzle
ostream& operator<<(ostream &out, const Sudoku &p) {
	out << p.streamOutputHelper(out); 
	return out;
}
// input function to read file 
istream& operator>>(istream &in, Sudoku &input) {
	input.streamInputHelper(in);
	return in;
}
*/

//default constructor
Sudoku::Sudoku() {
	//initialize
    grid = new int*[9]; 
	fixed = new bool*[9];

	for (int i = 0; i < 9; i++) {
		grid[i] = new int[9];
		fixed[i] = new bool[9];

		for (int j = 0; j < 9; j++) {
			grid[i][j] = 0;                    
			fixed[i][j] = false;
		}
	}
}
// isFixed method is checking values if it is fixed or variable.
bool Sudoku::isFixed(int i, int j) {
    return fixed[i][j];
}
// destructor
Sudoku::~Sudoku() {
	for (int i = 0; i < 9; i++) {
		delete[] grid[i]; 
		delete[] fixed[i];
	}

	delete[] grid;
	delete[] fixed;
}
// helper function for output
ostream& Sudoku::streamOutputHelper(ostream &out) const {
for(int i = 0; i < 9; i++){
        if(i % 3 == 0){
            out << "+-------+-------+-------+" << endl;
        }
        out << "| ";

        for(int j = 0; j < 9; j++){
            char c = grid[j][i] + '0';
            out << c << " ";

            if((j + 1) % 3 == 0){
               out << "| "; 
            }
        }
      out << endl;
    }
    out << "+-------+-------+-------+" << endl;

    return out;
}
//helper function input
void Sudoku::streamInputHelper(istream& in) {
    int row = 0;
    int column = 0;
	char c;
	
	while (in.get(c)) {                                         
		if (c <= '9' && c >= '0') {
			if (c != '0') {
				fixed[column][row] = true ;
			} else {
				fixed[column][row] = false;
			}

			grid[column][row] = (c - '0');    
			column++;

			if (column > 8) {
				column = 0;
				row++;
			}
		}
	}
}