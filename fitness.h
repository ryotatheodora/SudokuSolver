/**
 * @file fitness.h
 * @author Yohanes
 * @brief 
 * Notes:
 * 
 * @date 2022-05-26
 **/

#pragma once

#include <iostream>
#include "puzzle.h"
using namespace std;

class fitness {
public:
	virtual int howFit(const puzzle &p) = 0;    
};