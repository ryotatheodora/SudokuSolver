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
        cerr << "Input: " << argv[0] << " <POPULATION SIZE> , <MAX GENERATION>" << endl;
        return 1;
    }

    //initialize pop_size and max_gen
    int population_size_ = atoi(argv[1]);
    int max_gen_ = atoi(argv[2]);

    string file;
    cin >> file;

    ifstream ifin(file);

    //reading in from the command line argument for initial puzzle
    shared_ptr<Puzzle> puzzle = make_shared<Sudoku>();
    ifin >> *puzzle;
    cout << *puzzle;

    //initialize genetic_algo_ with max generation, pop_size, and initial puzzle
    GeneticAlgorithm<SudokuPopulation> genetic_algo_(max_gen_, population_size_, puzzle);
    Individual best_ = genetic_algo_.run();

    //output result
    cout << "Best fit: " << best_.first << "\n";
    cout << *best_.second << endl;

    return 0;
}