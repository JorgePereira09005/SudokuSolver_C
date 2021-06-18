#include "sudoku.h"

int UNSOLVED = 81;
int SIZE_ROWS = 9;
int SIZE_COLUMNS = 9;

int main()
{
	int** puzzle;

	//array of an array of pointers
	Sudoku* sudoku;

	puzzle = createPuzzle();
	
	sudoku = setUpPuzzle(puzzle);

	printPuzzle(sudoku->squares);

	printf("\nbefore checkPuzzle()");

	checkPuzzle(sudoku->squares, sudoku->boxes);
	checkPuzzle(sudoku->squares, sudoku->boxes);
	checkPuzzle(sudoku->squares, sudoku->boxes);
	checkPuzzle(sudoku->squares, sudoku->boxes);

	printf("\nafter checkPuzzle()");

	printf("\n\n");

	printPuzzle(sudoku->squares);

	return 0;
}
