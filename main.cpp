// one of the main purposes of using static class is to try to keep the count of a particular attribute in a class in this case, num_player
// the statc varible belongs to the class, not to the object

//player.h
/////////////////////////////////////////////////////////////////////////
#pragma once
#include <string>
#include <iostream>

using namespace std;


class Player
{
private:
    static int num_player; // this belongs to the class
    string name;
    int xp;
    int health;
public:
    string getName() const;
    Player(string nameValue = "None", int xpValue = 0, int healthValue = 0);   
    Player(const Player &source);
    ~Player();
    static int get_num_player();
};




///////////////////////////////////////////////////////////////////////////////
//Player.cpp


#include "Player.h"
#include <string>
#include <iostream>

using namespace std;

int Player::num_player {0};

string Player::getName() const {
    return name;
}

Player::Player(string nameValue, int xpValue, int healthValue)
:name{nameValue},xp{xpValue},health{healthValue} {
    num_player++;
}

Player::Player(const Player &source)
:Player{name=source.name,xp = source.xp, health = source.health} {
    
}

Player::~Player() {
    num_player--;
}

 int Player::get_num_player() {
    return num_player;
}

///////////////////////////////////////////////////////////////////////////////
//main.cpp

#include <iostream>
#include <string>
#include <Player.h>

using namespace std;

void display_num() {
    cout << "The number of player is "<<Player::get_num_player() << endl; 
}

int main() {
    display_num();
    Player eddie("eddie",10,12);
    Player k("eddie",10,12);
    display_num();
    return 0;
}
