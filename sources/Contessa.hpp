#include "Player.hpp"
// using namespace std;
namespace coup{
    class Contessa : public Player
    {
    private:

    public:
        Contessa(Game &game, string name);
        static void block(Player &p);
        string role();
        ~Contessa();
    };
}