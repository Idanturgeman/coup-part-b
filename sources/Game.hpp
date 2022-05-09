#pragma once
#include "Player.hpp"
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <stdexcept>

using namespace std;

namespace coup
{
    class Player;
    class Game
    {
    public:
        Game();
        ~Game();
        string winner();
        string turn();
        void nextTurn();
        void addPlayer(Player *p);
        unsigned int gameStart;
        unsigned int i;
        unsigned int numOfPlayers;
        vector<string> players();

    private:
        vector<Player*> playersList;

    };
    
}