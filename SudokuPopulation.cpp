/**
 * @file SudokuPopulation.cpp
 * @author Tammy Le, Ryota Theodora, Yohanes Koeswono
 * Date: 6/2/2022
 **/
#include "SudokuPopulation.h"

// method: SudokuPopulation implements all Population methods for Sudoku objects,
// using a SudokuFitness object to accomplish its tasks
SudokuPopulation::SudokuPopulation(int pop_size, shared_ptr<Puzzle> &puzzle)
{
    size_ = pop_size;
    fitness_ptr_ = make_shared<SudokuFitness>();
    factory_ptr_ = make_shared<SudokuFactory>();
    for (int i = 0; i < size_; i++)
    {
        shared_ptr<Puzzle> p = factory_ptr_->createPuzzle(puzzle);
        puzzle_vector_.emplace_back(fitness_ptr_->howFit(p), p);
    }
}

// method: cull which eliminates the X% least fit members of a generation
void SudokuPopulation::cull(double x)
{
    // sorts the vector using the C++ sorting feature
    sort(puzzle_vector_.begin(), puzzle_vector_.end());
    int left = (1 - x) * size_;
    left = max(1, left);

    puzzle_vector_.erase(puzzle_vector_.begin() + left, puzzle_vector_.end());
}

// method: that produces a new generation with N individuals for every single individual in the old generation —
// presumably after the old generation has been culled,
// so the population size stays constant from one generation to the next
void SudokuPopulation::newGeneration()
{
    int remain_ = puzzle_vector_.size();
    int i = 0;
    while ((int)puzzle_vector_.size() < size_)
    {
        shared_ptr<Puzzle> p = factory_ptr_->createPuzzle(puzzle_vector_[i].second);
        puzzle_vector_.emplace_back(fitness_ptr_->howFit(p), p);
        if ((i += 1) == remain_)
            return;
        else
            i++;
    }
}

// method: bestFitness returns the fitness of the best Puzzle in the current generation
int SudokuPopulation::bestFitness()
{
    auto it = min_element(puzzle_vector_.begin(), puzzle_vector_.end());
    return it->first;
}

// method: bestIndividual returns the Puzzle with the highest fitness
Individual SudokuPopulation::bestIndividual()
{
    return *min_element(puzzle_vector_.begin(), puzzle_vector_.end());
}