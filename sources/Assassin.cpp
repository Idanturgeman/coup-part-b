#include "Assassin.hpp"
namespace coup
{
    Assassin::Assassin(Game &game, string name) : Player(game, move(name))
    {
        this->mordechaiTraget = NULL;
    }

    Assassin::~Assassin()
    {
    }
    string Assassin::role(){
        return "Assassin";
    }
    void Assassin::someOneBlockme(){
        int f = this->lastAction.compare("foreign_aid");
        int k = this->lastAction.compare("kill");
        if (f == 0)
        {
            this->money -= 2;
        }
        else if (k == 0)
        {
            this->mordechaiTraget->isAlive = true;
        }
        else{
            throw invalid_argument("you cant block this action");
        }
    }
    void Assassin::coup(Player &p){
        isMyTurn();
        const int seven = 7;
        const int three = 3;
        if (!p.isAlive)
        {
            throw runtime_error("this player is dead!");
        }
        if (this->money < three)
        {
            throw runtime_error("this Assassin havn't engoth money");
        }
        p.isAlive = false;
        this->mordechaiTraget = &p;
        if (this->money >= seven)
        {
            money -= seven;
            this->endMyTurn("coup");
        }
        else{
            money -= three;
            this->endMyTurn("kill");
        }
    }
        

}