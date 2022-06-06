/**
 * @file Puzzle.h
 * @author Tammy Le, Ryota Theodora, Yohanes Koeswono
 * @date 2022-06-04
 **/
#ifndef PUZZLE_H_
#define PUZZLE_H_

#include <iostream>
using namespace std;

class Puzzle
{
public:
    // method to hand output stream
    friend ostream &operator<<(ostream &out, const Puzzle &p);
    // method to handle input stream
    friend istream &operator>>(istream &in, Puzzle &p);
    // destructor - deallocate memory and cleanup
    virtual ~Puzzle();

private:
    // helper method to hand input stream
    virtual istream &streamInputHelper(istream &in) = 0;
    // helper method to hand output stream
    virtual ostream &streamOutputHelper(ostream &out) const = 0;
};
#endif // PUZZLE_H_