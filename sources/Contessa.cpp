#include "Contessa.hpp"
namespace coup{
    Contessa::Contessa(Game &game, string name) : Player(game, move(name))
    {
    }
    
    Contessa::~Contessa()
    {
    }
    void Contessa::block(Player &p){
        int k = p.lastAction.compare("kill");
        if ( k == 0)
        {
            p.someOneBlockme();
        }
        else{
            throw invalid_argument("you can't block this action");  
        }
    }
    string Contessa::role(){
        return "Contessa";
    }
}