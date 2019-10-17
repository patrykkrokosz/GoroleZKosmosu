#include <iostream>
#include <ncurses.h>
#include <time.h>
#include "objects.h"

const int ENEMIESNUMBER = 40;
const int WIDTH = 60;
const int HEIGHT = 40;

enum Directions{
    LEFT,
    RIGHT,
    DOWN
};

void sleep(unsigned int mseconds)
{
    clock_t goal = mseconds + clock();
    while (goal > clock());
}

int find_nearest_to_the_edge(Gorol *gorole, bool toRight){
    int nearest = 0;
    for(int i = 1; i < ENEMIESNUMBER; i++){
        if (gorole[nearest].get_pos()[1] <= gorole[i].get_pos()[1] && toRight){
            nearest = i;
        }
        else if (gorole[nearest].get_pos()[1] >= gorole[i].get_pos()[1] && !toRight){
            nearest = i;
        }
    }
    return nearest;
}

int find_lowest(Gorol *gorole){
    int lowest = 0;
    for int i = 1; i < ENEMIESNUMBER; i++){
    if (gorole[lowest].get_pos()[0] => gorole[i].get_pos()[0]){
    }
    }
}

void move_enemies(Gorol *gorole, Directions dir){
    for (int i = 0; i < ENEMIESNUMBER; i++){
        switch( dir ){
            case LEFT:
                gorole[i].move_left();
                break;
            case RIGHT:
                gorole[i].move_right();
                break;
            case DOWN:
                gorole[i].move_down();
                break;
            default:
                break;
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
    clear();
    noecho();
    cbreak();
    bool game = true;
    bool enemiesgotoright = true;
    int nearest;

    while(game){
        for(int i = 0; i < ENEMIESNUMBER; i++){
            mvaddch(gorole[i].get_pos()[0], gorole[i].get_pos()[1], gorole[i].get_face());
        }
    refresh();

    sleep(100000);

        nearest = find_nearest_to_the_edge(gorole, enemiesgotoright);

        if ( gorole[nearest].get_pos()[1] >= WIDTH-1 || gorole[nearest].get_pos()[1] <= 0){
            move_enemies(gorole, DOWN);
            enemiesgotoright = !enemiesgotoright;
        }
        else{
            if(enemiesgotoright){
                move_enemies(gorole, RIGHT);
            }
            else{
                move_enemies(gorole, LEFT);
            }
        }
    clear();
    refresh();
    }
    endwin();

	return 0;
}
