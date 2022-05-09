#include "Player.hpp"
#pragma once
using namespace std;
namespace coup{
    class Assassin : public Player
    {
    
    
    public:
        void coup(Player &p);
        void block(Player &p);
        string role();
        void someOneBlockme();
        ~Assassin();
        Assassin(Game &game, string name);


    private:
        Player *mordechaiTraget;
    
    
     
    
    };






}