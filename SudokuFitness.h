/**
 * @file SudokuFitness.h
 * @author Yohanes
 * @brief 
 * Notes:
 * Implements "howFit" for Sudoku objects
 * @date 2022-05-26
 **/

#ifndef SUDOKUFITNESS_H_
#define SUDOKUFITNESS_H_

#include <iostream>
#include "Fitness.h"
#include "Puzzle.h"
#include "Sudoku.h"

using namespace std;

class SudokuFitness : public Fitness {
public:
	//constructor
	SudokuFitness();

	int howFit(Puzzle *sudoku);

	int checkDuplicateRow(Sudoku *s);
	int checkDuplicateColumn(Sudoku *s);
    int checkAllBlock(Sudoku *s);
	int checkDuplicateBlock(Sudoku *s, int x, int y);
    
};
#endif //SUDOKUFITNESS_H_