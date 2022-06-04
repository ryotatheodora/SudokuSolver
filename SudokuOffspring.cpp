/**
 * @file SudokuOffspring.cpp
 * @author Le, Tammy
 * @date 2022-05-26
 **/

#include "SudokuOffspring.h"

SudokuOffspring::SudokuOffspring(){}

SudokuOffspring::~SudokuOffspring(){}

//helper function to retreive probability
bool SudokuOffspring::getProbability() {
    int random = rand() % 100 + 1;
    /* cout << "random: " << random << " change? " << (random <= 50) << endl; */
    return random <= 3;
}

// method to make offspring 
// (uses the method in sudoku class where that method 
// checked if the values are fixed or variable)
shared_ptr<Puzzle> SudokuOffspring::makeOffspring(shared_ptr<Puzzle>& p) {
    //make copy of puzzle
    shared_ptr<Puzzle>& copy = p;
    //visit each cell (x,y) - double for loop bc matrix 

    int size = sizeof(p->grid); 

    for (int i = 0; i < size + 1; i++) {
        for (int j = 0; j < size + 1; j++ ) {
            if(!p->isFixed(i, j) && getProbability()) { //isFixed coming from yohanes sudoku class probability
                // then change value
                int random = rand() % 10;
                /* cout << "value changed: " << p->grid[i][j] << " to: " << random << endl; */
                copy->grid[i][j] = random; // adding 48 to correlate with ASCII 0 - 9
            }
        }
    }
    return copy;
}