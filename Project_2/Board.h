#ifndef BOARD_H
#define BOARD_H

#include "Events.h"
#include "Player.h"
#include "Riddles.h"
#include "Tile.h"
#include "utils.h"
#include <iostream>

using namespace std;

class Board
{
    private:
        static const int _BOARD_SIZE = 52;
        Tile _tiles[2][_BOARD_SIZE];
        static const int _MAX_PLAYERS = 2;
        int _player_count;

        vector <Player> _Players;
        Player _players[_MAX_PLAYERS];

        // Display Function
        void displayTile(int path_index, int pos);
        bool isPlayerOnTile(int player_index, int path_index, int pos);
        int _role_dice();

        // Tile Color Function
        char getTileColor(int player_index);

        // Initialize and Load Events and Riddles
        Events _event;
        Riddles _riddle;


    public:
        // Constructors
        Board();
        Board(int player_count);


        // Getter
        Player getPlayer(int player_index);
        
        int getPlayerPosition(int player_index);

        // Setter
        void setPlayer(int player_index, Player player);
        void setPlayerPath(int player_index, int path);
        void setPlayerPosition(int player_index, int pos);


        // Paths
        void cubTraining(int player_index);
        void prideLands(int player_index);


        // Initialize
        void iniitializePlayer(int player_index, Player character);
        void initializePlayerPath(int p1_path, int p2_path);
        void initializeBoard();

        // Display
        void displayTrack(int path_index);
        void displayBoard();
        
        
        // Move
        bool movePlayer(int player_index);
        bool processMove(int player_index, int prevPos);
        void movePlayerPosition(int player_index, int pos);
        
        void samePosition(int p1, int p2);

        
        // Tiles
        void regularTiles(int player_index);
        bool blueTile(int player_index);
        void pinkTile(int player_index);
        void redTile(int player_index);
        void brownTile(int player_index, int prevPos);
        void purpleTile(int player_index);
};

#endif
