/**
 * @file SudokuFitness.h
 * @author Yohanes
 * @brief 
 * Notes:
 * 
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
	int howFit(const Puzzle&);

	int checkDuplicateRow(const Sudoku &s);
	int checkDuplicateColumn(const Sudoku &s);
	int checkDuplicateBlock(int x, int y, const Sudoku &s);
};
#endif //SUDOKUFITNESS_H_