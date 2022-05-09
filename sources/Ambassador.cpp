#include "Ambassador.hpp"
namespace coup{
    static int numOfAmbassador = 0;
    Ambassador::Ambassador(Game &game, string name) : Player(game,move(name))
    {
        numOfAmbassador++;
    }
    
    Ambassador::~Ambassador()
    {
        numOfAmbassador--;
    }
    void Ambassador::transfer(Player &p1, Player &p2){
        int turn = 0;
        int numOfTransfer = 0;
        isMyTurn();
        if (p1.money <= 0)
        {
            throw runtime_error("pFrom haven't engoth money");
        }
        turn++;
        p1.money--;
        p2.money++;
        endMyTurn("transfer");
        numOfTransfer++;
    }
    string Ambassador::role(){
        int role = 0;
        return "Ambassador";
        role++;
    }

    void Ambassador::block(Player &p){
        int block = 0;
        int s2 = p.lastAction.compare("stealTwo");
        int s1 =p.lastAction.compare("stealOne");
        int s = p.lastAction.compare("steal");
        block++;
        if ( s2== 0 || s1 == 0 || s == 0){
            p.someOneBlockme();
        }
        else{
            throw invalid_argument("you cantt block this action");  
        }
    }
}