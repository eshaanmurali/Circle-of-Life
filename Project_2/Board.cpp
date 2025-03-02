#include "Board.h"
#include "utils.h"
#define RED "\033[48;2;230;10;10m"
#define GREEN "\033[48;2;34;139;34m" /* Grassy Green (34,139,34) */
#define BLUE "\033[48;2;10;10;230m"
#define PINK "\033[48;2;255;105;180m"
#define BROWN "\033[48;2;139;69;19m"
#define PURPLE "\033[48;2;128;0;128m"
#define ORANGE "\033[48;2;230;115;0m" /* Orange (230,115,0) */
#define GREY "\033[48;2;128;128;128m" /* Grey (128,128,128) */
#define RESET "\033[0m"

#include <cstdlib> // For rand() and srand()
#include <ctime>   // For time()

Board::Board()
{
    _player_count = 1;

    // Initialize player
    _players[0] = Player();

    // Initialize board
    initializeBoard();

    // Initialize event
    _event = Events();
}

Board::Board(int player_count)
{
    // Initialize players
    for (int i = 0; i < player_count; i++)
    {
        _Players.push_back(Player());
    }

    // Initialize player count
    _player_count = player_count;

    
    // Initialize tiles
    initializeBoard();

    // Initialize event
    _event = Events();
    _riddle = Riddles();
}


// Getters
Player Board::getPlayer(int player_index)
{
    return _Players[player_index];
}

int Board::getPlayerPosition(int player_index)
{
    return _Players[player_index].getPosition();
}

// Setter
void Board::setPlayer(int player_index, Player player)
{
    _Players[player_index] = player;   
}

void Board::setPlayerPath(int player_index, int path)
{
    _Players[player_index].setPath(path);
}

void Board::setPlayerPosition(int player_index, int pos)
{
    _Players[player_index].setPosition(pos);
}



// Paths
void Board::cubTraining(int path_index)
{
    Tile temp;
    int green_count = 0;
    int total_tiles = _BOARD_SIZE;

    // Keep track of green tile positions to ensure we place exactly 30 greens
    for (int i = 0; i < total_tiles; i++)
    {
        if (i == total_tiles - 1)
        {
            // Set the last tile as Orange for "Pride Rock"
            temp.setColor('O');
        }
        else if (i == 0)
        {
            // Set the last tile as Orange for "Pride Rock"
            temp.setColor('Y');
        }
        else if (green_count < 30 && (rand() % (total_tiles - i) < 30 - green_count))
        {
            temp.setColor('G');
            green_count++;
        }
        else
        {
            // Randomly assign one of the other colors: Blue, Pink, Brown, Red,Purple
            int color_choice = rand() % 100;
            if (color_choice < 25)
            {
                temp.setColor('B'); // Blue
            }
            else if (color_choice < 40)
            {
                temp.setColor('P'); // Pink
            }
            else if (color_choice < 65)
            {
                temp.setColor('N'); // Brown
            }
            else if (color_choice < 99)
            {
                temp.setColor('R'); // Red
            }
            else
            {
                temp.setColor('U'); // Purple
            }
        }
        // Assign the tile to the board for the specified lane
        _tiles[path_index][i] = temp;
    }
}

void Board::prideLands(int path_index)
{
    Tile temp;
    int green_count = 0;
    int total_tiles = _BOARD_SIZE;

    // Keep track of green tile positions to ensure we place exactly 30 greens
    for (int i = 0; i < total_tiles; i++)
    {
        if (i == total_tiles - 1)
        {
            // Set the last tile as Orange for "Pride Rock"
            temp.setColor('O');
        }
        else if (i == 0)
        {
            // Set the last tile as Orange for "Pride Rock"
            temp.setColor('Y');
        }
        else if (green_count < 20 && (rand() % (total_tiles - i) < 20 - green_count))
        {
            temp.setColor('G');
            green_count++;
        }
        else
        {
            // Randomly assign one of the other colors: Blue, Pink, Brown, Red,Purple
            int color_choice = rand() % 100;
            if (color_choice < 15)
            {
                temp.setColor('B'); // Blue
            }
            else if (color_choice < 35)
            {
                temp.setColor('P'); // Pink
            }
            else if (color_choice < 50)
            {
                temp.setColor('N'); // Brown
            }
            else if (color_choice < 70)
            {
                temp.setColor('R'); // Red
            }
            else
            {
                temp.setColor('U'); // Purple
            }
        }
        // Assign the tile to the board for the specified lane
        _tiles[path_index][i] = temp;
    }
}


// Initialize
void Board::iniitializePlayer(int player_index, Player character)
{
    _Players[player_index] = character;
}

void Board::initializePlayerPath(int p1_path, int p2_path)
{
    _Players[0].setPath(p1_path);
    _Players[1].setPath(p2_path);
}

void Board::initializeBoard()
{
    // Seed random number generator in your main function once
    srand(time(0));

    cubTraining(0);
    prideLands(1);
}


// Display
bool Board::isPlayerOnTile(int player_index, int path_index, int pos)
{
    if (_Players[player_index].getPath() == path_index)
    {
        if (_Players[player_index].getPosition() == pos)
        {
            return true;
        }
    }
    return false;
}

void Board::displayTile(int path_index, int pos)
{
    if (path_index == 0 && pos == 0)
    {
        cout << "Cub Training Path" << endl;
    }
    if (path_index == 1 && pos == 0)
    {
        cout << "Pride Lands Path" << endl;
    }

    string color = "";

    string playerState = "";
    for (int i = 0; i < _player_count; i++)
    {
        if (isPlayerOnTile(i, path_index, pos))
        {
            if (playerState.length())
            {
                playerState = playerState + '&' + to_string(i + 1);
            }
            else
            {
                playerState = to_string(i + 1);
            }
        }
    }
    // Player 1 is on the correct path at Position 0

    // Template for displaying a tile: <line filler space> <color start> |<player symbol or blank space > | <reset color><line filler space><endl>
    // Determine color to display
    if (_tiles[path_index][pos].getColor() == 'R')
    {
        color = RED;
    }
    else if (_tiles[path_index][pos].getColor() == 'G')
    {
        color = GREEN;
    }
    else if (_tiles[path_index][pos].getColor() == 'B')
    {
        color = BLUE;
    }
    else if (_tiles[path_index][pos].getColor() == 'U')
    {
        color = PURPLE;
    }
    else if (_tiles[path_index][pos].getColor() == 'N')
    {
        color = BROWN;
    }
    else if (_tiles[path_index][pos].getColor() == 'P')
    {
        color = PINK;
    }
    else if (_tiles[path_index][pos].getColor() == 'O')
    {
        color = ORANGE;
    }
    else if (_tiles[path_index][pos].getColor() == 'Y')
    {
        color = GREY;
    }

    if (playerState.length())
    {
        cout << color << "|" << (playerState) << "|" << RESET;
    }
    else
    {
        cout << color << "| |" << RESET;
    }
}

void Board::displayTrack(int path_index)
{
    for (int i = 0; i < _BOARD_SIZE; i++)
    {
        displayTile(path_index, i);
    }
    cout << endl;
}

void Board::displayBoard()
{
    displayTrack(0);
    cout << endl;
    displayTrack(1);
}


void Board::movePlayerPosition(int player_index, int pos)
{
    int currentPos = _Players[player_index].getPosition();
    if (currentPos + pos >= _BOARD_SIZE - 1)
    {
        _Players[player_index].setPosition(_BOARD_SIZE - 1);
    }
    else if (currentPos + pos < 0)
    {
        _Players[player_index].setPosition(0);
    }
    else
    {
        _Players[player_index].setPosition(currentPos + pos);
    }
}



// Move
int Board::_role_dice()
{
    return (rand() % 6) + 1;
}


bool Board::movePlayer(int player_index)
{
    int dice_roll = _role_dice();
    int prevPos = _Players[player_index].getPosition();

    // Check if the player has reached the end of the board
    if ((dice_roll + prevPos) >= _BOARD_SIZE - 1)
    {
        _Players[player_index].setPosition(_BOARD_SIZE - 1);
        return false;
    }
    else
    {
        _Players[player_index].setPosition(prevPos + dice_roll);
        return true;
    }
}

void Board::samePosition(int p1, int p2)
{

    cout << "Players are at the same position" << endl;
    cout << "Time for a challenge!" << endl;
    cout << "Who ever guesses a number closest to the random number generator wins!" << endl;

    // Random Number between 1 and 50
    int num = rand() % 50 + 1;
    int player1_guess;
    int player2_guess;

    cout << "Player " << p1 + 1 << ", guess a number between 1 and 50" << endl;
    cin >> player1_guess;

    cout << "Player " << p2 + 1 << ", guess a number between 1 and 50" << endl;
    cin >> player2_guess;
    
    int player1_diff = abs(num - player1_guess);
    int player2_diff = abs(num - player2_guess);    

    if (player1_diff < player2_diff)
    {
        cout << "Player " << p1 + 1 << " wins! You gain 100 Pride Points" << endl;
        _Players[p1].addPridePoints(100);
    }
    else if (player1_diff > player2_diff)
    {
        cout << "Player " << p2 + 1 << " wins! You gain 100 Pride Points" << endl;
        _Players[p2].addPridePoints(100);
    }
    else
    {
        cout << "It's a tie! Both players gain 50 Pride Points" << endl;
        _Players[p1].addPridePoints(50);
        _Players[p2].addPridePoints(50);
    }
}



bool Board::processMove(int player_index, int prevPos)
{
    char color = getTileColor(player_index);

    bool extraTurn = false;
    switch (color)
    {
        case 'G':
            regularTiles(player_index);
            break;
        
        case 'R':
            redTile(player_index);
            break;
        
        case 'B':
            // Extra turn
            extraTurn = blueTile(player_index);
            if (extraTurn)
            {
                return false;
            }
            else
            {
                break; 
            }


        
        case 'U':
            purpleTile(player_index);
            break;
        
        case 'N':
            brownTile(player_index, prevPos);
            break;
        
        case 'P':
            pinkTile(player_index);
            break;
        
        default:
            break;
    }

    return true;   
}


char Board::getTileColor(int player_index)
{
    int path = _Players[player_index].getPath();
    int pos = _Players[player_index].getPosition();
    
    return _tiles[path][pos].getColor();
}

// Tile Color
void Board::regularTiles(int playerIndex)
{
    cout << "Player " << playerIndex + 1 << " has landed on a regular tile" << endl;

    int triggerEvent = rand() % 2;


    int path = _Players[playerIndex].getPath();
    int advisor = _Players[playerIndex].getAdvisor();

    if (triggerEvent == 0)
    {
        int addPridePoints = _event.resolveEvent(path, advisor);
        _Players[playerIndex].adjustStats(0, 0, 0, addPridePoints);

        //_players[playerIndex].addPridePoints(_event.resolveEvent(path, advisor));
    }
}


bool Board::blueTile(int playerIndex)
{
    cout << "Player " << playerIndex + 1 << " has landed on a Blue tile" << endl;

    // Extra turn
    int playerStaminaPoints = _Players[playerIndex].getStamina();

    if (playerStaminaPoints >= 100)
    {
        cout << "You’ve found a peaceful oasis! This grants you an extra turn to keep moving forward" << endl;
        return true;
    }
    else
    {
        cout << "You do not have enough Stamina Points to move forward" << endl;
        
        // Transferring points
        cout << "You are allowed to transfer Pride Points to Stamina Points" << endl;
        cout << "Would you like to transfer 100 Pride Points to Stamina Points?" << endl;
        
        int choice;
        cout << "Yes (1) or No (0)" << endl;
        cin >> choice;
        switch (choice)
        {
            case 1:
                _Players[playerIndex].addPridePoints(-100);
                _Players[playerIndex].addStamina(100);
                return true;
                break;
            
            default:
                return false;
                break;
        }
    }

    
    cout << "You also gain 200 Stamina, Strength, and Wisdom points!" << endl;
    _Players[playerIndex].adjustStats(200, 200, 200, 0);
}

void Board::pinkTile(int playerIndex)
{
    cout << "Player " << playerIndex + 1 << " has landed on a Pink tile" << endl;
    cout << "Welcome to the land of enrichment! By landing here your Stamina, Strength, and Wisdom Points increase by 300" << endl;
    
   

    // Get Players Advisor
    int advisorIndex = _Players[playerIndex].getAdvisor();

    // Check if player has advisor
    if (advisorIndex == 0)
    {
        cout << "You have the option to select an Advisor" << endl;
        _Players[playerIndex].selectAdvisor();
    }
    else
    {
        cout << "You have the option to select a different Advisor. Would you like to? " << endl;
        cout << "Yes (1) or No (0)" << endl;

        int choice;
        cin >> choice;
        switch (choice)
        {
            case 1:
                _Players[playerIndex].selectAdvisor();
                break;

            default:
                break;
        }
    }

    // Increase Stamina, Strength, and Wisdom by 300
    _Players[playerIndex].adjustStats(300, 300, 300, 0);
}

void Board::redTile(int playerIndex)
{
    cout << "Player " << playerIndex + 1 << " has landed on a Red tile" << endl;
    _Players[playerIndex].adjustStats(-100, -100, -100, 0);

    // Move back 10 spaces
    movePlayerPosition(playerIndex, -10);
}

void Board::brownTile(int playerIndex, int prevPos)
{
    cout << "Player " << playerIndex + 1 << " has landed on a Brown tile" << endl;
    cout << "The Hyenas are on the prowl! They drag you back to where you last were." << endl;
    cout << "In addition, your Stamina Points are reduced by 200!" << endl;
    _Players[playerIndex].addStamina(-200);

    // Move back to the previous tile
    setPlayerPosition(playerIndex, prevPos);
}


void Board::purpleTile(int playerIndex)
{
    bool askedQuestion = false;
    while (!askedQuestion)
    {
        int wisdomPoints = _Players[playerIndex].getWisdom();
        // Check Wisdom Points
        if (wisdomPoints >= 100)
        {
            cout << "Player " << playerIndex + 1 << " has landed on a Purple tile" << endl;
            cout << "Time for a test of wits! you will face a random riddle" << endl;
            cout << "If you answer correctly, you will gain 500 Wisdom Points!" << endl;

            // Riddle
            int riddleIndex = _riddle.selectRiddle();
            bool correct = _riddle.processRiddle(riddleIndex);

            if (correct)
            {
                cout << "Correct! Gained 500 Wisdom Points!" << endl;
                _Players[playerIndex].addWisdom(500);
            }
            else
            {
                cout << "Incorrect! The correct answer was: " << _riddle.getAnswer(riddleIndex) << endl;
            }
            askedQuestion = true;
        }
        else
        {

            cout << "Player " << playerIndex + 1 << " has landed on a Purple tile" << endl;
            cout << "You do not have enough Wisdom Points to answer the riddle" << endl;
            cout << "You are allowed to transfer Pride Points to Wisdom Points" << endl;
            cout << "Would you like to transfer 100 Pride Points to Wisdom Points?" << endl;
            int choice;
            cout << "Yes (1) or No (0)" << endl;
            cin >> choice;
            switch (choice)
            {
            case 1:
                _Players[playerIndex].addPridePoints(-100);
                _Players[playerIndex].addWisdom(100);
                break;
            
            default:
                return;
            }
        }
    }
    
}