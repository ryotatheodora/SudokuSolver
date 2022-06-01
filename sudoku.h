/**
 * @file Sudoku.h
 * @author Yohanes
 * @brief 
 * Notes:
 * 
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
	Sudoku();
	~Sudoku();

    // returns a string representation of the sudoku
	string streamOutputHelper() const;

    // read a puzzle in a compact text format
    void streamInputHelper(istream &in);
	
	int **grid;
	int fitnessScore;
};
#endif //SUDOKU_H_