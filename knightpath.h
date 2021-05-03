#ifndef KNIGHTPATH_H_INCLUDED
#define KNIGHTPATH_H_INCLUDED
class knight
{
public:
    static const int N=8;
    int sol[N][N];
    bool ValidPosition(int x, int y, int sol[N][N]); //check place is in range and not assigned yet
    void displaySolution();
    int knightTour(int x, int y, int move, int sol[N][N], int xMove[N], int yMove[N]);
    bool KnightMovement();
    void play_knight();
};


#endif // KNIGHTPATH_H_INCLUDED
