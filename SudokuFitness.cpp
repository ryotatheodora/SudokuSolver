/**
 * @file SudokuFitness.h
 * @author Yohanes
 * @date 2022-05-26
 **/

#include <iostream>
#include "Puzzle.h"
#include "Sudoku.h"
#include "SudokuFitness.h"

#include <set>
using namespace std;

int SudokuFitness::howFit(shared_ptr<Puzzle>& sudoku) {
    //make copy of puzzle

    shared_ptr<Sudoku> p = dynamic_pointer_cast<Sudoku>(sudoku);

    int fitness = checkDuplicateRow(p) + checkDuplicateColumn(p) + checkAllBlock(p);

    return fitness;
}

// check duplicate in every row of the sudoku
int SudokuFitness::checkDuplicateRow(shared_ptr<Sudoku>& s) {
    int duplicate = 0;

    for(int row = 0; row < 9; row++) {
        for(int column = 0; column < 9; column++) {
            for(int i = column + 1; i < 9; i++) {
                if(s->grid[row][i] == s->grid[row][column]) {
					duplicate++;
				}
            }
        }
    }

    return duplicate;
}

// check duplicate in every column of the sudoku
int SudokuFitness::checkDuplicateColumn(shared_ptr<Sudoku>& s) {
    int duplicate = 0;

    for(int column = 0; column < 9; column++) {
        for(int row = 0; row < 9; row++) {
            for(int i = row + 1; i < 9; i++) {
                if (s->grid[i][column] == s->grid[row][column]) {
					duplicate++;
				}
            }
        }
    }

    return duplicate;
}

// Move from one block to another block
int SudokuFitness::checkAllBlock(shared_ptr<Sudoku>& s) {
    int duplicate = 0;
    for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			duplicate += checkDuplicateBlock(s, i, j);
		}
	}
    return duplicate;
}

// check duplicates in 3X3 grids of the sudoku
int SudokuFitness::checkDuplicateBlock(shared_ptr<Sudoku>& s, int x, int y) {
    int temp[9];
	int duplicate = 0;
    int k = 0;

    // traverse 3*3 grid put the value to the temp 
	for (int row = 0; row < 3; row++) {
		for (int column = 0; column < 3; column++) {
			temp[k] = s->grid[(3 * x) + row][(3 * y) + column];  
			k++;
		}
	}

    // check if there is duplicate value
	for (int i = 0; i < 9; i++) {
		for (int j = i + 1; j < 9; j++) {
			if (temp[i] == temp[j]) {
				duplicate++;
			}
		}
    }
	return duplicate;
}

