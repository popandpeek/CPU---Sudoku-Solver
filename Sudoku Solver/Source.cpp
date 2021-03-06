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

	int* test_board_easy2 = new int[81] { 0, 0, 0, 0, 9, 0, 0, 0, 0, 
										  0, 3, 0, 0, 0, 0, 7, 4, 2, 
										  6, 1, 0, 0, 3, 0, 0, 0, 0,
									  	  0, 0, 8, 0, 0, 0, 0, 0, 0, 
									 	  0, 2, 9, 1, 4, 7, 0, 0, 8,
										  4, 5, 0, 0, 0, 0, 0, 7, 0,
										  0, 4, 0, 0, 0, 0, 0, 6, 0,
										  5, 0, 0, 6, 0, 0, 0, 3, 0,
										  0, 0, 0, 0, 8, 1, 2, 0, 0 };

	int* easy_test2_answer = new int[81] { 2, 8, 4, 7, 9, 5, 3, 1, 6, 
										   9, 3, 5, 8, 1, 6, 7, 4, 2,
										   6, 1, 7, 2, 3, 4, 5, 8, 9,
										   1, 7, 8, 5, 6, 9, 4, 2, 3,
										   3, 2, 9, 1, 4, 7, 6, 5, 8, 
										   4, 5, 6, 3, 2, 8, 9, 7, 1,
										   8, 4, 2, 9, 5, 3, 1, 6, 7,
										   5, 9, 1, 6, 7, 2, 8, 3, 4, 
										   7, 6, 3, 4, 8, 1, 2, 9, 5 };

	// https://www.puzzles.ca/sudoku_puzzles/sudoku_medium_487.html
	int* test_board_medium = new int[81] { 0, 0, 0, 0, 0, 0, 3, 0, 0,
										   8, 5, 2, 3, 0, 0, 0, 0, 1,
										   0, 9, 0, 2, 0, 0, 0, 0, 4,
										   9, 7, 4, 0, 0, 0, 0, 0, 0,
										   0, 1, 0, 0, 6, 0, 0, 0, 0, 
										   0, 0, 0, 0, 4, 0, 0, 0, 0,
										   6, 0, 9, 0, 8, 0, 0, 3, 7,
										   3, 0, 0, 0, 0, 0, 0, 6, 0,
										   0, 2, 0, 0, 0, 5, 0, 0, 0 };

	int* medium_test_answer = new int[81]{  4, 6, 7, 9, 1, 8, 3, 2, 5,
											8, 5, 2, 3, 7, 4, 6 ,9, 1, 
											1, 9, 3, 2, 5, 6, 7, 8, 4,
											9, 7, 4, 5, 2, 3, 8, 1, 6,
											2, 1, 8, 7, 6, 9, 4, 5, 3, 
											5, 3, 6, 8, 4, 1, 2, 7, 9, 
											6, 4, 9, 1, 8, 2, 5, 3, 7, 
											3, 8, 5, 4, 9, 7, 1, 6, 2, 
											7, 2, 1, 6, 3, 5, 9, 4, 8 };


	// https://www.puzzles.ca/sudoku_puzzles/sudoku_medium_487.html
	int* test_board_hard = new int[81]{  0, 7, 0, 5, 0, 6, 0, 0, 0,
										 4, 0, 3, 0, 0, 0, 0, 0, 1,
										 0, 6, 0, 0, 0, 0, 9, 0, 7,
										 0, 0, 0, 7, 3, 0, 8, 2, 0,
										 8, 0, 4, 0, 5, 0, 0, 7, 3,
										 0, 9, 0, 0, 2, 0, 0, 0, 5,
										 0, 0, 1, 0, 0, 0, 0, 0, 0,
										 0, 0, 0, 1, 0, 0, 2, 0, 6,
										 0, 0, 0, 3, 8, 2, 0, 0, 0 };

	// http://www.ams.org/notices/200904/rtx090400460p.pdf
	int* test_board_diabolical = new int[81]{ 0, 9, 0, 7, 0, 0, 8, 6, 0,
											  0, 3, 1, 0, 0, 5, 0, 2, 0,
											  8, 0, 6, 0, 0, 0, 0, 0, 0,
											  0, 0, 7, 0, 5, 0, 0, 0, 6,
											  0, 0, 0, 3, 0, 7, 0, 0, 0,
											  5, 0, 0, 0, 1, 0, 7, 0, 0,
											  0, 0, 0, 0, 0, 0, 1, 0, 9, 
											  0, 2, 0, 6, 0, 0, 3, 5, 0,
											  0, 5, 4, 0, 0, 8, 0, 7, 0 };

	int* diabolical_test_answer = new int[81]{ 2, 9, 5, 7, 4, 3, 8, 6, 1,
											   4, 3, 1, 8, 6, 5, 9, 2, 7,
											   8, 7, 6, 1, 9, 2, 5, 4, 3, 
											   3, 8, 7, 4, 5, 9, 2, 1, 6, 
											   6, 1, 2, 3, 8, 7, 4, 9, 5, 
											   5, 4, 9, 2, 1, 6, 7, 3, 8, 
											   7, 6, 3, 5, 2, 4, 1, 8, 9, 
											   9, 2, 8, 6, 7, 1, 3, 5, 4, 
											   1, 5, 4, 9, 3, 8, 6, 7, 2 };

	// Instantiate and set game board
	Board *easy_sudoku = new Board();
	easy_sudoku->set_board(test_board_easy);

	std::cout << std::endl << "Now testing easy board #1:" << std::endl;
	std::cout << "Board start state: " << std::endl;
	easy_sudoku->print_board();

	// Run solver on easy board
	auto start_easy = high_resolution_clock::now();

	bool solved = easy_sudoku->solve_board(); // solve board

	auto stop_easy = high_resolution_clock::now();
	auto duration_easy = duration_cast<milliseconds>(stop_easy - start_easy);
	std::cout << "Runtime: " << duration_easy.count() << "ms" << std::endl;
	std::cout << "Board end state: " << std::endl;
	easy_sudoku->print_board();
	std::cout << "Board is correct: " << solved << std::endl;

	// Run solver on second easy board
	Board *easy_sudoku2 = new Board();
	easy_sudoku2->set_board(test_board_easy2);

	std::cout << std::endl << "Now testing easy board #2:" << std::endl;
	std::cout << "Board start state: " << std::endl;
	easy_sudoku2->print_board();

	auto start_easy2 = high_resolution_clock::now();

	solved = easy_sudoku2->solve_board(); // solve board

	auto stop_easy2 = high_resolution_clock::now();
	auto duration_easy2 = duration_cast<milliseconds>(stop_easy2 - start_easy2);
	std::cout << "Runtime: " << duration_easy2.count() << "ms" << std::endl;
	std::cout << "Board end state: " << std::endl;
	easy_sudoku2->print_board();
	std::cout << "Board is correct: " << solved << std::endl;

	// Run solver on medium board
	Board *med_sudoku = new Board();
	med_sudoku->set_board(test_board_medium);

	std::cout << std::endl << "Now testing medium board:" << std::endl;
	std::cout << "Board start state: " << std::endl;
	med_sudoku->print_board();

	auto start_med = high_resolution_clock::now();

	solved = med_sudoku->solve_board(); // solve board

	auto stop_med = high_resolution_clock::now();
	auto duration_med = duration_cast<milliseconds>(stop_med - start_med);
	std::cout << "Runtime: " << duration_med.count() << "ms" << std::endl;
	std::cout << "Board end state: " << std::endl;
	med_sudoku->print_board();
	std::cout << "Board is correct: " << solved << std::endl;

	// Run solver on hard board
	Board *hard_sudoku = new Board();
	hard_sudoku->set_board(test_board_hard);

	std::cout << std::endl << "Now testing hard board:" << std::endl;
	std::cout << "Board start state: " << std::endl;
	hard_sudoku->print_board();

	auto start_hard = high_resolution_clock::now();

	solved = hard_sudoku->solve_board(); // solve board

	auto stop_hard = high_resolution_clock::now();
	auto duration_hard = duration_cast<milliseconds>(stop_hard - start_hard);
	std::cout << "Runtime: " << duration_hard.count() << "ms" << std::endl;
	std::cout << "Board end state: " << std::endl;
	hard_sudoku->print_board();
	std::cout << "Board is correct: " << solved << std::endl;

	// Run solver on diabolical board
	Board *diabolical_sudoku = new Board();
	diabolical_sudoku->set_board(test_board_diabolical);

	std::cout << std::endl << "Now testing diabolical board:" << std::endl;
	std::cout << "Board start state: " << std::endl;
	diabolical_sudoku->print_board();

	auto start_diabolical = high_resolution_clock::now();

	solved = diabolical_sudoku->solve_board(); // solve board

	auto stop_diabolical = high_resolution_clock::now();
	auto duration_diabolical = duration_cast<milliseconds>(stop_diabolical - start_diabolical);
	std::cout << "Runtime: "<< duration_diabolical.count() << " ms" << std::endl;
	std::cout << "Board end state: " << std::endl;
	diabolical_sudoku->print_board();
	std::cout << "Board is correct: " << solved << std::endl;

	//delete easy_sudoku;
	//delete easy_sudoku2;
	//delete med_sudoku;
	//delete hard_sudoku;
	//delete diabolical_sudoku;
	//delete test_board_easy2;
	//delete easy_test2_answer;
	//delete test_board_medium;
	//delete medium_test_answer;
	//delete test_board_hard;
	//delete test_board_easy;
	//delete test_board_hard;
	//delete test_board_diabolical;
	//delete diabolical_test_answer;

	return 0;
}