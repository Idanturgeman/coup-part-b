#include "Contessa.hpp"
namespace coup{
    static int numOfContessa = 0;
    Contessa::Contessa(Game &game, string name) : Player(game, move(name))
    {
        numOfContessa++;
    }
    
    Contessa::~Contessa()
    {
        numOfContessa--;
    }
    void Contessa::block(Player &p){
        static int block = 0;
        int k = p.lastAction.compare("kill");
        if ( k == 0)
        {
            block++;
            p.someOneBlockme();
        }
        else{
            throw invalid_argument("you can't block this action");  
        }
    }
    string Contessa::role(){
        static int role = 0;
        return "Contessa";
        role++;
    }
}