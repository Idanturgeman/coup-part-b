#include "Player.hpp"

using namespace std;
namespace coup{
    class Ambassador : public Player
    {
    public:
        Ambassador(Game &game, string name);
        string role();
        void transfer(Player &p1, Player &p2);
        static void block(Player &p);
        ~Ambassador();
    };
}