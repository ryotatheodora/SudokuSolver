/**
 * @file SudokuOffspring.cpp
 * @author Le, Tammy
 * @brief 
 * Notes:
 * The SudokuOffspring class implements "makeOffspring" for Sudoku objects.
 * Only need to implement mutation. 
 * Copy of the original Sudoku, with some probability of changing each variable number in the puzzle as it is copied.
 * @date 2022-05-26
 **/
#ifndef SUDOKUOFFSPRING_H_
#define SUDOKUOFFSPRING_H_

using namespace std;

class SudokuOffspring : public Reproduction {

public:
    Puzzle makeOffspring(Puzzle &p) override;
private:

};
#endif // SUDOKUOFFSPRING_H_