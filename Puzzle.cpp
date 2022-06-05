/**
 * @file Puzzle.cpp
 * @author Yohanes, Ryota Theodora
 * @date 2022-06-04
**/

#include "Puzzle.h"

ostream& operator<<(ostream &out, const Puzzle &p) {
    return p.streamOutputHelper(out);
}

istream& operator>>(istream &in, Puzzle &p) {
    return p.streamInputHelper(in);
}

// destructor
Puzzle::~Puzzle() {
}

