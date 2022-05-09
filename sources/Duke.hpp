#include "Player.hpp"
using namespace std;
namespace coup{
    class Duke : public Player
    {
    public:
        Duke(Game &game, string name);
        ~Duke();
        void tax();
        string role();
        static void block(Player &p);
    };
}