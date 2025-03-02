#ifndef RIDDLE_H
#define RIDDLE_H

#include <iostream>
#include <fstream>

#include "utils.h"

using namespace std;

struct Riddle
{
    string question;
    string answer;
};

class Riddles
{
    private:
        Riddle riddles[27];
        vector <Riddle> _riddles;
        void loadRiddles();
    public:
        Riddles();
        string getAnswer(int riddle_index);

        int selectRiddle();


        bool processRiddle(int riddle_index);
};


#endif
