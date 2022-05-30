/*
* Author: Ryota Theodora
* file: SudokuPopulation.cpp
*   
* Date: 5/30/2022
*/

#include "SudokuPopulation.h"

SudokuPopulation::SudokuPopulation(int pop_size, shared_ptr<Puzzle> &puzzle){
    size_ = pop_size;
    fitness = make_shared<SudokuFitness>();
    factory = make_shared<sudokuFactory>();
    for(int i = 0; i < size; i++) {
        shared_ptr<Puzzle> p = factory->createPuzzle(puzzle);
        puzzle_vector_.emplace_back(fitness->howFit(p), p);
    }
}

void Population::cull(double x) {
    sort(puzzle_vector_.begin(), puzzle_vector_.end());
    int left = (1- x) * size;
    left = max(1, left);;
    puzzle_vector_.erase(puzzle_vector_.begin() + left, puzzle_vector_.end());
}

void SudokuPopulation::newGeneration() {
    int remain_ = puzzle_vector_.size();
    int i = 0;
    while ((int)puzzle_vector_.size() < size) {
        shared_ptr<Puzzle> p = factory->createPuzzle(puzzle_vector_[i].second);
        puzzle_vector_.emplace_back(fitness->howFit(p), p);
        if((i+=1) == remain_)
            return 0;
        else
            i + 1;
    }
}

Fitness Population::bestFitness(Puzzle current) {
    auto it = min_element(puzzle_vector_.begin(), puzzle_vector_.end());
    return it->first;
}

Individual Population::bestIndividual(Fitness fitness) {
    return *min_element(puzzle_vector_.begin(), puzzle_vector_.end());
}