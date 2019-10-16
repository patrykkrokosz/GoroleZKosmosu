#include <iostream>
#include <ncurses.h>
#include "objects.h"

using namespace std;

int main()
{

    Gorol gorol;

    cout<< *gorol.get_pos();

	return 0;
}
