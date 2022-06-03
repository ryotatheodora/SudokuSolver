/*
* Author: Ryota Theodora
* file: GeneticAlgorithm.h
* Notes: 
* ask the Population for the bestFitness, halting iterations if a solution has been found or 
if the maximum number of generations limit has been reached,
* command the Population to cull 90% of its Puzzles, and
* command the Population to reproduce a newGeneration.
* can choose to output up to 10 puzzles as it executes
* Date: 5/30/2022
*/
#ifndef GENETIC_ALGORITHM_H_
#define GENETIC_ALGORTIHM_H_

#include "Population.h"
#include "Puzzle.h"
#include <limits>
#include <memory>

using namespace std;

template<typename T>
class GeneticAlgorithm {
private:
    int max_generation_;
    shared_ptr<Population> population_;
public:
    GeneticAlgorithm(int max_gen, int pop_size, shared_ptr<Puzzle> &initial);
    Individual run();
};

template<typename T>
GeneticAlgorithm<T>::GeneticAlgorithm(int max_gen, int pop_size, shared_ptr<Puzzle> &initial): max_generation_(max_gen), population_(make_shared<T>(pop_size, initial)){

}

template<typename T>
Individual GeneticAlgorithm<T>::run() {
    Individual best{numeric_limits<int>::max(), nullptr};

    //run until max_gen
    for(int i = 0; i < max_generation_; ++i) {
        //getting best individual
        Individual current_best = population_->bestIndividual();
        //found solution
        if(current_best.first == 0) {
            best = current_best;
            break;
        }
        //update best individual
        if(current_best.first < best.first) {
            best = current_best;
        }
        //cull 90% individuals
        population_->cull(0.9);
        population_->newGeneration();
    }

    return best;
}

#endif