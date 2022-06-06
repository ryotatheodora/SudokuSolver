/**
 * @file SudokuFitness.h
 * @author Tammy Le, Ryota Theodora, Yohanes Koeswono
 * @date 2022-06-04
 **/
#include "Puzzle.h"
#include "Sudoku.h"
#include "SudokuFitness.h"

using namespace std;

int SudokuFitness::howFit(shared_ptr<Puzzle> &sudoku)
{

    // cast to Sudoku puzzle as pointer
    shared_ptr<Sudoku> sudoku_ = dynamic_pointer_cast<Sudoku>(sudoku);
    int duplicates = 0;

    // duplicates counter method
    auto update_duplicates = [&duplicates](int count[])
    {
        for (int i = 0; i < 10; ++i)
        {
            if (count[i] > 1)
            {
                duplicates += count[i];
            }
        }
    };

    // Check duplicates value within the Sudoku column
    for (int i = 0; i < 9; ++i)
    {
        int count[10] = {0};
        for (int j = 0; j < 9; ++j)
        {
            ++count[sudoku_->value(j, i)];
        }
        update_duplicates(count);
    }

    // Check duplicates value within the Sudoku row
    for (int i = 0; i < 9; ++i)
    {
        int count[10] = {0};
        for (int j = 0; j < 9; ++j)
        {
            ++count[sudoku_->value(i, j)];
        }
        update_duplicates(count);
    }

    // Check duplicates within block of 3x3 within Sudoku 
    for (int i = 0; i < 9; ++i)
    {
        // get the location of the blocks within a 9x9 sudoku
        int row_block = (i / 3) * 3;
        int col_block = (i % 3) * 3;
        int count[10] = {0};
        for (int j = row_block; j < row_block + 3; ++j)
        {
            for (int k = col_block; k < col_block + 3; ++k)
            {
                ++count[sudoku_->value(j, k)];
            }
        }
        update_duplicates(count);
    }
    return duplicates;
}