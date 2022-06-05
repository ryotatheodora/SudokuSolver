/**
* @file SudokuPopulation.cpp
* @author Ryota Theodora
* Date: 6/2/2022
**/

#include "SudokuPopulation.h"

SudokuPopulation::SudokuPopulation(int pop_size, shared_ptr<Puzzle>& puzzle){
    size_ = pop_size;
    fitness_ptr_ = make_shared<SudokuFitness>();
    factory_ptr_ = make_shared<SudokuFactory>();
    for(int i = 0; i < size_; i++) {
        shared_ptr<Puzzle> p = factory_ptr_->createPuzzle(puzzle);
        puzzle_vector_.emplace_back(fitness_ptr_->howFit(p), p);
    }
}

void SudokuPopulation::cull(double x) {
    //sorts the vector using the C++ sorting feature
    sort(puzzle_vector_.begin(), puzzle_vector_.end());
    int left = (1- x) * size_;
    left = max(1, left);
    puzzle_vector_.erase(puzzle_vector_.begin() + left, puzzle_vector_.end());
}

void SudokuPopulation::newGeneration() {
    int remain_ = puzzle_vector_.size();
    int i = 0;
    while ((int)puzzle_vector_.size() < size_) {
        shared_ptr<Puzzle> p = factory_ptr_->createPuzzle(puzzle_vector_[i].second);
        puzzle_vector_.emplace_back(fitness_ptr_->howFit(p), p);
        if((i+=1) == remain_)
            return;
        else
            i++;
    }
}

int SudokuPopulation::bestFitness() {
    auto it = min_element(puzzle_vector_.begin(), puzzle_vector_.end());
    return it->first;
}

Individual SudokuPopulation::bestIndividual() {
    return *min_element(puzzle_vector_.begin(), puzzle_vector_.end());
}