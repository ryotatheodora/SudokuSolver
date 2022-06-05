/**
 * @file Sudoku.cpp
 * @author Yohanes, Ryota Theodora
 * @date 2022-06-04
 **/
#include "Sudoku.h"

Sudoku::Sudoku() {
	//resize the layout to 81
	layout_.resize(81);
}

Sudoku::~Sudoku() {
}

int Sudoku::value(int row, int col) {
    return layout_[row * 9 + col].first;
}

bool Sudoku::determined(int row, int col) {
    return layout_[row * 9 + col].second;
}

void Sudoku::setValue(int row, int col, int val, bool deter) {
    layout_[row * 9 + col] = {val, deter};
}

// helper function for output
ostream& Sudoku::streamOutputHelper(ostream &out) const {
	const string border_ = "+-------+-------+-------+";
    
	//top border
	out << border_ << endl;
    for (int row = 0; row < 9; row++) {
        // left border
        out << "|";
        for (int col = 0; col < 9; col++) {
			// prints number within blocks
            out << " " << layout_[row * 9 + col].first;
            // right borders
            if (col % 3 == 2) 
				out << " |";
        }
        out << endl;
		//checks for 3rd row within block
        if (row % 3 == 2) 
			out << border_ << endl;
    }
    return out;
}

istream& Sudoku::streamInputHelper(istream& in) {
	//clear layout_
	layout_.clear();
	char c;
	
<<<<<<< HEAD
	while (in.get(c)) {        
        if (layout_.size() == 81) {
			break;
=======
	while (in.get(c)) {                                       
		if (c <= '9' && c >= '0') {
			if (c != '0') {
				fixed[column][row] = true ;
			} else {
				fixed[column][row] = false;
			}

			grid[column][row] = c - '0'; //cannot do this: character minus character
			column++;

			if (column > 8) {
				column = 0;
				row++;
			}
>>>>>>> f4d08f9fb5ac4d471a013df96a49b5ff0c33ced0
		}
        if (c <= '9' && c >= '0') {
            layout_.push_back({c - '0', c != '0'});
        }
    }
    return in;
}
