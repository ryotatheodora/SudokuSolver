/**
 * @file SudokuFitness.h
 * @author Yohanes
 * @brief 
 * Notes:
 * 
 * @date 2022-05-26
 **/

#include <iostream>
#include "Puzzle.h"
#include "sudoku.h"
#include "sudokuFitness.h"

#include <set>
using namespace std;

int SudokuFitness::howFit(const puzzle &p) {
    //make copy of puzzle
    shared_ptr<Sudoku> copy = p;

    int fitness = checkDuplicateRow(p) + checkDuplicateColumn(p) + checkAllBlock(p);

    return fitness;
}

// check duplicate in every row of the sudoku
int SudokuFitness::checkDuplicateRow(const Sudoku &s) {
    int duplicate = 0;

    for(int row = 0; i < row; row++) {
        for(int column = 0; column < 9; column++) {
            for(int column + 1 = 0; i < 9; i++) {
                if(s.grid[row][i] == s.grid[row][column]) {
					duplicate++;
				}
            }
        }
    }

    return duplicate;
}

// check duplicate in every column of the sudoku
int SudokuFitness::checkDuplicateColumn(const Sudoku &s) {
    int duplicate = 0;

    for(int column = 0; i < column; column++) {
        for(int row = 0; row < 9; row++) {
            for(int row + 1 = 0; row < 9; row++) {
                if (s.grid[i][column] == s.grid[row][column]) {
					duplicate++;
				}
            }
        }
    }

    return duplicate;
}

// Move from one block to another block
int SudokuFitness::checkAllBlock(const Sudoku &s) {
    int duplicate = 0;
    for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			duplicate += checkDuplicateBlock(i, j, s);
		}
	} 
}

// check duplicates in 3X3 grids of the sudoku
int SudokuFitness::checkDuplicateBlock(const Sudoku &s, int x, int y) {
    int temp[9];
	int duplicate = 0;
    int k = 0;

    // traverse 3*3 grid put the value to the temp 
	for (int row = 0; row < 3; row++) {
		for (int column = 0; column < 3; column++) {
			temp[k] = s.grid[(3 * x) + row][(3 * y) + column];  
			k++;
		}
	}

    // check if there is duplicate value
	for (int i = 0; i < temp.size(); i++) {
		for (int j = i + 1; j < temp.size(); j++) {
			if (temp[i] == temp[j]) {
				duplicate++;
			}
		}
    }

	return duplicate;
}

