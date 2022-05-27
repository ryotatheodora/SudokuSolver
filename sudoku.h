/**
 * @file sudoku.h
 * @author Yohanes
 * @brief 
 * Notes:
 * 
 * @date 2022-05-26
 **/

#pragma once
#include<iostream>
#include"puzzle.h"

#include"string"

class sudoku : public puzzle { 

public:
    friend ostream& operator<<(ostream &out, sudoku &p);
	friend istream& operator>>(istream &in, sudoku &p);
	sudoku();
	~sudoku();

    // returns a string representation of the sudoku
	string streamOutputHelper() const;

    // read a puzzle in a compact text format
    void streamInputHelper(istream &in);
	
private :
	int **grid;
	int fitnessScore;
};