/**
 * @file PuzzleFactory.cpp
 * @author Le, Tammy
 * @date 2022-05-26
 **/
#include "PuzzleFactory.h"

PuzzleFactory::~PuzzleFactory() {
}

shared_ptr<Puzzle> PuzzleFactory::createPuzzle(shared_ptr<Puzzle> &p) {
    return reproduction_->makeOffspring(p);
}