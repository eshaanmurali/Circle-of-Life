#include "Riddles.h"

Riddles::Riddles()
{
    loadRiddles();
}

string removeHidden(string str)
{
    string temp = "";
    for(int i = 0; i < (int)str.length(); i++)
    {
        if(str[i] == '\r')
        {
            break;
        }
        temp += str[i];
    }
    return temp;
}

void Riddles::loadRiddles()
{
    ifstream fin;
    string riddle;
    string tokens[2];

    // Open Riddles File
    fin.open("riddles.txt");
    if (fin.fail())
    {
        cout << "Failed to open file" << endl;
        return;
    }

    getline(fin, riddle);

    while (getline(fin, riddle))
    {
        // Convert Riddles line to an object Riddle
        split(riddle, '|', tokens, 2);
        
        Riddle r;
        r.question = tokens[0];
        r.answer = removeHidden(tokens[1]);
        //cout << r.answer << endl;

        _riddles.push_back(r);
    }
}

string Riddles::getAnswer(int riddle_index)
{
    return _riddles[riddle_index].answer;
}

int Riddles::selectRiddle()
{
    int numRiddles = _riddles.size();

    int riddle_index = rand() % numRiddles;
    return riddle_index;
}

bool Riddles::processRiddle(int riddle_index)
{
    string guess;
    string answers;

    cout << _riddles[riddle_index].question << endl;

    cin.clear();
    cin.ignore();
    getline(cin, guess);

   
    // check if guess is correct
    if (guess == riddles[riddle_index].answer)
    {
        return true;
    }
    else
    {
        return false;
    }
}
