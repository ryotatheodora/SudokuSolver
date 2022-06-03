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
	int howFit(shared_ptr<Puzzle>& sudoku) override;

	int checkDuplicateRow(shared_ptr<Sudoku>& s);
	int checkDuplicateColumn(shared_ptr<Sudoku>& s);
    int checkAllBlock(shared_ptr<Sudoku>& s);
	int checkDuplicateBlock(shared_ptr<Sudoku>& s, int x, int y);
    
};
#endif //SUDOKUFITNESS_H_