/*
** Ben Pittman
** Greg Smith
** Calvin Winston Fei
** Term Project - Source.cpp
** Static class for checking solutions.
** Assumptions: Assumes valid board size and 1D memory allocation
*/

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <set>
#include "board.h"
#include <chrono>
#include <string>

using namespace std::chrono;

int main() {
	// https://www.puzzles.ca/sudoku_puzzles/sudoku_easy_487.html
	int* test_board_easy = new int[81]{ 0, 7, 0, 0, 0, 1, 0, 0, 0,
										6, 0, 0, 0, 0, 0, 0, 0, 0, 
										0, 0, 0, 0, 5, 3, 0, 0, 0,
										0, 0, 0, 8, 0, 0, 0, 2, 0,
										0, 3, 0, 0, 4, 7, 1, 6, 0,
										4, 0, 0, 0, 0, 0, 5, 7, 0,
										0, 0, 0, 0, 1, 0, 7, 5, 0,
										0, 6, 0, 5, 2, 0, 0, 4, 0,
										3, 0, 0, 0, 0, 9, 0, 8, 6 };

	// Instantiate and set game board
	Board easy_sudoku = Board();
	easy_sudoku.set_board(test_board_easy);
	easy_sudoku.print_board();

	// Initial run of annotate
	auto start = high_resolution_clock::now();
	easy_sudoku.annotate_potential_entries();
	easy_sudoku.remove_doubles_and_triples_by_sub_grid();
	auto stop = high_resolution_clock::now();
	auto duration = duration_cast<microseconds>(stop - start);
	std::cout << duration.count() << "ms" << std::endl;
	//easy_sudoku.print_cell(76);

	std::cout << easy_sudoku.empty_cells << std::endl;

	// Second run
	easy_sudoku.remove_doubles_and_triples_by_sub_grid();
	easy_sudoku.annotate_potential_entries();
	std::cout << easy_sudoku.empty_cells << std::endl;

	// Third run
	easy_sudoku.remove_doubles_and_triples_by_sub_grid();
	easy_sudoku.annotate_potential_entries();
	std::cout << easy_sudoku.empty_cells << std::endl;

	// Fourth run
	easy_sudoku.remove_doubles_and_triples_by_sub_grid();
	easy_sudoku.annotate_potential_entries();
	easy_sudoku.annotate_potential_entries();
	std::cout << easy_sudoku.empty_cells << std::endl;
	easy_sudoku.print_board();

	easy_sudoku.print_cell(48);
	easy_sudoku.print_cell(53);
	easy_sudoku.print_cell(75);
	easy_sudoku.print_cell(76);

	delete test_board_easy;

	return 0;
}