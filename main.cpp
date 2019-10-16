#include <iostream>
#include <ncurses.h>
#include "objects.h"

const int ENEMIESNUMBER = 40;
const int WIDTH = 60;
const int HEIGHT = 40;

using namespace std;

int main()
{

    Gorol gorole[ENEMIESNUMBER];

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
    for(int i; i < ENEMIESNUMBER; i++){
        mvaddch(gorole[i].get_pos()[0], gorole[i].get_pos()[1], gorole[i].get_face());
    }
    refresh();
    getch();
    endwin();

	return 0;
}
