/*
* Author: Ryota Theodora
* file: SudokuPopulation.h
*   
* Date: 5/30/2022
*/


#ifndef SUDOKU_POPULATION_H_
#define SUDOKU_POPULATION_H_

#include "Population.h"
#include "Sudoku.h"
#include "SudokuFitness.h"
#include "SudokuFactory.h"

#include <memory>
#include <algorithm>

using namespace std;

class SudokuPopulation: public Population {
public:
    SudokuPopulation(int pop_size, shared_ptr<Puzzle> &puzzle);
    void cull(double x);
    void newGeneration();
    int bestFitness();
    Individual bestIndividual();
};

#endif