#include "Events.h"


// Fix this
Events::Events()
{
    loadNegativeEvents();
    loadPositiveEvents();
}

void Events::loadNegativeEvents()
{
    ifstream fin;
    string negative_event;
    string tokens[4];

    // Open File Negative Events
    fin.open("NegativeEvents.txt");
    if (fin.fail())
    {
        cout << "Failed to open file" << endl;
        return;
    }

    getline(fin, negative_event);
    //int index = 0;
    while(getline(fin, negative_event)){
        // Convert line into an object eventsInfo

        split(negative_event, '|', tokens, 4);
        
        eventsInfo e;
        e.description = tokens[0];
        e.path_type = stoi(tokens[1]);
        e.advisor = stoi(tokens[2]);
        e.pride_points = stoi(tokens[3]);

        _events.push_back(e);
        //_negative_events[index] = e;

        //index++;
    }
}

void Events::loadPositiveEvents()
{
    ifstream fin;
    string positive_event;
    string tokens[4];

    // Open file Positive Events
    fin.open("PositiveEvents.txt");
    if (fin.fail())
    {
        cout << "Failed to open file" << endl;
        return;
    }

    getline(fin, positive_event);
    //int index = 0;
    while(getline(fin, positive_event)){
        // Convert line into an object eventsInfo

        split(positive_event, '|', tokens, 4);
        
        eventsInfo e;
        e.description = tokens[0];
        e.path_type = stoi(tokens[1]);
        e.advisor = stoi(tokens[2]);
        e.pride_points = stoi(tokens[3]);

        _events.push_back(e);
        //_positive_events[index] = e;

        //index++;
    }
}


int Events::resolveEvent(int path_type, int advisor)
{
    /*
    path_type is the players path
    _path_type is the path of the event

    advisor is the players advisor
    _advisor is the advisor of the event
    */

    int numEvents = _events.size();
    int index = rand() % numEvents;

    int _path_type = _events[index].path_type;
    int _advisor = _events[index].advisor;

    if (index < 20) // Negative Event
    {
        if (path_type == _path_type && advisor == _advisor) // Advisor Saved player
        {
            cout << "Your advisor saved you from the event: " << _negative_events[index].description << endl;
            return 0;
        }
        else if (path_type != _path_type && _path_type != 2) // player on a different path
        {
            return 0;
        }
        else // player affected
        {
            cout << "Negative Event Occured: " << _events[index].description << endl;
            return _events[index].pride_points;
        }
    }

    else // Positive Event
    {
        if (path_type == _path_type || path_type == 2) // Event occurs on player path
        {
            cout << "Positive Event Occured: " << _events[index].description << endl;
            return _events[index].pride_points;
        }
        else
        {
            return 0;
        }
    }
    
}