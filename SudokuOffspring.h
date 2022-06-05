/**
 * @file SudokuOffspring.cpp
 * @author Tammy Le, Ryota Theodora
 * @brief 
 * Notes:
 * The SudokuOffspring class implements "makeOffspring" for Sudoku objects.
 * Only need to implement mutation. 
 * Copy of the original Sudoku, with some probability of changing each variable number in the puzzle as it is copied.
 * @date 2022-06-04
 **/
#ifndef SUDOKUOFFSPRING_H_
#define SUDOKUOFFSPRING_H_

#include "Puzzle.h"
#include "Reproduction.h"
#include "Sudoku.h"
#include <memory>
#include <functional>
#include <random>

using namespace std;

class SudokuOffspring : public Reproduction {

public:
     shared_ptr<Puzzle> makeOffspring(shared_ptr<Puzzle>& p) override;
 };
 #endif // SUDOKUOFFSPRING_H_
