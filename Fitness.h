/**
 * @file Fitness.h
 * @author Yohanes
 * @date 2022-05-26
 **/

#ifndef FITNESS_H_
#define FITNESS_H_

#include <iostream>
#include "Puzzle.h"
using namespace std;

class Fitness {
public:
	virtual int howFit(const Puzzle &p) = 0;    
};
#endif //FITNESS_H_
