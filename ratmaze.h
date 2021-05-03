#ifndef RATMAZE_H_INCLUDED
#define RATMAZE_H_INCLUDED
class ratmaze
{
public:
    static const int L=8;
    bool solveMazeUtil(	int maze[L][L], int x,int y, int sol[L][L]);//finds the path using backtracking
    void printSolution(int sol[L][L]);//prints the mazes
    bool isSafe(int maze[L][L], int x, int y);//makes sure all points are checked
    bool solveMaze(int maze[L][L]);//checks whether path exists or not
    void play_ratmaze();
};


#endif // RATMAZE_H_INCLUDED
