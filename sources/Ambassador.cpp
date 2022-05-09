#include "Ambassador.hpp"
namespace coup{
    Ambassador::Ambassador(Game &game, string name) : Player(game,move(name))
    {
    }
    
    Ambassador::~Ambassador()
    {
    }
    void Ambassador::transfer(Player &p1, Player &p2){
        isMyTurn();
        if (p1.money <= 0)
        {
            throw runtime_error("pFrom haven't engoth money");
        }
        p1.money--;
        p2.money++;
        endMyTurn("transfer");
    }
    string Ambassador::role(){
        return "Ambassador";
    }

    void Ambassador::block(Player &p){
        int s2 = p.lastAction.compare("stealTwo");
        int s1 =p.lastAction.compare("stealOne");
        int s = p.lastAction.compare("steal");
        if ( s2== 0 || s1 == 0 || s == 0){
            p.someOneBlockme();
        }
        else{
            throw invalid_argument("you cantt block this action");  
        }
    }
}