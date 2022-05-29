#ifndef POPULATION_H_
#define POPULATION_H_

#include <iostream>
#include <string>
using namespace std;

class Population: public Fitness, public Puzzle, public PuzzleFactory {

private:
	int kLength_;
	int kCrossover_;
	int kPopulation_Limit_;
	int generation_;
	int current_population_;
	float kMutation_frequency_;
	float kDeath_fitness_;
	float kReproduction_fitness_;

public:
	/*
	* method: Constructor
	* Create an initial, random set of puzzles
	*/
	Population();

	/*
	* method: newGeneration
	* Produces a new generation with N individuals for every single individual in the old generation.
	* Presumably after the old generation has been culled, 
	* so that the population size stays constant from one generation to the next.
	*/
	void newGeneration();

	/*
	* method: cull
	* eliminates X% least fit of a generation 
	*/
	void cull(Puzzle puzzle, int X);

	/*
	* method: bestFitness
	* returns the fitness of the best puzzle in the current generation
	*/
	Fitness bestFitness(Puzzle current);
	
	/*
	* method: bestIndividuals
	* returns the puzzle with the highest fitness
	*/
	Puzzle bestIndividual(Fitness fitness);

};
#endif