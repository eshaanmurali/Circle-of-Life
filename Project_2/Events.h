#ifndef EVENTS_H
#define EVENTS_H 

#include <iostream>
#include <fstream>

#include "utils.h"

struct eventsInfo
{
    string description;
    int path_type;
    int advisor;
    int pride_points;
};

class Events
{
    private:
        vector <eventsInfo> _events;

        eventsInfo _negative_events[20];
        eventsInfo _positive_events[30];

        void loadNegativeEvents();
        void loadPositiveEvents();

    public:
        Events();
        int resolveEvent(int path_type, int advisor);
};

#endif