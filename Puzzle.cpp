/**
 * @file Puzzle.cpp
 * @author Yohanes
 * @date 2022-05-26
 **/

#include "Puzzle.h"

ostream& operator<<(ostream &out, Puzzle &p) {
    return p.streamOutputHelper(out);
}

istream& operator>>(istream &in, Puzzle &p) {
    return p.streamInputHelper(in);
}
