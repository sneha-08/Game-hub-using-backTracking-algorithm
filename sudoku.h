#ifndef SUDOKU_H_INCLUDED
#define SUDOKU_H_INCLUDED
class sudoku
{
public:
    static const int N=9;
    static const int UNASSIGNED=9;
    int is_exist_row(int grid[N][N], int row, int num);//checks for row
    int is_exist_col(int grid[N][N], int col, int num);//checks for column
    int is_exist_box(int grid[N][N], int startRow, int startCol, int num);//checks for box
    int is_safe_num(int grid[N][N], int row, int col, int num);//calls row,column and box checks for num
    int find_unassigned(int grid[N][N], int *row, int *col);//checks if the box is empty
    int solve(int grid[N][N]);//solving the puzzle
    void print_grid(int grid[N][N]);//prints grid
    void play_sudoku();
};


#endif // SUDOKU_H_INCLUDED
