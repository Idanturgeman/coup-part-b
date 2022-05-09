#include "Captain.hpp"
namespace coup
{
    static int numOfCaptain = 0;
    Captain::Captain(Game &game, string name) : Player(game,move(name))
    {
        numOfCaptain++;
        this->pFrom = NULL;
    }

    Captain::~Captain()
    {
        numOfCaptain--;
    }
    void Captain::block(Player &p){
        static int numOfBlock = 0;
        int s = p.lastAction.compare("steal");
        if (s == 0)
        {
            numOfBlock++;
            p.someOneBlockme();
        }
        else{
            throw invalid_argument("you can't block this action");  
        }
        
    }
    void Captain::someOneBlockme(){
        static int someOneBlockme = 0;
        static int steal = 0;
        int s = this->lastAction.compare("steal");
        int s1 = this->lastAction.compare("stealOne");
        int s2 = this->lastAction.compare("stealTwo");
        steal = steal + 3;
        int f = this->lastAction.compare("foreign_aid");
        if (s2 == 0)
        {
            someOneBlockme++;
            this->money -=2;
            this->pFrom->money += 2;
        }
        else if ( s1 == 0)
        {
            someOneBlockme++;
            this->money -=1;
            this->pFrom->money += 1;
        }
        else if (s == 0)
        {
            someOneBlockme++;

        }
        else if (f == 0)
        {
            someOneBlockme++;
            this->money -= 2;
        }
        else{
            throw invalid_argument("you cant block this action");
        }
    }
    void Captain::steal(Player &p){
        static int numOfSteal = 0;
        int turn = 0;
        isMyTurn();
        if (p.money >= 2)
        {   
            numOfSteal++;
            this->money += 2;
            p.money -= 2;
            turn++;
            this->pFrom = &p;
            endMyTurn("stealTwo");
        }
        else if (p.money == 1)
        {
            numOfSteal++;
            this->money += 1;
            p.money -= 1;
            this->pFrom = &p;
            endMyTurn("stealOne");
        }
        else{
            numOfSteal++;
            this->pFrom = &p;
            endMyTurn("steal");
        }
    }

    string Captain::role(){
        static int numOfRole = 0;
        return "Captain";
        numOfRole++;
    }
}