#include <iostream>
#include<stdlib.h>
using namespace std;
#include "sudoku.h"
#include "knightpath.h"
#include "ratmaze.h"

int main()
{
    system("color E4");
    sudoku s;
    knight k;
    ratmaze r;
    mainmenu:
    system("CLS");
    cout <<"\nWelcome to Game hub!\n" << endl;
    cout<<"\n1.Sudoku\n";
    cout<<"\n2.Knights tour\n";
    cout<<"\n3.Rat's Maze\n";
    cout<<"\n4.exit\n";
    cout<<"\nEnter your choice:";
    int choice;
    cin>>choice;
    system("pause");
    system("CLS");
    switch(choice)
    {
    case 1:
        s.play_sudoku();
        system("pause");
        goto mainmenu;
        break;
    case 2:
        k.play_knight();
        system("pause");
        goto mainmenu;
        break;
    case 3:
        r.play_ratmaze();
        system("pause");
        goto mainmenu;
        break;

    case 4:
        exit(0);
        break;

    default:
        cout<<"\nInvalid Input.Please enter a valid choice\n";
        system("pause");
        goto mainmenu;

    }
    return 0;
}
