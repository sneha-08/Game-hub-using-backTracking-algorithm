#include<iostream>
using namespace std;
#include "sudoku.h"
#include<stdlib.h>


int sudoku::is_exist_row(int grid[N][N], int row, int num)
{
	for (int col = 0; col < 9; col++)
        {
		if (grid[row][col] == num)
		{
			return 1;
		}
        }
	return 0;
}

int sudoku::is_exist_col(int grid[N][N], int col, int num)
 {
	for (int row = 0; row < 9; row++)
    {
		if (grid[row][col] == num)
		{
			return 1;
		}
    }
	return 0;
}

int sudoku::is_exist_box(int grid[N][N], int startRow, int startCol, int num)
{
	for (int row = 0; row < 3; row++)
    {
		for (int col = 0; col < 3; col++)
		 {
			if (grid[row + startRow][col + startCol] == num)
			{
				return 1;
			}
		}
	}
	return 0;
}

int sudoku::is_safe_num(int grid[N][N], int row, int col, int num)
{
	return !is_exist_row(grid, row, num)
			&& !is_exist_col(grid, col, num)
			&& !is_exist_box(grid, row - (row % 3), col - (col %3), num);
}

int sudoku::find_unassigned(int grid[N][N], int *row, int *col)
{
	for (*row = 0; *row < N; (*row)++)
    {
		for (*col = 0; *col < N; (*col)++)
		{
			if (grid[*row][*col] == 0)
			{
				return 1;
			}
		}
	}
	return 0;
}

int sudoku::solve(int grid[N][N])
{

	int row = 0;
	int col = 0;

	if (!find_unassigned(grid, &row, &col))
    {
		return 1;
	}

	for (int num = 1; num <= N; num++ )
    {

		if (is_safe_num(grid, row, col, num))
        {
			grid[row][col] = num;

			if (solve(grid))
            {
				return 1;
			}

			grid[row][col] = UNASSIGNED;
		}
	}

	return 0;
}

void sudoku::print_grid(int grid[N][N])
{

    int i,j;
    cout<<"\n\t"<<"     1 2 3   4 5 6   7 8 9\n";
    cout<<"\t   -------------------------\n";
    for(i=0;i<9;i++)
    {
        cout<<"\t";

        for(j=0;j<9;j++)
        {
            if(j==0)
            {
                cout<<i+1;
                cout<<"  | ";
            }
            if(grid[i][j]==0)
                cout<<". ";

            else
                cout<<grid[i][j]<<" ";

            if((j+1)%3==0 )
                cout<<"| ";

        }

    if((i+1)%3==0 )
        cout<<"\n\t   -------------------------";

    cout<<"\n";
    }
    cout<<"\n***************************************************************\n";
}
void sudoku::play_sudoku()
{
    //int choice=-1;
    cout<<"\nWELCOME TO SUDOKU NINJA\n";
    cout<<"Are you ready for a fun game of sudoku?\n";
    system("pause");

    system("CLS");
    cout<<"\n Here is the puzzle for you (^.^)\n";
    cout<<"\n Don't forget to have fun!!!!!!!!\n";
    int grid[N][N] = {{4,0,9, 0,0,8, 0,3,0},
			 {7,5,0, 0,3,2, 0,1,8},
			 {0,0,0, 5,0,0, 2,0,6},
			 {8,0,0, 0,0,3, 9,0,0},
			 {0,3,0, 0,4,0, 0,7,5},
			 {0,0,1, 2,0,7, 0,0,0},
			 {0,0,8, 4,0,0, 0,0,9},
			 {0,1,0, 0,0,9, 0,4,0},
			 {2,0,0, 7,1,0, 8,5,0}
			 };

        int r,c;
        int sol;
        int f=0;

        int ans[N][N]={{4,0,9, 0,0,8, 0,3,0},
			 {7,5,0, 0,3,2, 0,1,8},
			 {0,0,0, 5,0,0, 2,0,6},
			 {8,0,0, 0,0,3, 9,0,0},
			 {0,3,0, 0,4,0, 0,7,5},
			 {0,0,1, 2,0,7, 0,0,0},
			 {0,0,8, 4,0,0, 0,0,9},
			 {0,1,0, 0,0,9, 0,4,0},
			 {2,0,0, 7,1,0, 8,5,0}
			 };

        print_grid(grid);
        int choice;
        cout<<"\n Do you want to play the game(1) or jump to the solution(2)?\n";
        cin>>choice;
        system("pause");
        if(choice==2)
        {
            system("CLS");
            cout<<"\n Here's the grid:\n";
            print_grid(grid);
            solve(grid);
            cout<<"\n Solution Grid:\n";
            print_grid(grid);
            return;
        }
        cout<<"\n Let's get started...\n";
        system("pause");
        solve(grid);

        do
        {
            system("cls");
            print_grid(ans);
            cout<<"\n Enter the row no. :\n";
            cin>>r;

            r-=1;

            cout<<"\n Enter the column no.:\n";
                cin>>c;

            c-=1;

            cout<<"\n Enter the element:\n";
            cin>>sol;

            if(grid[r][c]==sol)
            {

            ans[r][c]=sol;
            cout<<"\n Correct\n";
            cout<<"\n Play on !!!\n";
            cout<<endl;
            print_grid(ans);

                for(int i=0;i<9;i++)
                    {
                        for(int j=0;j<9;j++)

                            if(ans[i][j]==0)
                                f=0;
                            else
                                f+=1;
                    }
                system("pause");
            }

            else
            {
                cout<<"\n Wrong answer\n";
                    cout<<"\n Don't give up !!\n";
                cout<<"\n Continue Playing...\n";
                system("pause");




            }

        }while(f!=81);

        print_grid(ans);
    cout<<"\n WINNER!!WINNER!!CHICKEN DINNER!!\n";
    cout<<"\n Good play today! See you next time!!\n";
}
