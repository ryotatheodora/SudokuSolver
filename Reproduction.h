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

using namespace std;

class Reproduction {

public:
    virtual Puzzle makeOffspring(Puzzle &p) = 0;
    virtual ~Reproduction() = default;
private:

};
#endif //REPRODUCTION_H_