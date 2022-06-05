/**
 * @file Puzzle.h
 * @author Yohanes, Ryota Theodora
 * @date 2022-06-04
 **/

#ifndef PUZZLE_H_
#define PUZZLE_H_

#include <iostream>
using namespace std;

class Puzzle {
public:
    friend ostream& operator<<(ostream& out, const Puzzle& p);    
	friend istream& operator>>(istream& in, Puzzle& p);
	virtual ~Puzzle(); // destructor 

private:
    virtual istream& streamInputHelper(istream& in) = 0;
    virtual ostream& streamOutputHelper(ostream& out) const = 0;
};
#endif //PUZZLE_H_