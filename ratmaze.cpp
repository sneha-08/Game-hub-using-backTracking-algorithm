#include <graphics.h>
#include<stdio.h>
#include<dos.h>
#include<windows.h>
#include<iostream>
#include<stdlib.h>
using namespace std;
#include "ratmaze.h"

void ratmaze::printSolution(int sol[L][L])
{
	floodfill(75,75,2);
				floodfill(75+(50*(7)),75+(50*(7)),2);
				setfillstyle(1,RED);
	for (int i = 0; i < L; i++) {
		for (int j = 0; j < L; j++)
		{
		    if(sol[j][i]==1)
		{
		    floodfill(75+(50*(i)),75+(50*(j)),2);
            delay(1000);
            continue;

		}
		}

	}

}


bool ratmaze::isSafe(int maze[L][L], int x, int y)//keeps x,y inside maze
{

	if (
		x >= 0 && x < L && y >= 0
		&& y < L && maze[x][y] == 1)
		return true;

	return false;
}



bool ratmaze::solveMaze(int maze[L][L])//checks if path is available or not
{
	int sol[L][L] = { { 0, 0, 0, 0, 0, 0, 0, 0 },
					{ 0, 0, 0, 0,0, 0, 0, 0 },
					{ 0, 0, 0, 0,0, 0, 0, 0 },
					{ 0, 0, 0, 0, 0, 0, 0, 0 },
					{ 0, 0, 0, 0, 0, 0, 0, 0 },
					{ 0, 0, 0, 0, 0, 0, 0, 0 },
					{ 0, 0, 0, 0, 0, 0, 0, 0 },
					{ 0, 0, 0, 0,0, 0, 0, 0 } };

	if (solveMazeUtil(
			maze, 0, 0, sol)
		== false) {
		printf("Solution doesn't exist");
		return false;
	}

	printSolution(sol);
	return true;
}


bool ratmaze::solveMazeUtil(
	int maze[L][L], int x,
	int y, int sol[L][L])
{
	//denotes goal
	if (
		x == L - 1 && y == L - 1
		&& maze[x][y] == 1) {
		sol[x][y] = 1;
		return true;
	}


	if (isSafe(maze, x, y) == true) {

		sol[x][y] = 1;//marking for backtracking


		if (solveMazeUtil(
				maze, x + 1, y, sol)//going in the same row
			== true)
			return true;


		if (solveMazeUtil(
				maze, x, y + 1, sol)//going to the next row to find path
			== true)
			return true;


		sol[x][y] = 0;//if soln fails backtrack and unmark
		return false;
	}

	return false;
}


void ratmaze::play_ratmaze()
{
	int maze[L][L] = { { 1, 1, 1, 0, 0, 0, 0, 0 },
				{ 1, 0, 1, 1, 1, 0, 1, 1 },
				{ 1, 1, 0, 1, 1, 1, 0, 1 },
				{ 1, 1, 1, 1, 1, 0, 1, 1 },
				{ 0, 1, 1, 0, 1, 1, 1, 1 },
				{ 1, 1, 1, 1, 0, 1, 0, 0 },
				{ 1, 0, 1, 0, 1, 1, 1, 1 },
                { 0, 1, 1, 0, 1, 1, 1, 0 } };

					int gd=DETECT,gm;
                    initgraph(&gd,&gm," ");
                    settextstyle(10,4,4);
				outtextxy(600,50,"rat maze");
				settextstyle(8,4,1);
				outtextxy(650,80,"blue: obstacles");
				outtextxy(640,110,"yellow: source");
				outtextxy(640,140,"& destination");
				outtextxy(580,170,"red: path");
				setcolor(2);
//border*/
				setcolor(2);
				line(50,50,450,50);
				line(450,50,450,450);
				line(450,450,50,450);
				line(50,450,50,50);

				//horizontal
				line(50,100,450,100);
				line(50,150,450,150);
				line(50,200,450,200);
				line(50,250,450,250);
				line(50,300,450,300);
				line(50,350,450,350);
				line(50,400,450,400);


				//vertical
				line(100,50,100,450);
				line(150,50,150,450);
				line(200,50,200,450);
				line(250,50,250,450);
				line(300,50,300,450);
				line(350,50,350,450);
				line(400,50,400,450);
				setfillstyle(1,BLUE);
				for(int i=0;i<8;i++)
				{
                    for(int j=0;j<8;j++)
                    {
                       // if(i!=7 && j!=7)
                        //{

                        if(maze[j][i]==0)
                        {
                            floodfill(75+((50*i)),75+((50*j)),2);

                        }
                  //  }
                    }
                }
                setfillstyle(1,YELLOW);
				floodfill(75,75,2);
				floodfill(75+(50*(7)),75+(50*(7)),2);

	solveMaze(maze);
	setfillstyle(1,YELLOW);
				floodfill(75,75,2);
				floodfill(75+(50*(7)),75+(50*(7)),2);
	getch();
	closegraph();

	//return 0;
	/*int choice;
	cout<<"\n Hello player!! you are gonna set up the maze now!!\n";
	cout<<"\n The rat enters the maze at left top corner and exits at right bottom corner\n";
	cout<<"\n Press 1 to setup the maze yourself else the maze is set by us\n";
	cin>>choice;
	if(choice!=1)
    {
        int maze[N][N] = { { 1, 0, 0, 0 },
					{ 1, 1, 1, 1 },
					{ 0, 1, 1, 1 },
					{ 1, 0, 0, 1 } };
        cout<<"\n Here's our maze:\n";
        printSolution(maze);
        cout<<"\n Here's the path that the rat takes:\n";
        solveMaze(maze);
        return;

    }
	cout<<"\n Please enter 1 for the place you wanna set the maze in and we will specify each coordinate at a time\n";
	int maze[N][N]={0};

    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            cout<<"\n Do you want to set maze at ("<<i<<" ,"<<j<<") coordinate [please enter 1 if yes and 0 for no]: ";
            cin>>maze[i][j];
        }
    }
    maze[0][0]=1;
    maze[N-1][N-1]=1;
    system("pause");
    system("CLS");
    cout<<"\n Here's the maze you entered\n";
    printSolution(maze);

    cout<<"\n Here's the path that the rat takes:\n";
	solveMaze(maze);
*/
}
