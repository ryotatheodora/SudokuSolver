/**
 * @file Sudoku.h
 * @author Tammy Le, Ryota Theodora, Yohanes Koeswono
 * @brief
 * Notes:
 * 9x9 grid with fixed (isFixed) and initialized data
 * Output operators - used through puzzle inheritance
 * Reads file and ignored anything not between 0 and 9 (first 81 integers)
 * Outputs sudoku puzzle
 * @date 2022-06-04
 **/
#ifndef SUDOKU_H_
#define SUDOKU_H_

#include <vector>
#include <cctype>
#include <string>
#include <iostream>
#include "Puzzle.h"

using namespace std;

class Sudoku : public Puzzle
{
public:
    // constructor
    Sudoku();
    // destructor
    ~Sudoku();
    // helper function for input stream
    istream &streamInputHelper(istream &in) override;
    // helper function for outout stream
    ostream &streamOutputHelper(ostream &out) const override;
    // return value of position row, column on layout_
    int value(int row, int column);
    // returning the bool of a single cell is determined
    bool determined(int row, int column);
    // setting a value of a cell if cell is not determined
    void setValue(int row, int column, int val, bool deter);

private:
    // vector to represent Sudoku layout as a list multiple of 9
    // row * 9 = 1 block
    // row * 9 + col = block position
    vector<pair<int, bool> > layout_;
};

#endif