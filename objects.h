
class Player {

    int x, score, lives;
    char face;

  public:

    Player(int ix = 0, int iscore = 0, int ilives = 3, char iface = 'A'){
        x = ix;
        score = iscore;
        lives = ilives;
        face = iface;
    }

    void move_right(){ x++; }
    void move_left(){ x--; }
    int get_lives(){ return lives; }
    void lose_live() { lives--;}
    int get_pos(){ return x; }
};

class Gorol {

    int pos[2];
    bool isAlive;
    char face;

  public:
    Gorol(int ix = 0, int iy = 0, char iface = 'G', bool iisAlive = true){
        pos[1] = ix;
        pos[0] = iy;
        face = iface;
        isAlive = iisAlive;
    }

    void move_right(){ pos[1]++; }
    void move_left(){ pos[1]--; }
    void move_down(){ pos[0]--; }
    void die(){ isAlive = false; }
    int get_pos(){ return pos; }


};
