/**
 * @file SudokuOffspring.cpp
 * @author Le, Tammy
 * @date 2022-05-26
 **/

#include "SudokuOffspring.h"

//helper function to retreive probability
bool getProbability() {
    int random = rand() % 100 + 1;
    return random <= 5;
}

// method to make offspring 
// (uses the method in sudoku class where that method 
// checked if the values are fixed or variable)
Sudoku makeOffspring(Sudoku *p) {
    // code for make offspring here - pseudocode:

    //make copy of puzzle
    Sudoku copy = p;
    //visit each cell (x,y) - double for loop bc matrix 

    int size = sizeof(p->grid); 

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++ ) {
            if(!p->isFixed(i, j) && getProbability()) { //isFixed coming from yohanes sudoku class probability
                // then change value
                copy.grid[i][j] = rand() % 10 + 1; 
            }
        }
    }
    return copy;
}