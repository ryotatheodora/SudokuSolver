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

ostream& operator<<(ostream &out, const Sudoku &p) {
	out << p.streamOutputHelper(); 
	return out;
}

istream& operator>>(istream &in, Sudoku &input) {
	input.streamInputHelper(in);
	return in;
}

Sudoku::Sudoku() {
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

bool Sudoku::isFixed(int i, int j) {
    return fixed[i][j];
}

Sudoku::~Sudoku() {
	for (int i = 0; i < 9; i++) {
		delete[] grid[i]; 
		delete[] fixed[i];
	}

	delete[] grid;
	delete[] fixed;
	
}

string Sudoku::streamOutputHelper(ostream &out) const {
    const string border = "+-------+-------+-------+\n";

    out << border;
    for (int i = 0; i < 9; i++) {
        out << "|";
        for (int j = 0; j < 9; j++) {
            out << " " << grid[i*9+j].first;
            // inner border
            if (j % 3 == 2) {
                out << " |";
            }
            
        }
        out << endl;
        if (i % 3 == 2) {
            out << border;
        }
        
        
    }
    return out;
}

void Sudoku::streamInputHelper(istream& in) {
    int row = 0;
    int column = 0;
    char c;

    while (in.get(c)) {
        if (c <= '9' && c >= '0') {
            if (c != '0') {
                isFixed[column][row] = true ;
            } else {
                isFixed[column][row] = false;
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
