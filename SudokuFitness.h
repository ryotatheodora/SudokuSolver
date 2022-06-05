/**
 * @file SudokuFitness.h
 * @author Yohanes, Ryota Theodora
 * @brief 
 * Notes:
 * Implements "howFit" for Sudoku objects
 * @date 2022-06-04
 **/

#ifndef SUDOKUFITNESS_H_
#define SUDOKUFITNESS_H_

#include <memory>
#include "Fitness.h"
#include "Puzzle.h"
#include "Sudoku.h"

using namespace std;

class SudokuFitness : public Fitness {
public:
	int howFit(shared_ptr<Puzzle>& sudoku) override;

};
#endif //SUDOKUFITNESS_H_