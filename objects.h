
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
    void lose_live() { lives--; }
    int get_pos(){ return x; }
    char get_face(){ return face; }
};

class Gorol {

    int pos[2];
    bool isAlive;
    char face;

  public:
    Gorol(int iy = 0, int ix = 0, char iface = 'G', bool iisAlive = true){
        pos[0] = iy;
        pos[1] = ix;
        face = iface;
        isAlive = iisAlive;
    }

    void move_right(){ pos[1]++; }
    void move_left(){ pos[1]--; }
    void move_down(){ pos[0]++; }
    void die(){ isAlive = false; }
    int* get_pos(){ return pos; }
    char get_face(){ return face; }
    bool get_status(){ return isAlive; }
    void revive(){ isAlive = true; }


};
