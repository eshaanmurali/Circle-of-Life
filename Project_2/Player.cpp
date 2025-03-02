#include "Player.h"

// Constructors
Player::Player()
{
    // Initialize Player Position to 0
    _pos = 0;

    _advisor_id = 0;
}
Player::Player(string name, int strength, int stamina, int wisdom, int pride_points, int age)
{
    _name = name;
    _strength = strength;
    _stamina = stamina;
    _wisdom = wisdom;
    _pride_points = pride_points;
    _age = age;
    _advisor_id =0;
}

// Getters
// Player Elements
string Player::getName()
{
    return _name;
}

int Player::getStrength()
{
    return _strength;
}

int Player::getStamina()
{
    return _stamina;
}

int Player::getWisdom()
{
    return _wisdom;
}

int Player::getPridePoints()
{
    return _pride_points;
}

int Player::getAge()
{
    return _age;
}


// Setters
// Name
void Player::setName(string name)
{
    _name = name;
}

// Strength
void Player::setStrength(int strength)
{
    if (strength < 10 || strength > 1000)
    {
        _strength = strength;
    }
    else
    {
        _strength = 100;
    }
}
void Player::addStrength(int strength)
{
    if (_strength + strength < 10 || _strength + strength > 1000)
    {
        _strength += strength;
    }
    else
    {
        _strength = 100;
    }
}

// Stamina
void Player::setStamina(int stamina)
{
    if (stamina < 10 || stamina > 1000)
    {
        _stamina = stamina;
    }
    else
    {
        _stamina = 100;
    }
}
void Player::addStamina(int stamina)
{
    if (_stamina + stamina < 10 || _stamina + stamina > 1000)
    {
        _stamina += stamina;
    }
    else
    {
        _stamina = 100;
    }
}

// Wisdom
void Player::setWisdom(int wisdom)
{
    if (wisdom < 10 || wisdom > 1000)
    {
        _wisdom = wisdom;
    }
    else
    {
        _wisdom = 100;
    }
}
void Player::addWisdom(int wisdom)
{
    if (_wisdom + wisdom < 10 || _wisdom + wisdom > 1000)
    {
        _wisdom += wisdom;
    }
    else
    {
        _wisdom = 100;
    }
}

// Pride Points
void Player::setPridePoints(int pride_points)
{
    if (pride_points < 0)
    {
        _pride_points = 0;
    }
    else
    {
        _pride_points = pride_points;
    }
}
void Player::addPridePoints(int pride_points)
{
    if (_pride_points + pride_points < 0)
    {
        _pride_points = 0;
    }
    else
    {
        _pride_points += pride_points;
    }
}

// Age
void Player::setAge(int age)
{
    if (age < 1 || age > 20)
    {
        _age = age;
    }
    else
    {
        _age = 1;
    }
}
void Player::addAge(int age)
{
    if (_age + age < 1 || _age + age > 20)
    {
        _age += age;
    }
    else
    {
        _age = 1;
    }
}

void Player::adjustStats(int strength, int stamina, int wisdom, int pridePoints)
{
    _strength += strength;
    _stamina += stamina;
    _wisdom += wisdom;
    _pride_points += pridePoints;

    if (strength != 0)
    {
        cout << "Adjusted strength by " << strength << " points" << endl;
    }
    if (stamina != 0)
    {
        cout << "Adjusted stamina by " << stamina << " points" << endl;
    }
    if (wisdom != 0)
    {
        cout << "Adjusted wisdom by " << wisdom << " points" << endl;
    }
    if (pridePoints != 0)
    {
        cout << "Adjusted Pride Points by " << pridePoints << " points" << endl;
    }
}


// Board Elements
// Getters
int Player::getPath()
{
    return _path;
}

int Player::getPosition()
{
    return _pos;
}

// Setters
void Player::setPath(int path)
{
    if (path == 0)
    {
        _pride_points += -5000;
        _stamina += 500;
        _strength += 500;
        _wisdom += 1000;

        //_advisors[0].loadAdvisors();
        //_advisors[0].pickAdvisor();
    }
    else
    {
        _pride_points += 5000;
        _stamina += 200;
        _strength += 200;
        _wisdom += 200;
    }
    
    _path = path;
}

void Player::setPosition(int pos)
{
    _pos = pos;
}


// Advisor
void Player::selectAdvisor()
{
    int num;
    cout << "Select an Advisor" << endl;
    printAdvisor();
    cin >> num;
    
    //_advisors.erase(_advisors.begin() + num);

    _advisor_id = num;
}


int Player::getAdvisor()
{
    return _advisor_id;
}

void Player::printAdvisorName()
{
    cout << _advisors[_advisor_id] << endl;
}



// Actions
int Player::finalEvaluation()
{
    cout << "Player " << _name << "'s final stats calculation!" << endl;

    int extraStamina = _stamina / 100;
    cout << "Extra Stamina: " << extraStamina << endl;

    int extraStrength = _strength / 100;
    cout << "Extra Strength: " << extraStrength << endl;

    int extraWisdom = _wisdom / 100;
    cout << "Extra Wisdom: " << extraWisdom << endl;

    int extraPoints = 1000 * (extraStamina + extraStrength + extraWisdom);
    cout << "Extra Points: " << extraPoints << endl;

    _pride_points = _pride_points + extraPoints;
    cout << "Player " << _name << " has " << _pride_points << " Pride Points!" << endl;
    cout << endl;

    return _pride_points;
}


void Player::printAdvisor()
{
    for (int i = 0; i < 6; i++)
    {
        cout << _advisors[i] << " ";
    }
}

void Player::printStats() {
        cout << "Player: " << _name << "  " << "Age: " << _age << endl;

        cout << left << setw(15) << "Strength:" << setw(5) << _strength << endl;
        cout << left << setw(15) << "Stamina:" << setw(5) << _stamina << endl;
        cout << left << setw(15) << "Wisdom:" << setw(5) << _wisdom << endl;
        cout << left << setw(15) << "Pride Points:" << setw(5) << _pride_points << endl;
}