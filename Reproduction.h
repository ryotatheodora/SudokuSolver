/**
 * @file Reproduction.h
 * @author Le, Tammy
 * @brief Reproduction <<interface>> 
 * Notes:
 * PuzzleFactory uses this class to create new puzzles from old one. 
 * SudokuOffspring implements this class. 
 * @date 2022-05-26
 **/

#ifndef REPRODUCTION_H_
#define REPRODUCTION_H_
#include "Puzzle.h"
#include <memory>

using namespace std;

class Reproduction {

public:
    virtual shared_ptr<Puzzle> makeOffspring(shared_ptr<Puzzle> &p) = 0;
    virtual ~Reproduction() = default;
};
#endif //REPRODUCTION_H_