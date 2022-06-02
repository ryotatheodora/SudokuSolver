/**
 * @file Sudoku.cpp
 * @author Yohanes
 * @brief 
 * Notes:
 * 
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

string Sudoku::helperStreamOutput(ostream &out) const {
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

void Sudoku::helperStreamInput(istream& in) {
    grid.clear();
    char c;

    while (in >> c) {
        if (grid.size() == 81) {
            break;
        }
        
        if (isdigit(c)) {
            grid.push_back({c - '0', c != '0'});
        }
    }
    return in;
}

