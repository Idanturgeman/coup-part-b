#include "Captain.hpp"
namespace coup
{
    Captain::Captain(Game &game, string name) : Player(game,move(name))
    {
        this->pFrom = NULL;
    }

    Captain::~Captain()
    {
    }
    void Captain::block(Player &p){
        int s = p.lastAction.compare("steal");
        if (s == 0)
        {
            p.someOneBlockme();
        }
        else{
            throw invalid_argument("you can't block this action");  
        }
        
    }
    void Captain::someOneBlockme(){
        int s = this->lastAction.compare("steal");
        int s1 = this->lastAction.compare("stealOne");
        int s2 = this->lastAction.compare("stealTwo");
        int f = this->lastAction.compare("foreign_aid");
        if (s2 == 0)
        {
            this->money -=2;
            this->pFrom->money += 2;
        }
        else if ( s1 == 0)
        {
            this->money -=1;
            this->pFrom->money += 1;
        }
        else if (s == 0)
        {

        }
        else if (f == 0)
        {
            this->money -= 2;
        }
        else{
            throw invalid_argument("you cant block this action");
        }
    }
    void Captain::steal(Player &p){
        isMyTurn();
        if (p.money >= 2)
        {   
            this->money += 2;
            p.money -= 2;
            this->pFrom = &p;
            endMyTurn("stealTwo");
        }
        else if (p.money == 1)
        {
            this->money += 1;
            p.money -= 1;
            this->pFrom = &p;
            endMyTurn("stealOne");
        }
        else{
            this->pFrom = &p;
            endMyTurn("steal");
        }
    }

    string Captain::role(){
        return "Captain";
    }
}