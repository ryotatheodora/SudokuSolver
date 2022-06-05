/**
 * @file SudokuOffspring.cpp
 * @author Tammy Le, Ryota Theodora
 * @date 2022-06-04
 **/
#include "SudokuOffspring.h"

shared_ptr<Puzzle> SudokuOffspring::makeOffspring(shared_ptr<Puzzle>& puzzle) {
    shared_ptr<Sudoku> p = dynamic_pointer_cast<Sudoku>(puzzle);
    const int probability = 5;

<<<<<<< HEAD
    // Initializing random generator
    random_device random;
    //Mersenne Twister 19937 generator
    mt19937 mt(random());

    auto range_of_100 = bind(uniform_int_distribution<int>((0, 99)), mt);
    auto range_of_9 = bind(uniform_int_distribution<int>(1, 9), mt);

    shared_ptr<Sudoku> sudoku_ = make_shared<Sudoku>();
    for(int i = 0; i < 9; i++) {
        for(int j = 0; j < 9; j++) {
            int val = p->value(i, j);
            bool deter = p->determined(i, j);

            if(val == 0 || (range_of_100() < probability && !deter)) {
                val = range_of_9();
=======
//helper function to retreive probability
bool SudokuOffspring::getProbability() {
    int random = rand() % 1000 + 1;
    /* cout << "random: " << random << " change? " << (random <= 50) << endl; */
    return random <= 2;
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
            if(!p->isFixed(i, j)) { //isFixed coming from yohanes sudoku class probability
                // then change value
                if(copy->grid[i][j] == 0 || getProbability() ){
                    int random = rand() % 10;
                    copy->grid[i][j] = random; // adding 48 to correlate with ASCII 0 - 9
                }
>>>>>>> f4d08f9fb5ac4d471a013df96a49b5ff0c33ced0
            }
            sudoku_->setValue(i, j, val, deter);
        }
    }
    return sudoku_;
}
