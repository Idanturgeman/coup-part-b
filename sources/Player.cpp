#include "Player.hpp"
#include "Game.hpp"
// #include <string>
// #include <stdexcept>
using namespace std;

namespace coup
{

    void Player::income()
    {
        isMyTurn();
        this->money++;
        this->endMyTurn("income");
    }
    void Player::foreign_aid()
    {
        isMyTurn();
        const int ten = 10;
        if (this->money > ten)
        {
            throw runtime_error("you have too much coins");
        }
        this->money += 2;
        
        this->endMyTurn("foreign_aid");
    }
    void Player::coup(Player &p){
        isMyTurn();
        const int seven = 7;
        if (!p.isAlive)
        {
            throw runtime_error("this player is dead");
        }
        
        if (this->money < seven)
        {
            throw runtime_error("this Player havn't engoth money");
        }
        p.isAlive = false;
        money -= seven;
        this->endMyTurn("coup");

    }
    string Player::role()
    {
        return "virtual";
    }
    int Player::coins() const{
        return this->money;
    }

    void Player::isMyTurn(){
        // cout << game->turn() << "turn now\n";
        int x = this->name.compare(game->turn());
        if (x != 0)
        {
            throw runtime_error(this->name + " is not your turn!");
        }
        
    }
    void Player::someOneBlockme(){
        int f = this->lastAction.compare("foreign_aid");
        if (f == 0)
        {
            this->money -= 2;
        }
        else{
            throw runtime_error("you can not block this");
        }
    }
    void Player::endMyTurn(string last){
        this->lastAction = move(last);
        this->game->nextTurn();
    }
    Player::Player(Game &game, string name)
    {
        // game.addPlayer(this);
        const int six = 6;
        this->name = move(name);
        this->game = &game;
        if (this->game->gameStart == 1)
        {
            throw runtime_error("the game already start");
        }
        if (this->game->numOfPlayers == six)
        {
            throw runtime_error("too many players");
        }
        this->isAlive = true;
        this->game->addPlayer(this);
        this->money = 0;
    }
    Player::~Player()
    {
    }
}