//#include "util.h"
#include <iostream>

using namespace std;


int split(string input_string, char separator, string arr[], const int ARR_SIZE)
{
    int count = 0;
    int prevLocation = 0;
    int length = input_string.length();

    if (length == 0)
    {
        return 0;
    }

    for (int i = 0; i < length; i++)
    {
        if (input_string[i] == separator)
        {
            if (count > ARR_SIZE - 1)
            {
                return -1;
            }
            arr[count] = input_string.substr(prevLocation, i - prevLocation);
            prevLocation = i + 1;
            count++;
        }
    }

    if (count < ARR_SIZE)
    {
        arr[count] = input_string.substr(prevLocation);
        count++;
    }
    else
    {
        return -1;
    }

    if (count == 0)
    {
        return 0;
    }

    return count;
}


// Spinner for Game
void printSpinner(int number) {
    cout << "  -----------  " << endl;
    cout << " /           \\ " << endl;
    cout << "/     " << number << "     \\" << endl;
    cout << "\\           / " << endl;
    cout << " \\_________/  " << endl;
    cout << "     ^         " << endl;
    cout << "    SPINNER     " << endl;
}