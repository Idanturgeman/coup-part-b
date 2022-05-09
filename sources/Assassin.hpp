#include "Player.hpp"
using namespace std;
namespace coup{
    class Assassin : public Player
    {
    
    private:
        Player *mordechaiTraget;
    
    
    public:
        Assassin(Game &game, string name);
        void coup(Player &p);
        void block(Player &p);
        string role();
        void someOneBlockme();
        ~Assassin();
    
    
    
    
    
    };











}