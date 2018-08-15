#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
// true if there are spots with row and column as location and false if grid is completely full
int FindUnassignedLocation(int grid[9][9], int *row, int *col){
for(*row = 0; *row<9; (*row)++){
	for(*col = 0; *col<9; (*col)++){
		if(grid[*row][*col] == 0) return 1;
	}
}
return 0;
}

int inRow(int grid[9][9], int row, int num){
	for(int col = 0; col<9; col++){
		if(grid[row][col] == num) return 0;
	}
	return 1;
}

int inCol(int grid[9][9], int col, int num)
{
for(int row = 0; row<9; row++)
	{
		if(grid[row][col] == num) return 0;
	}
return 1;
}

int inMat(int grid[9][9], int rstart, int cstart, int num)
{
for(int row = 0; row<3; row++)
	{
		for(int col = 0; col<3; col++)
		{
			if(grid[row+rstart][col+cstart] == num) return 0;
		}
	}
return 1;
}

int isSafe(int grid[9][9], int row, int col, int num){
	int mat[] = {0,0,0,3,3,3,6,6,6};
	return inRow(grid, row, num)&&inCol(grid, col, num)&& inMat(grid, mat[row], mat[col], num);
}



int SudokuSolver(int grid[9][9]) // returns true if everything is in place and false otherwise
{
int row = 0, col = 0;
if(!FindUnassignedLocation(grid, &row, &col)) return 1;

for(int n = 1; n<=9; n++)
{
	if(isSafe(grid,row, col, n)) 
	{
	grid[row][col] = n;
	
	if(SudokuSolver(grid)) return 1;
	
	grid[row][col] = 0;
	}
}
return 0;
}
	
void printGrid(int grid[9][9])
{
    for (int row = 0; row < 9; row++)
    {
       for (int col = 0; col < 9; col++)
             printf("%2d", grid[row][col]);
        printf("\n");
    }
}

void main()
{
    int grid[9][9];
	printf("Enter the sudoku puzzle left to right, top to bottom: \n");
	for(int i=0; i<9; i++)
	{
	for(int j=0; j<9; j++)
	{
	scanf("%d",&grid[i][j]);
	}
	}
    if (SudokuSolver(grid) == true)
          printGrid(grid);
    else
         printf("No solution exists");

} 