/**
 * @file PuzzleFactory.cpp
 * @author Le, Tammy
 * @date 2022-05-26
 **/

#include "PuzzleFactory.h"

//method to create new puzzle
shared_ptr<Puzzle> PuzzleFactory::createPuzzle(shared_ptr<Puzzle> &p) {
    shared_ptr<Puzzle> copiedP = reproduction->makeOffspring(p);
    return copiedP; //return copied puzzle
}