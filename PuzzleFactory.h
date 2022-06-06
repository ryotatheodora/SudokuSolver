/**
 * @file PuzzleFactory.h
 * @author Tammy Le, Ryota Theodora, Yohanes Koeswono
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

class PuzzleFactory
{
public:
    // method: creates new puzzles from old puzzles
    shared_ptr<Puzzle> createPuzzle(shared_ptr<Puzzle> &p);
    // destructor
    virtual ~PuzzleFactory();

protected:
    shared_ptr<Reproduction> reproduction_;
};

#endif // PUZZLEFACTORY_H_