/**
 * @file Reproduction.h
 * @author Le, Tammy
 * @brief Reproduction <<interface>> 
 * Notes:
 * PuzzleFactory uses this class to create new puzzles from old one. 
 * SudokuOffspring implements this class. 
 * Reproduction subclasses must implement a "makeOffspring" method, which takes a Puzzle and returns a new Puzzle.
 * @date 2022-05-26
 **/

#ifndef REPRODUCTION_H_
#define REPRODUCTION_H_
#include "Puzzle.h"
#include <memory>

using namespace std;

class Reproduction {

public:
    // makeOffspring method, takes a puzzle and returns new puzzle
    virtual Puzzle* makeOffspring(Puzzle *p) = 0;
    ~Reproduction() = default;
};
#endif //REPRODUCTION_H_