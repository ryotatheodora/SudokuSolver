/**
 * @file Puzzle.cpp
 * @author Tammy Le, Ryota Theodora, Yohanes Koeswono
 * @date 2022-06-04
 **/
#include "Puzzle.h"

// helper method to handle output stream
ostream &operator<<(ostream &out, const Puzzle &p)
{
    return p.streamOutputHelper(out);
}
// helper method to handle input stream
istream &operator>>(istream &in, Puzzle &p)
{
    return p.streamInputHelper(in);
}

// destructor
Puzzle::~Puzzle()
{
}
