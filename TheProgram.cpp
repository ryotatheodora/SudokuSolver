/*
 * Author: Tammy Le, Ryota Theodora, Yohanes Koeswono
 * file: TheProgram.cpp
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

// driver code for this program
int main(int argc, char **argv)
{
    srand((unsigned int)time(NULL));
    if (argc != 3)
    {
        cerr << "Input: " << argv[0] << " <POPULATION SIZE> , <MAX GENERATION>" << endl;
        return 1;
    }

    // initialize pop_size and max_gen
    int population_size_ = atoi(argv[1]);
    int max_gen_ = atoi(argv[2]);

    cout << "Insert 81-digit to solve: " << endl;

    // reading in from the command line argument for initial puzzle
    shared_ptr<Puzzle> p = make_shared<Sudoku>();
    cin >> *p;
    cout << *p;

    // initialize genetic_algo_ with max generation, pop_size, and initial puzzle
    GeneticAlgorithm<SudokuPopulation> genetic_algo_(max_gen_, population_size_, p);
    Individual best_ = genetic_algo_.run();

    // output GA result
    cout << "Best fit: " << best_.first << "\n";
    cout << *best_.second << endl;

    return 0;
}