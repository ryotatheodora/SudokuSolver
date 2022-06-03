/**
 * @file Sudoku.h
 * @author Yohanes
 * @brief 
 * Notes:
 * 9x9 grid with fixed (isFixed) and initialized data
 * Output operators - used through puzzle inheritance
 * Reads file and ignored anything not between 0 and 9 (first 81 integers)
 * Outputs sudoku puzzle
 * @date 2022-05-26
 **/

#ifndef SUDOKU_H_
#define SUDOKU_H_

#include <iostream>
#include "Puzzle.h"
#include "string"

class Sudoku : public Puzzle { 

public:
    friend ostream& operator<<(ostream &out, Sudoku &p);
	friend istream& operator>>(istream &in, Sudoku &p);
    // constructor
	Sudoku();
    // destructor
	~Sudoku();

    // returns a string representation of the sudoku
	ostream &streamOutputHelper(ostream &out) const override;

    // read a puzzle in a compact text format
    istream &streamInputHelper(istream &in) override;

    bool **fixed;
    bool isFixed(int i, int j);
	
	int **grid;
	int fitnessScore;
};
#endif //SUDOKU_H_
