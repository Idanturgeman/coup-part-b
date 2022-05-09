#include "Game.hpp"
namespace coup{
    vector<string> Game::players()
    {
        vector<string> names;
        for(Player *p : playersList ){
            if (p->isAlive)
            {
                names.push_back(p->name);
            }  
        }
        return names;
    }
    string Game::turn()
    {
        if (this->playersList.empty())
        {
            throw runtime_error("their is no players in this game");
        }
        // i = i % playersList.size();
        return this->playersList[i]->name;
    }
    string Game::winner()
    {
        if (this->players().size() != 1)
        {
            throw runtime_error("their is no winners in this game");
        }
        if (this->gameStart == 0)
        {
            throw runtime_error("the game not start");
        }
        
        // i = i % playersList.size();
        return this->players().at(0);
    }
    void Game::addPlayer(Player *p){
        this->playersList.push_back(p);

        this->numOfPlayers++;
    }
    void Game::nextTurn(){
        const int six = 6;
        const int two = 2; 
        do
        {
           this->i = (this->i+1) % this->playersList.size();
        } while (!this->playersList.at(i)->isAlive);
        if (this->numOfPlayers < two || this->numOfPlayers > six )
        {
            throw runtime_error("too much players");
        }
        if (gameStart == 0)
        {
            gameStart = 1; 
        }
    }
    Game::Game(/* args */)
    {
        this->i = 0;
        this->numOfPlayers = 0;
        this->gameStart = 0;
    }

    Game::~Game()
    {
    }
}