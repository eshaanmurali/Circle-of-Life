#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <iomanip>

using namespace std;

class Player{
    private:
        // Attributes
        string _name;
        int _strength, _stamina, _wisdom, _pride_points, _age;

        // Board Information
        int _pos;
        int _path;

        // Advisor
        vector <string> _advisors = {"None (0)", "Rafiki (1)", "Nala (2)", "Sarabi (3)", "Zazu (4)", "Sarafina (5)"};
        int _advisor_id;

    public:
        // Constructor
        Player();
        Player(string, int, int, int, int, int);

        // Attributes
        // Getter
        string getName();
        int getStrength();
        int getStamina();
        int getWisdom();
        int getPridePoints();
        int getAge();

        // Setter
        void setName(string);  

        void setStrength(int);
        void addStrength(int);

        void setStamina(int);
        void addStamina(int);
        
        void setWisdom(int);
        void addWisdom(int);

        void setPridePoints(int);
        void addPridePoints(int);

        void setAge(int);
        void addAge(int);


        void adjustStats(int strength, int stamina, int wisdom, int pridePoints);

        // Board Information
        // Getters
        int getPath();
        int getPosition();

        // Setters
        void setPath(int);
        void setPosition(int);


        // Advisor
        int getAdvisor();
        void setAdvisor(int);
        void selectAdvisor(); 
        void printAdvisorName();
       

        // Actions
        int finalEvaluation();

        // Display
        void printAdvisor();
        void printStats();
};

#endif