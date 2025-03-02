#include "Game.h"
#include "utils.h"

Game::Game()
{
    // Initialize the game board
    _game_board = Board(2);
    _num_players = 2;

    // Initialize the game ended flag
    _game_ended = false;
    _players_finished.clear();
    for (int i = 0; i < 2; i++)
    {
        _players_finished[i] = false;
    }
    
    // Initialize the Advisors
    _advisors.clear();
    for (int i = 0; i < 2; i++)
    {
        _advisors.push_back(0);
    }
}

Game::Game(int num_players)
{
    // Initialize the game board
    _game_board = Board(num_players);
    _num_players = num_players;

    // Initialize the game ended flag
    _game_ended = false;
    for (int i = 0; i < num_players; i++)
    {
        _players_finished.push_back(false);
    }

    // Initialize the Advisors
    for (int i = 0; i < num_players; i++)
    {
        _advisors.push_back(0);
    }
}

bool Game::mainMenu(int playerIndex){
    int num;
    cout << "* * * * * * * * * * * * * * * * * * * * * * * *" << endl;
    cout << " *             The Circle of Life            *" << endl;
    cout << " *  Main Menu: Select an option to continue  *" << endl;
    cout << " *         1. Check Player Progress (1)      *" << endl;
    cout << " *          2. Review Character (2)          *" << endl;
    cout << " *            3. Check Position (3)          *" << endl;
    cout << " *          4. Review Your Advisor (4)       *" << endl;
    cout << " *             5. Move Forward (5)           *" << endl;
    cout << " *           6. Check Final Stats (6)        *" << endl;
    cout << " *              7. Quit Game (7)             *" << endl;   
    cout << "* * * * * * * * * * * * * * * * * * * * * * * *" << endl;

    cin >> num;

    switch(num)
    {
        case 1:
            // Player Stats
            _game_board.getPlayer(playerIndex).printStats();

            // Convert Stats using Pride Points
            int choice;
            cout << "Do you want to convert Pride Points to Stats?" << endl;
            cout << "Yes (1) or No (0)" << endl;
            cin >> choice;

            switch(choice)
            {
                case 1:
                    int stat_choice;
                    cout << "What stat do you want to convert?" << endl;
                    cout << "Strength (1), Stamina (2), Wisdom (3)" << endl;
                    cin >> stat_choice;

                    int points;
                    cout << "How many points do you want to convert?" << endl;
                    cin >> points;

                    switch(stat_choice)
                    {
                        case 1:
                            _game_board.getPlayer(playerIndex).addStrength(points);
                            _game_board.getPlayer(playerIndex).addPridePoints(-points);
                            break;
                        case 2:
                            _game_board.getPlayer(playerIndex).addStamina(points);
                            _game_board.getPlayer(playerIndex).addPridePoints(-points);
                            break;
                        case 3:
                            _game_board.getPlayer(playerIndex).addWisdom(points);
                            _game_board.getPlayer(playerIndex).addPridePoints(-points);
                            break;
                    }

                    break;

                default:
                    break;
            }
            return false;

        case 2:
            // Player Name and Age
            cout << "Character is " << _game_board.getPlayer(playerIndex).getName() << endl;
            cout << "Age is " << _game_board.getPlayer(playerIndex).getAge() << endl;
            return false;

        case 3:
            // Display Board
            _game_board.displayBoard();
            return false;

        case 4:
            // Print Advisor
            _game_board.getPlayer(playerIndex).printAdvisorName();
            return false;

        case 5:
            return true;
        
        case 6:
            // Final Stats
            _game_board.getPlayer(playerIndex).finalEvaluation();
            return false;
        
        case 7:
            _game_ended = true;
            return false;
        default:
            cout << "Invalid Number" << endl;
            return false;
    }
}



void Game::loadCharacters()
{
    ifstream fin;
    string character;
    string tokens[6];

    // Open Characters file
    fin.open("characters.txt");
    
    if (fin.fail())
    {
        cout << "Failed to open file" << endl;
        return;
    }

    getline(fin, character);

    while (getline(fin, character))
    {
        // Make each line a player object
        split(character, '|', tokens, 6);
        Player p(tokens[0], stoi(tokens[2]), stoi(tokens[3]), stoi(tokens[4]), stoi(tokens[5]), stoi(tokens[1]));

        _Characters.push_back(p);
    }
}

void Game::printCharacters()
{
    int size = _Characters.size();

    for (int i = 0; i < size; i++)
    {
        cout << "Character " << i + 1 << endl;
        _Characters[i].printStats();

        //_characters[i].printStats();
        cout << endl;
    }
}

int Game::matchCharacter(string name)
{
    int length = _Characters.size();

    for (int i = 0; i < length; i++)
    {
        if (_Characters[i].getName() == name)
        {
            return i;
        }
    }

    return -1;
}

void Game::selectCharacter(){
    loadCharacters();

    string character;
    for (int i = 0; i < _num_players; i++)
    {
        printCharacters();

        cout << "Choose your character Player " << i + 1 << endl;
        cin >> character;

        // Match Character by int

        int index = matchCharacter(character);

        while (index == -1)
        {
            printCharacters();

            cout << "Choose your character Player " << i + 1 << endl;
            cin >> character;

            index = matchCharacter(character);
        }

        Player temp_player = _Characters[index];
        _Characters.erase(_Characters.begin() + index);
        _game_board.iniitializePlayer(i, temp_player);
    }
}


void Game::setupGame()
{
    Player temp;

    // Initialize Players
    selectCharacter();
    

    // Find Path Type
    vector <int> Players_Paths;
    int path;

    for (int i = 0; i < _num_players; i++)
    {
        cout << "Player " << i + 1 << ", Choose your path type: Cub Training (0) or Straight to the Pride Lands (1)" << endl;
        cin >> path;

        switch (path)
        {
            case 0:
                temp = _game_board.getPlayer(i);
                temp.selectAdvisor();

                // Update player in board
                _game_board.setPlayer(i, temp);

                // Update advisor in game
                _advisors[i] = temp.getAdvisor();

                // Update path in board
                _game_board.setPlayerPath(i, path);
                break;
            case 1:
                // Update path in board
                _game_board.setPlayerPath(i, path);
                break;
            
            default:
                cout << "Invalid Path Type" << endl;
                break;
        }

        Players_Paths.push_back(path);
    }
}



void Game::runGame()
{
    int player = 0;
    while (!_game_ended)
    {
        // Skip the turn if the player has finished
        if (_players_finished[player])
        {
            player = (player + 1) % _num_players; // Move to the next player
            continue;
        }

        cout << endl;
        cout << "Player " << player + 1 << "'s Turn" << endl;

        if (mainMenu(player))
        {
            int prevPos = _game_board.getPlayerPosition(player);
            _game_board.movePlayer(player);

            if (_game_board.getPlayerPosition(player) == 51)
            {
                _players_finished[player] = true;
            }

            // Check if all players are finished
            bool all_players_finished = true;
            for (int i = 0; i < _num_players; i++)
            {
                if (!_players_finished[i])
                {
                    all_players_finished = false;
                    break;
                }
            }

            if (all_players_finished)
            {
                _game_ended = true;
                return; // End the game if all players finished
            }

            // Check if any players are at the same position
            // Make sure the position is not final position
            if (_game_board.getPlayerPosition(player) != 51)
            {
                for (int i = 0; i < _num_players; i++)
                {
                    if (i != player && _game_board.getPlayerPosition(i) == _game_board.getPlayerPosition(player))
                    {
                        _game_board.samePosition(i, player); 
                        break;
                    }
                }
            }
            

            // Process the move for the current player
            if (_game_board.processMove(player, prevPos))
            {
                player = (player + 1) % _num_players; 
            }
            else
            {
                continue; 
            }
        }
        else
        {
            continue; // Pop up the menu again if the player doesn't want to move
        }
    }

    _game_board.displayBoard();
}


void Game::resolveGame(){
    vector <int> Players_Final_Points;

    for (int i = 0; i < _num_players; i++)
    {
        Players_Final_Points.push_back(_game_board.getPlayer(i).finalEvaluation());
    }

    // Find Winner sort players final points
    int winner = Players_Final_Points[0];
    for (int i = 1; i < _num_players; i++)
    {
        if (Players_Final_Points[i] > Players_Final_Points[winner])
        {
            winner = i;
        }
    }


    
    ofstream fout("GameResults.txt");
    if (fout.is_open()) 
    {
        fout << "The winner is Player " << winner + 1 << " with " << Players_Final_Points[winner] << " Pride Points!" << endl;
        fout << endl;


        fout << "Final Results" << endl;
        for (int i = 0; i < _num_players; i++)
        {
            fout << "Player " << i + 1 << _game_board.getPlayer(0).getName() << " Pride Points: " << Players_Final_Points[i] << endl;
            fout << endl;
        }

        fout.close();
    } 
    else 
    {
        cout << "Failed to open file for writing results." << endl;
    }
    

}

