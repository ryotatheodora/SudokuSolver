/**
 * @file Puzzle.h
 * @author Yohanes
 * @date 2022-05-26
 **/

#ifndef PUZZLE_H_
#define PUZZLE_H_

#include <iostream>
using namespace std;

class Puzzle {
public:
    friend ostream& operator<<(ostream &out, Puzzle &p);    
	friend istream& operator>>(istream &in, Puzzle &p);
	
    Puzzle(){} // constructor
	virtual ~Puzzle(){} // destructor 
};
#endif //PUZZLE_H_