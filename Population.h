/*
* Author: Ryota Theodora
* file: Population.h
* Notes: Population is a container for a number of puzzles - Use a vector of puzzles
* Cull puzzles from the population
* Constructors that create initial randomized puzzles
* new generation method that creats x number of new puzzles using the top 10%
* best fitness returns the lowest fitness score (best score)
* best individual returns the puzzle with the best fitness
* Date: 5/30/2022
*/
#ifndef POPULATION_H_
#define POPULATION_H_

#include "Fitness.h"
#include "PuzzleFactory.h"

#include <vector>
#include <memory>

using namespace std;
using Individual = pair<int, shared_ptr<Puzzle>>;

class Population {
protected:
	int size_;
	vector<Individual> puzzle_vector_;
	shared_ptr<Fitness> fitness_ptr_;
	shared_ptr<PuzzleFactory> factory_ptr_;

public:
	/*
	* method: Constructor
	* Create an initial, random set of puzzles
	*/
	Population() = default;

	/*
	* method: Destructor
	* deallocate memory and cleanup
	*/
	virtual ~Population();

	/*
	* method: pure virtual newGeneration
	* Produces a new generation with N individuals for every single individual in the old generation.
	* Presumably after the old generation has been culled,
	* so that the population size stays constant from one generation to the next.
	*/
	virtual void newGeneration() = 0;

	/*
	* method: cull
	* eliminates x% least fit of a generation
	*/
	virtual void cull(double x) = 0;

	/*
	* method: pure virtual bestFitness
	* returns the fitness of the best puzzle in the current generation
	*/
	virtual int bestFitness() = 0;

	/*
	* method: pure Virtual bestIndividuals
	* returns the puzzle with the highest fitness
	*/
	virtual Individual bestIndividual() = 0;

};
#endif