/**
 * @file PuzzleFactory.h
 * @author Le, Tammy
 * @brief PuzzleFactory <<interface>> 
 * Notes:
 * SudokuFactory implements this class. This class is to create new puzzles from old ones. 
 * @date 2022-05-26
 **/
#ifndef PUZZLEFACTORY_H_
#define PUZZLEFACTORY_H_

#include "Puzzle.h"
#include "Reproduction.h"
#include <memory>

using namespace std;

class PuzzleFactory {

public:
    //method
    virtual Puzzle createPuzzle(Puzzle* p) = 0;
    //destructor 
    virtual ~PuzzleFactory() = 0;
    shared_ptr<Reproduction> reproduction;
};

#endif //PUZZLEFACTORY_H_