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

	int* test_board_easy2 = new int[81]{ 0, 0, 0, 0, 9, 0, 0, 0, 0, 
										 0, 3, 0, 0, 0, 0, 7, 4, 2, 
										 6, 1, 0, 0, 3, 0, 0, 0, 0,
										 0, 0, 8, 0, 0, 0, 0, 0, 0, 
										 0, 2, 9, 1, 4, 7, 0, 0, 8,
										 4, 5, 0, 0, 0, 0, 0, 7, 0,
										 0, 4, 0, 0, 0, 0, 0, 6, 0,
										 5, 0, 0, 6, 0, 0, 0, 3, 0,
										 0, 0, 0, 0, 8, 1, 2, 0, 0 };

	int* easy_test2_answer = new int[81]{ 2, 8, 4, 7, 9, 5, 3, 1, 6, 
										  9, 3, 5, 8, 1, 6, 7, 4, 2,
										  6, 1, 7, 2, 3, 4, 5, 8, 9,
										  1, 7, 8, 5, 6, 9, 4, 2, 3,
										  3, 2, 9, 1, 4, 7, 6, 5, 8, 
										  4, 5, 6, 3, 2, 8, 9, 7, 1,
										  8, 4, 2, 9, 5, 3, 1, 6, 7,
										  5, 9, 1, 6, 7, 2, 8, 3, 4, 
										  7, 6, 3, 4, 8, 1, 2, 9, 5 };

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

	//// Instantiate and set game board
	//Board *easy_sudoku = new Board();
	//easy_sudoku->set_board(test_board_easy);
	//easy_sudoku->print_board();
	//int loop_count_easy = 0;

	//// Run solver on easy board
	//auto start_easy = high_resolution_clock::now();

	//while (easy_sudoku->is_complete() == false) {
	//	easy_sudoku->annotate_potential_entries();
	//	easy_sudoku->remove_doubles_and_triples_by_sub_grid();
	//	//easy_sudoku->find_unique_potentials();
	//	std::cout << "Loops: " << ++loop_count_easy << " | Empty Cells: ";
	//	std::cout << easy_sudoku->empty_cells << std::endl;
	//	if (loop_count_easy > 15) {
	//		break;
	//	}
	//}

	//auto stop_easy = high_resolution_clock::now();
	//auto duration_easy = duration_cast<milliseconds>(stop_easy - start_easy);
	//std::cout << duration_easy.count() << "ms" << std::endl;
	//std::cout << "Board is correct: " << easy_sudoku->compare_boards(easy_sudoku->board_to_ints(), easy_test_answer) << std::endl;
	//easy_sudoku->print_board();

	//// Run solver on second easy board
	//Board *easy_sudoku2 = new Board();
	//easy_sudoku2->set_board(test_board_easy2);
	//easy_sudoku2->print_board();
	//int loop_count_easy2 = 0;

	//auto start_easy2 = high_resolution_clock::now();

	//while (easy_sudoku2->is_complete() == false) {
	//	easy_sudoku2->annotate_potential_entries();
	//	easy_sudoku2->remove_doubles_and_triples_by_sub_grid();
	//	//easy_sudoku2->find_unique_potentials();
	//	std::cout << "Loops: " << ++loop_count_easy2 << " | Empty Cells: ";
	//	std::cout << easy_sudoku2->empty_cells << std::endl;
	//	if (loop_count_easy2 > 15) {
	//		break;
	//	}
	//}

	//auto stop_easy2 = high_resolution_clock::now();
	//auto duration_easy2 = duration_cast<milliseconds>(stop_easy2 - start_easy2);
	//std::cout << duration_easy2.count() << "ms" << std::endl;
	//std::cout << "Board is correct: " << easy_sudoku2->compare_boards(easy_sudoku2->board_to_ints(), easy_test2_answer) << std::endl;
	//easy_sudoku2->print_board();

	// Run solver on medium board
	Board *med_sudoku = new Board();
	med_sudoku->set_board(test_board_medium);
	med_sudoku->print_board();
	int loop_count_med = 0;

	// run solver on mediam board
	auto start_med = high_resolution_clock::now();

	while (med_sudoku->is_complete() == false) {
		med_sudoku->annotate_potential_entries();
		med_sudoku->remove_doubles_and_triples_by_sub_grid();
		std::cout << "Loops: " << ++loop_count_med << " | Empty Cells: ";
		std::cout << med_sudoku->empty_cells << std::endl;
		if (loop_count_med > 10) {
			break;
		}
	}

	med_sudoku->find_unique_potentials();
	std::cout << med_sudoku->empty_cells << std::endl;
	med_sudoku->annotate_potential_entries();
	std::cout << med_sudoku->empty_cells << std::endl;
	med_sudoku->remove_doubles_and_triples_by_sub_grid();
	std::cout << med_sudoku->empty_cells << std::endl;
	med_sudoku->find_unique_potentials();
	std::cout << med_sudoku->empty_cells << std::endl;
	med_sudoku->annotate_potential_entries();
	std::cout << med_sudoku->empty_cells << std::endl;
	med_sudoku->remove_doubles_and_triples_by_sub_grid();
	std::cout << med_sudoku->empty_cells << std::endl;
	med_sudoku->find_unique_potentials();
	std::cout << med_sudoku->empty_cells << std::endl;
	med_sudoku->annotate_potential_entries();
	std::cout << med_sudoku->empty_cells << std::endl;
	med_sudoku->remove_doubles_and_triples_by_sub_grid();
	std::cout << med_sudoku->empty_cells << std::endl;
	med_sudoku->find_unique_potentials();
	std::cout << med_sudoku->empty_cells << std::endl;
	med_sudoku->annotate_potential_entries();
	std::cout << med_sudoku->empty_cells << std::endl;
	med_sudoku->find_unique_potentials();
	std::cout << med_sudoku->empty_cells << std::endl;
	med_sudoku->remove_doubles_and_triples_by_sub_grid();
	std::cout << med_sudoku->empty_cells << std::endl;
	med_sudoku->find_unique_potentials();
	std::cout << med_sudoku->empty_cells << std::endl;
	med_sudoku->annotate_potential_entries();
	std::cout << med_sudoku->empty_cells << std::endl;
	med_sudoku->find_unique_potentials();
	std::cout << med_sudoku->empty_cells << std::endl;

	med_sudoku->print_board();

	auto stop_med = high_resolution_clock::now();
	auto duration_med = duration_cast<milliseconds>(stop_med - start_med);
	std::cout << duration_med.count() << "ms" << std::endl;
	std::cout << "Board is correct: " << med_sudoku->compare_boards(test_board_medium, medium_test_answer) << std::endl;

	//delete easy_sudoku;
	//delete easy_sudoku2;
	delete med_sudoku;
	delete test_board_easy2;
	delete easy_test2_answer;
	delete test_board_medium;
	delete medium_test_answer;
	delete test_board_easy;
	delete easy_test_answer;

	return 0;
}