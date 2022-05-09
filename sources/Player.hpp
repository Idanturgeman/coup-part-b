#pragma once
#include "Game.hpp"
#include <string>
using namespace std;
namespace coup{
    class Game;
    class Player
    {   
      
    public:
        Player(Game& game, string name);
        ~Player();
        bool isAlive;
        void foreign_aid();
        int money;
        void coup(Player &p);
        int coins() const;
        void income();
        void isMyTurn();
        string name;
        void endMyTurn(string last);
        string lastAction;
        virtual string role();
        virtual void someOneBlockme();
       
    protected:
        Game *game;
      
    };
    
}