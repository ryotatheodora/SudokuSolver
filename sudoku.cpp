/**
 * @file sudoku.cpp
 * @author Yohanes
 * @brief 
 * Notes:
 * 
 * @date 2022-05-26
 **/

#include<iostream>
#include<fstream>
#include<istream>
#include<ostream>

#include"sudoku.h"
using namespace std;


ostream& operator<<(ostream &out, const sudoku &p) {
	 
	out << p.streamOutputHelper(); 
	return out;
}

istream& operator>>(istream &in, sudoku &input) {
	input.streamInputHelper(in);
	return in;
}

sudoku::sudoku() {
    grid = new int*[9];

	for (int i = 0; i < 9; i++) {
		 grid[i] = new int[9];
    }
}