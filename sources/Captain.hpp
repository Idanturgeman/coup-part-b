#include "Player.hpp"

using namespace std;
namespace coup{
    class Captain : public Player
    {
    
    public:
        Captain(Game &game, string name);
        ~Captain();
        void steal(Player &p);
        void someOneBlockme();
        static void block(Player &p);
        string role();
        
    private:
    
    Player *pFrom;


    };


}