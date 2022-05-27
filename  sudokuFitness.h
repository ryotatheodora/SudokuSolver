/**
 * @file sudokuFitness.h
 * @author Yohanes
 * @brief 
 * Notes:
 * 
 * @date 2022-05-26
 **/

#pragma once
#include<iostream>
#include "fitness.h"
#include "puzzle.h"
#include"sudoku.h"

using namespace std;

class sudokuFitness : public fitness
{
public:
	int howFit(const puzzle&);

	int checkDuplicateRow(const sudoku &s);
	int checkDuplicateColumn(const sudoku &s);
	int checkDuplicateBlock(int x, int y, const sudoku &s);
};