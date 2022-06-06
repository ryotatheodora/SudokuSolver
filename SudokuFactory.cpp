/**
 * @file SudokuFactory.cpp
 * @author Tammy Le, Ryota Theodora, Yohanes Koeswono
 * @date 2022-05-26
 **/
#include "SudokuFactory.h"

// default constructor
SudokuFactory::SudokuFactory()
{
    // instaniate Reproduction object
    reproduction_ = make_shared<SudokuOffspring>();
}