#include <iostream>
#include "Board.h"

using namespace std;

int main()
{
    Board b(2);
    b.initializePlayerPath(1, 0);
    b.displayBoard();
    return 0;
}