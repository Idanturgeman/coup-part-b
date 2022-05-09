#include "Player.hpp"
// #include "Game.hpp"
using namespace std;
namespace coup{
    class Assassin : public Player
    {
    private:
        Player *mordechaiTraget;
    public:
        Assassin(Game &game, string name);
        // int coinsduck();
        void block(Player &p);
        void coup(Player &p);
        void someOneBlockme();
        string role();
        ~Assassin();
    };
}