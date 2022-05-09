#include "Player.hpp"
#include "Game.hpp"

using namespace std;

namespace coup
{
    static int numOfPlayer = 0;
    void Player::income()
    {
        static int _income = 0;
        isMyTurn();
        this->money++;
        this->endMyTurn("income");
        _income++;
    }
    void Player::foreign_aid()
    {
        static int _foreign_aid = 0;
        isMyTurn();
        const int ten = 10;
        if (this->money > ten)
        {
            throw runtime_error("you have too much coins");
        }
        _foreign_aid++;
        this->money += 2;
        
        this->endMyTurn("foreign_aid");
    }
    void Player::coup(Player &p){
        isMyTurn();
        static int _coup = 0;
        const int seven = 7;
        if (!p.isAlive)
        {
            throw runtime_error("this player is dead");
        }
        
        if (this->money < seven)
        {
            throw runtime_error("this Player havn't engoth money");
        }
        _coup++;
        p.isAlive = false;
        money -= seven;
        this->endMyTurn("coup");

    }
    string Player::role()
    {
        static int _role = 0;
        return "virtual";
        _role++;
    }
    int Player::coins() const{
        static int _coins = 0;
        return this->money;
        _coins++;
    }
    static int turn = 0;
    void Player::isMyTurn(){
        int x = this->name.compare(game->turn());
        turn++;
        if (x != 0)
        {
            throw runtime_error(this->name + " is not your turn!");
        }
        
    }
    void Player::someOneBlockme(){
        static int _block = 0;
        int f = this->lastAction.compare("foreign_aid");
        if (f == 0)
        {
            _block++;
            this->money -= 2;
        }
        else{
            throw runtime_error("you can not block this");
        }
    }
    void Player::endMyTurn(string last){
        turn--;
        this->lastAction = move(last);
        this->game->nextTurn();
    }
    Player::Player(Game &game, string name)
    {
        numOfPlayer++;
        const int six = 6;
        int ans = 0;
        this->name = move(name);
        this->game = &game;
        int temp = 0;
        if (this->game->gameStart == 1)
        {
            throw runtime_error("the game already start");
        }
        if (this->game->numOfPlayers == six)
        {
            throw runtime_error("too many players");
        }
        ans++;
        this->isAlive = true;
        this->game->addPlayer(this);
        this->money = 0;
        temp--;

    }
    Player::~Player()
    {
        numOfPlayer--;
    }
}