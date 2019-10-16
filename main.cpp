#include <iostream>
#include <ncurses.h>
#include "objects.h"

const int ENEMIESNUMBER = 40;
const int WIDTH = 60;
const int HEIGHT = 40;

using namespace std;

enum Directions{
    LEFT,
    RIGHT,
    DOWN
}

int find_nearest_to_the_edge(Gorol gorole*, bool toRight){
    nearest = 0;
    for(int i = 1; i < ENEMIESNUMBER; i++){
        if (gorole[nearest].get_pos()[1] <= gorole[nearest].get_pos()[1] && toRight){
            nearest = i;
        }
        else if (gorole[nearest].get_pos()[1] >= gorole[nearest].get_pos()[1] && !toRight){
            nearest = i;
        }
    }
}

int main()
{

    Gorol gorole[ENEMIESNUMBER];
    Player player;

    int gy = 4;
    int gx = 4;

    for (int i; i < ENEMIESNUMBER; i++){
        gorole[i] = Gorol(gy, gx);
        if (gx > WIDTH-20){
            gx = 3;
            gy++;
        }
        gx++;
    }

    initscr();
    noecho();
    bool game = true;

    while(game){
    for(int i; i < ENEMIESNUMBER; i++){
        mvaddch(gorole[i].get_pos()[0], gorole[i].get_pos()[1], gorole[i].get_face());
    }



    refresh();
    }
    endwin();

	return 0;
}
