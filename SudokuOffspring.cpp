/**
 * @file SudokuOffspring.cpp
 * @author Le, Tammy
 * @date 2022-05-26
 **/

#include "SudokuOffspring.h"

// method to make offspring 
// (uses the method in sudoku class where that method 
// checked if the values are fixed or variable)
shared_ptr<Sudoku> makeOffspring(shared_ptr<Sudoku> &p) {
    // code for make offspring here - pseudocode:

    //make copy of puzzle
    shared_ptr<Sudoku> copy = p;
    //visit each cell (x,y) - double for loop bc matrix 
    int x = 0;
    int y = 0;
    int size = sizeof(p->grid); 

    for (int i = 1; i < size; i++) {
        for (int j = 1; j < size; j++ ) {
            if(!p.isFixed(i, j) && getProbability()) { //isFixed coming from yohanes sudoku class
                // then change value
                copy->grid[i][j] = rand() % 10 + 1; 
            }
        }
    }
    return copy;
}
//helper function to retreive probability
bool getProbability() {
    int random = rand() % 100 + 1;
    return random <= 5;
}