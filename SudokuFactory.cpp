/**
 * @file SudokuFactory.cpp
 * @author Le, Tammy
 * @date 2022-05-26
 **/

#include "SudokuFactory.h"

//default constructor 
SudokuFactory::SudokuFactory() {
    //instaniate Reproduction object
    reproduction_ = make_shared<SudokuOffspring>();
} 

//method to create new puzzle
// shared_ptr<Puzzle> SudokuFactory::createPuzzle(shared_ptr<Puzzle>& p) {
//     shared_ptr<Puzzle> copiedP = sudokuOffspring.makeOffspring(p);
//     return copiedP; //return copied puzzle
// }
