#include "Player.hpp"
namespace coup{
    class Contessa : public Player
    {
    public:
        Contessa(Game &game, string name);
         ~Contessa();
        string role();
        static void block(Player &p);

    };
}