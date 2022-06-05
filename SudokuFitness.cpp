/**
 * @file SudokuFitness.h
 * @author Yohanes, Ryota Theodora
 * @date 2022-06-04
 **/
#include "Puzzle.h"
#include "Sudoku.h"
#include "SudokuFitness.h"

using namespace std;

int SudokuFitness::howFit(shared_ptr<Puzzle>& sudoku) {
    
    //cast to Sudoku puzzle as pointer
    shared_ptr<Sudoku> sudoku_ = dynamic_pointer_cast<Sudoku>(sudoku);
    int duplicates = 0;

    //duplicates counter method
    auto update_duplicates = [&duplicates](int count[]) {
        for(int i = 0; i < 10; i++) {
            if(count[i] > 1) {
                duplicates += count[i];
            }
        }
    };
    
    //check duplicates within column
    for(int i = 0; i < 9; i++) {
        int count[10] = {0};
        for(int j = 0; j < 9; j++) {
            ++count[sudoku_->value(i, j)];
        }
        update_duplicates(count);
    }
<<<<<<< HEAD

    //check duplicates within row
    for(int i = 0; i < 9; i++) {
        int count[10] = {0};
        for(int j = 0; j < 9; j++) {
            ++count[sudoku_->value(i, j)];
=======
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
>>>>>>> f4d08f9fb5ac4d471a013df96a49b5ff0c33ced0
        }
        update_duplicates(count);
    }


    //check duplicates within block
    for(int i = 0; i < 9; i++) {
        //get the location of the blocks within a 9x9 sudoku
        int row_block = (i / 3) * 3;
        int col_block = (i % 3) * 3;
        int count[10] = {0};
        for(int j = row_block; j < row_block + 3; j++) {
            for(int k = col_block; k < col_block + 3; k++) {
                ++count[sudoku_->value(i, j)];
            }
        }
        update_duplicates(count);
    }
    return duplicates;
}