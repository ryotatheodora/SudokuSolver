/*
* Author: Ryota Theodora
* file: Population.h
*   
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
private:
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
	void cull(int x);

	/*
	* method: pure virtual bestFitness
	* returns the fitness of the best puzzle in the current generation
	*/
	virtual Fitness bestFitness(Puzzle current) = 0;

	/*
	* method: pure Virtual bestIndividuals
	* returns the puzzle with the highest fitness
	*/
	virtual Individual bestIndividual(Fitness fitness) = 0;

};
#endif