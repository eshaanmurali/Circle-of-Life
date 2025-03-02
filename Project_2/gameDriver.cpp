#include "Game.h"

#include <iostream>

using namespace std;



int main(){
    cout << "Welcome to The Circle of Life" << endl;
    
    int num_players;
    cout << "How many players are there?" << endl;
    cin >> num_players;

    Game g(num_players);
    g.setupGame();
    g.runGame();
    g.resolveGame();

    /*
    if (num_players == 2)
    {
        Game g;
        g.setupGame();
        g.runGame();
        g.resolveGame();
    }
    else
    {
        Game g(num_players);
        g.setupGame();
        g.runGame();
        g.resolveGame();
    }
    */

    

    return 0;
}