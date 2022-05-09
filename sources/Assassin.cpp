#include "Assassin.hpp"
namespace coup
{
    static int numOfAssassin = 0;
    Assassin::Assassin(Game &game, string name) : Player(game, move(name))
    {
        numOfAssassin++;
        this->mordechaiTraget = NULL;
    }

    Assassin::~Assassin()
    {
        numOfAssassin--;
    }
    string Assassin::role(){
        int role = 0;
        return "Assassin";
        role++;
    }
    void Assassin::someOneBlockme(){
        int someOneBlockme = 0;
        int f = this->lastAction.compare("foreign_aid");
        int k = this->lastAction.compare("kill");
        if (f == 0)
        {
            this->money -= 2;
            someOneBlockme++;
        }
        else if (k == 0)
        {
            this->mordechaiTraget->isAlive = true;
            someOneBlockme++;
        }
        else{
            throw invalid_argument("you cant block this action");
        }
    }
    void Assassin::coup(Player &p){
        int turn = 0;
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
        turn++;
        p.isAlive = false;
        int coup = 0;
        this->mordechaiTraget = &p;
        if (this->money >= seven)
        {
            coup++;
            money -= seven;
            this->endMyTurn("coup");
        }
        else{
            coup++;
            money -= three;
            this->endMyTurn("kill");
        }
    }
        

}