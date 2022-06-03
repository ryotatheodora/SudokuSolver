/*
* Author: Ryota Theodora
* file: SudokuPopulation.h
* Implements population, uses sudokuFitness and sudokuFactory 
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
    // initialized population 
    SudokuPopulation(int pop_size, shared_ptr<Puzzle>& puzzle);
    // removes the boom x percentage of puzzle based off of fitness
    void cull(double x) override;
    void newGeneration() override;
    // returns the fitness value of the best puzzle
    int bestFitness() override;
    //returns the puzzle with the best fitness score
    Individual bestIndividual() override;
};
#endif