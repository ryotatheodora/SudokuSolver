/**
 * @file SudokuOffspring.cpp
 * @author Tammy Le, Ryota Theodora
 * @date 2022-06-04
 **/
#include "SudokuOffspring.h"

shared_ptr<Puzzle> SudokuOffspring::makeOffspring(shared_ptr<Puzzle>& puzzle) {
    shared_ptr<Sudoku> puzzle_ = dynamic_pointer_cast<Sudoku>(puzzle);
    const int probability = 2;

    // Initializing random generator
    random_device random;
    //Mersenne Twister 19937 generator
    mt19937 mt(random());

    auto range_of_100 = bind(uniform_int_distribution<int>((0, 99)), mt);
    auto range_of_9 = bind(uniform_int_distribution<int>(1, 9), mt);

    shared_ptr<Sudoku> sudoku_ = make_shared<Sudoku>();
    for(int i = 0; i < 9; ++i) {
        for(int j = 0; j < 9; ++j) {
            int val = puzzle_->value(i, j);
            bool deter = puzzle_->determined(i, j);

            if(val == 0 || (range_of_100() < probability && !deter)) {
                val = range_of_9();
            }
            sudoku_->setValue(i, j, val, deter);
        }
    }

    return sudoku_;
}
