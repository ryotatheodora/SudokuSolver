/*
* Author: Ryota Theodora
* file: TheProgram.cpp
*   
* Date: 5/30/2022
*/

#include "SudokuPopulation.h"
#include "GeneticAlgorithm.h"
#include "Sudoku.h"

#include <limits>
#include <fstream>
#include <string>
#include <iostream>
#include <memory>

using namespace std;

int main(int argc, char **argv) {
    if(argc != 3) {
        cerr << "Usage: " << argv[0] << " <POPULATION SIZE> , <MAX GENERATION>" << endl;
        return 1;
    }

    //initialize pop_size and max_gen
    int population_size_ = atoi(argv[1]);
    int max_gen_ = atoi(argv[2]);


    /*
     * Not sure how the input should be read
     * cmd line or file
     */

    //initialize genetic_algo_ with max generation, pop_size, and initial puzzle
    GeneticAlgorithm<SudokuPopulation> genetic_algo_(max_generation_, population_size_, puzzle);
    Individual best_ = genetic_algo_.run();

    //output result
    cout << "Best fit: " << best.first << "\n";
    cout << *best.second;

    return 0;


}