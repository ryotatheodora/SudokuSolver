/**
 * @file SudokuFactory.cpp
 * @author Le, Tammy
 * @date 2022-05-26
 **/

#include "SudokuFactory.h"

//default constructor 
SudokuFactory::SudokuFactory() {
    //instaniate Reproduction object
} 

//method to create new puzzle
Puzzle SudokuFactory::createPuzzle(Puzzle* p) {
    Sudoku copiedP = reproduction->makeOffspring(p);
    return copiedP; //return copied puzzle
}