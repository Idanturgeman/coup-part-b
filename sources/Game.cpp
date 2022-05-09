#include "Game.hpp"
namespace coup{
    static int _players = 0;
    vector<string> Game::players()
    {
        int i = 0;
        vector<string> names;
        for(Player *p : playersList ){
            if (p->isAlive)
            {
                _players++;
                names.push_back(p->name);
            }  
        }
        return names;
    }
    static int _turn = 0;
    string Game::turn()
    {
        
        if (this->playersList.empty())
        {
            throw runtime_error("their is no players in this game");
        }
        _turn++;
        return this->playersList[i]->name;
    }
    string Game::winner()
    {
        static int _winner = 0;
        if (this->players().size() != 1)
        {
            throw runtime_error("their is no winners in this game");
        }
        if (this->gameStart == 0)
        {
            throw runtime_error("the game not start");
        }
        
        _winner++;
        return this->players().at(0);
    }
    void Game::addPlayer(Player *p){
        _players++;
        this->playersList.push_back(p);

        this->numOfPlayers++;
    }
    void Game::nextTurn(){
        const int seven = 7;
        const int two = 2; 
        const int six = 6;
        const int one = 1;
        int ans = 0;
        int temp = 0;
        
        do
        {
            _turn++;
           this->i = (this->i+1) % this->playersList.size();
        } while (!this->playersList.at(i)->isAlive);
        _turn++;
        if (this->numOfPlayers < two || this->numOfPlayers > six )
        {
            throw runtime_error("too much players");
        }
        ans++;
        if (gameStart == 0)
        {
            temp++;
            gameStart = 1; 
        }
    }
    static int game = 0;
    Game::Game()
    {
        game++;
        this->i = 0;
        this->gameStart = 0;
        this->numOfPlayers = 0;
    }

    Game::~Game()
    {
        game--;
    }
}