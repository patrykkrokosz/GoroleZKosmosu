#include <iostream>
#include <ncurses.h>
#include <time.h>
#include "objects.h"

const int ENEMIESNUMBER = 40;
const int WIDTH = 60;
const int HEIGHT = 20;

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
        if (gorole[nearest].get_pos()[1] <= gorole[i].get_pos()[1] && toRight && gorole[i].get_status()){
            nearest = i;
        }
        else if (gorole[nearest].get_pos()[1] >= gorole[i].get_pos()[1] && !toRight && gorole[i].get_status()){
            nearest = i;
        }
    }
    return nearest;
}

int find_lowest(Gorol *gorole){
    int lowest;
    for (int i = 0; i < ENEMIESNUMBER; i++){
        if (gorole[i].get_status()){
        lowest = i;
        break;
        }
    }
    for (int i = 0; i < ENEMIESNUMBER; i++){
        if (gorole[lowest].get_pos()[0] <= gorole[i].get_pos()[0] && gorole[i].get_status()){
            lowest = i;
        }
    }
    return lowest;
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
    Boolet playerBullet;

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
    keypad(stdscr, true);
    timeout(100);
    curs_set(0);
    bool game = true;
    bool enemiesgotoright = true;
    int nearest, lowest, pressedkey;
    int aliveEnemies;

    //************************
    //*****GAME LOOP HERE*****
    //************************

    while(game){

        mvprintw(0, 0,"Lives: %d", player.get_lives());
        mvprintw(1, 0,"Score: %d", player.get_score());

        aliveEnemies = 0;

        if (playerBullet.is_active()){
            playerBullet.go();
            for(int i = 0; i < ENEMIESNUMBER; i++){
                if (gorole[i].get_pos()[0] == playerBullet.get_pos()[0] && gorole[i].get_pos()[1] == playerBullet.get_pos()[1] && gorole[i].get_status()){
                    playerBullet.deactivate();
                    mvaddch(gorole[i].get_pos()[0], gorole[i].get_pos()[1], 'x');
                    gorole[i].die();
                    player.add_score(100);
                    break;
                }
            }
            if (playerBullet.get_pos()[0] <= 3 ){
                playerBullet.deactivate();
            }
            if (playerBullet.is_active()){
                mvaddch(playerBullet.get_pos()[0], playerBullet.get_pos()[1], playerBullet.get_face());
            }
        }

        for(int i = 0; i < ENEMIESNUMBER; i++){
            if (gorole[i].get_status()){
                aliveEnemies++;
                mvaddch(gorole[i].get_pos()[0], gorole[i].get_pos()[1], gorole[i].get_face());
            }
        }


        mvaddch(HEIGHT-1, player.get_pos(), player.get_face());
        refresh();

        pressedkey = getch();
        sleep(100000);

        switch (pressedkey){
            case KEY_LEFT:
                player.move_left();
                break;
            case KEY_RIGHT:
                player.move_right();
                break;
            case ' ':
                if (!playerBullet.is_active()){
                    playerBullet.shoot(HEIGHT-2, player.get_pos(), true);
                }
            default:
                break;
            pressedkey = 0;
        }

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

        lowest = find_lowest(gorole);
        if (gorole[lowest].get_pos()[0] >= HEIGHT-1 || aliveEnemies == 0){
            game = false;
        }
        clear();
        pressedkey = 0;
        refresh();
    }

    printw("Game ended, lol.");
    refresh();
    sleep(100000);
    getch();
    getch();
    endwin();

	return 0;
}
