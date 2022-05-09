#include "Duke.hpp"
namespace coup
{
    static int numOfDuks = 0;
    Duke::Duke(Game &game, string name) : Player(game, move(name))
    {
        numOfDuks++;
    }

    Duke::~Duke()
    {
        numOfDuks--;
    }
    void Duke::block(Player &p){
        static int numOfBlock = 0;
        int f = p.lastAction.compare("foreign_aid");
        if (f == 0){
            numOfBlock++;
            p.someOneBlockme();
        }
        else{
            throw invalid_argument("you cantt block this action");  
        }
    }
    void Duke::tax(){
        static int numOfTax = 0;
        isMyTurn();
        this->money += 3;
        numOfTax++;
        this->endMyTurn("tax");
    }
    string Duke::role(){
        static int numOfRole = 0;
        return "Duke";
        numOfRole++;
    }

}