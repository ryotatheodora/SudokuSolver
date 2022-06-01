/**
 * @file Puzzle.cpp
 * @author Yohanes
 * @brief 
 * Notes:
 * 
 * @date 
 **/

#include "Puzzle.h"

ostream& operator<<(ostream &out, Puzzle &p) {
    return p.printout(out);
}

istream& operator>>(istream &in, Puzzle &p) {
    return p.readin(in);
}
/*
 constructor
*/
Puzzle::Puzzle(){
}

/*
 destructor
*/
Puzzle::~Puzzle() {
}