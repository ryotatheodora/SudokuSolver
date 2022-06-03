/**
 * @file Fitness.h
 * @author Yohanes
 * @brief Notes: Fitness is used by a Population to evaluate individual Puzzles
 * Fitness subclasses must implement a "howFit" method, which takes a 
 * Puzzle (subclass) object and returns an int
 * @date 2022-05-26
 **/

#ifndef FITNESS_H_
#define FITNESS_H_

#include <iostream>
#include <memory>
#include "Puzzle.h"
using namespace std;

class Fitness {
public:
	virtual int howFit(shared_ptr<Puzzle>& p) = 0;
	virtual ~Fitness() = default; 
};
#endif //FITNESS_H_
