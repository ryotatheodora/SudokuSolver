/*
* Author: Ryota Theodora
* file: GeneticAlgorithm.h
*   
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
    shared_ptr<Population> population;
public:
    GeneticAlgorithm(int max_gen, int pop_size, shared_ptr<Puzzle> &initial);
    Individual run();
};

template<typename T>
GeneticAlgorithm<T>::GeneticAlgorithm(int max_gen, int pop_size, shared_ptr<Puzzle> &initial): max_gen(max_generation_), population(make_shared<T>(pop_size, initial)){

}

template<typename T>
Individual GeneticAlgorithm::run() {
    Individual best{numeric_limits<int>::max(), nullptr};

    //run until max_gen
    for(int i = 0; i < max_gen; ++i) {
        //getting best individual
        Individual current_best = population->bestIndividual();
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
        population->cull(0.9);
        population->newGeneration();
    }

    return best;
}