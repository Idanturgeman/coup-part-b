#pragma once
#include <iostream>
#include <vector>
#include <stdexcept>
#include <string>
#include <algorithm>
#include "Player.hpp"
using namespace std;

namespace coup
{
    class Player;
    class Game
    {
    private:
        // vector<string> playersList;
        vector<Player*> playersList;
    public:
        // vector<string> playersList;
        unsigned int i;
        unsigned int numOfPlayers;
        unsigned int gameStart;
        Game(/* args */);
        // {
        //     this->i = 0;
        // };
        vector<string> players();
        void addPlayer(Player *p);
        string turn();
        string winner();
        void nextTurn();
        // void addPlayer(player p);
        ~Game();
    };
    
} // namespace coup