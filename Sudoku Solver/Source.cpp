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

	int* easy_test_answer = new int[81]{5, 7, 9, 6, 8, 1, 4, 3, 2, 
										6, 2, 3, 7, 9, 4, 8, 1, 5,
										1, 8, 4, 2, 5, 3, 6, 9, 7,
										7, 1, 6, 8, 3, 5, 9, 2, 4, 
										2, 3, 5, 9, 4, 7, 1, 6, 8, 
										4, 9, 8, 1, 6, 2, 5, 7, 3, 
										8, 4, 2, 3, 1, 6, 7, 5, 9, 
										9, 6, 7, 5, 2, 8, 3, 4, 1, 
										3, 5, 1, 4, 7, 9, 2, 8, 6 };

	// https://www.puzzles.ca/sudoku_puzzles/sudoku_medium_487.html
	int* test_board_medium = new int[81]{0, 0, 0, 0, 0, 0, 3, 0, 0,
										 8, 5, 2, 3, 0, 0, 0, 0, 1,
										 0, 9, 0, 2, 0, 0, 0, 0, 4,
										 9, 7, 4, 0, 0, 0, 0, 0, 0,
										 0, 1, 0, 0, 6, 0, 0, 0, 0, 
										 0, 0, 0, 0, 4, 0, 0, 0, 0,
										 6, 0, 9, 0, 8, 0, 0, 3, 7,
										 3, 0, 0, 0, 0, 0, 0, 6, 0,
										 0, 2, 0, 0, 0, 5, 0, 0, 0 };

	int* medium_test_answer = new int[81]{ 4, 6, 7, 9, 1, 8, 3, 2, 5,
											8, 5, 2, 3, 7, 4, 6 ,9, 1, 
											1, 9, 3, 2, 5, 6, 7, 8, 4,
											9, 7, 4, 5, 2, 3, 8, 1, 6,
											2, 1, 8, 7, 6, 9, 4, 5, 3, 
											5, 3, 6, 8, 4, 1, 2, 7, 9, 
											6, 4, 9, 1, 8, 2, 5, 3, 7, 
											3, 8, 5, 4, 9, 7, 1, 6, 2, 
											7, 2, 1, 6, 3, 5, 9, 4, 8 };

	// Instantiate and set game board
	Board easy_sudoku = Board();
	easy_sudoku.set_board(test_board_easy);
	easy_sudoku.print_board();
	int loop_count_easy = 0;

	// Run solver on easy board
	auto start_easy = high_resolution_clock::now();

	while (easy_sudoku.is_complete() == false) {
		easy_sudoku.annotate_potential_entries();
		easy_sudoku.remove_doubles_and_triples_by_sub_grid();
		std::cout << "Loops: " << ++loop_count_easy << " | Empty Cells: ";
		std::cout << easy_sudoku.empty_cells << std::endl;
	}

	auto stop_easy = high_resolution_clock::now();
	auto duration_easy = duration_cast<milliseconds>(stop_easy - start_easy);
	std::cout << duration_easy.count() << "ms" << std::endl;
	std::cout << "Board is correct: " << easy_sudoku.compare_boards(test_board_easy, easy_test_answer) << std::endl;
	easy_sudoku.print_board();

	Board med_sudoku = Board();
	med_sudoku.set_board(test_board_medium);
	med_sudoku.print_board();
	int loop_count_med = 0;

	// run solver on mediam board
	auto start_med = high_resolution_clock::now();

	while (med_sudoku.is_complete() == false) {
		med_sudoku.annotate_potential_entries();
		med_sudoku.remove_doubles_and_triples_by_sub_grid();
		std::cout << "Loops: " << ++loop_count_med << " | Empty Cells: ";
		std::cout << med_sudoku.empty_cells << std::endl;
		if (loop_count_med > 10) {
			break;
		}
	}

	auto stop_med = high_resolution_clock::now();
	auto duration_med = duration_cast<milliseconds>(stop_med - start_med);
	std::cout << duration_med.count() << "ms" << std::endl;
	std::cout << "Board is correct: " << med_sudoku.compare_boards(test_board_medium, medium_test_answer) << std::endl;
	med_sudoku.print_board();

	delete test_board_medium;
	delete medium_test_answer;
	delete test_board_easy;
	delete easy_test_answer;

	return 0;
}