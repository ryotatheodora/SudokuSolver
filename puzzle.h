/* puzzle.h
*/

#pragma once
#include<iostream>
using namespace std;

class puzzle {
public:
    friend ostream& operator<<(ostream &out, puzzle &p);    
	friend istream& operator>>(istream &in, puzzle &p);
	
    puzzle(){} // constructor
	virtual ~puzzle(){} // destructor 
};