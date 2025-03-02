#ifndef GAME_H
#define GAME_H

#include "Board.h"
#include "Player.h"
#include "utils.h"

#include <fstream>

class Game
{
    private:
        // Players
        int _num_players;

        // Board
        Board _game_board;

        // Flags
        bool _game_ended;
        vector <bool> _players_finished;

        // Characters
        vector <Player> _Characters;
        void printCharacters();
        int matchCharacter(string name);

        // Advisors
        vector <int> _advisors;


    public:
        // Constructors
        Game();
        Game(int num_players);
        
        // Getters
        Player getPlayer(int player_index);

        // Loaders
        void loadCharacters();

        // Selecters
        void selectCharacter();

        // Main Menu
        bool mainMenu(int playerIndex);

        // Game Functions
        void setupGame(); // Initialize board and players
        void runGame();


        // End Game
        void resolveGame();
};

#endif