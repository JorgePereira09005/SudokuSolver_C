//#pragma once

#ifndef SUDOKU_H
#define SUDOKU_H

#include <stdio.h>
#include <stdlib.h>

extern int UNSOLVED;
extern int SIZE_ROWS;
extern int SIZE_COLUMNS;

typedef struct Sudoku {
	struct Square*** squares;
	struct Box** boxes;
} Sudoku;

typedef struct Box {
	struct Square** squares;
	int numbers;
	int possible[9];
	int solvable;
	struct Box* next;
} Box;

typedef struct Square {
	int number;

	/* 
	000000000
	987654321
	first zero means square can be a 9
	*/
	int possible[9];
	int solvable;

	//box the square is in
	Box* box;

	int row;
	int column;

} Square;

//returns a pointer to an array of ints
int** createPuzzle();

//prints the int** puzzle passed as argument
void printPuzzle(Square*** puzzle);

Sudoku* setUpPuzzle(int** puzzle);

Sudoku* createSudoku(Square*** squares, Box** boxes);

int updateSudoku(Square*** sudoku, int row, int column);

int checkPuzzle(Square*** sudoku, Box** boxes);

int solveSquare(Square* square);

/*Box functions*/
Box** createBoxes();
int updateBoxes(Square*** sudoku, int row, int column);
int boxSingles(Square*** sudoku, Box** boxes);

#endif