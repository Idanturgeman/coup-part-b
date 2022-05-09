#pragma once
#include "Game.hpp"
#include <string>
using namespace std;
namespace coup{
    class Game;
    class Player
    {   
    protected:
        Game *game;
        
    public:
        int money;
        string name;
        bool isAlive;
        string lastAction;
        Player(Game& game, string name);//{
        //     this->game = game;
        //     this->name = name;
        //     this->money = 0;
        // };
        void income();
        void foreign_aid();
        void coup(Player &p);
        virtual string role();
        int coins() const;
        void isMyTurn();
        void endMyTurn(string last);
        virtual void someOneBlockme();
        ~Player();
    };
    
}