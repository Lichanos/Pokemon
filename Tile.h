//Nicholas Lumiere
//CS1300 UCB 
//Final Project - Tile Class

using namespace std;
#include "Pokemon.h"
#include "Item.h"
#ifndef TILE_H
#define TILE_H
class Tile{
    private:
        int xPos;
        int yPos;
        char terrain;
        bool completed;
        bool isPokemon;
        bool isItem;
        Pokemon p;
        Item i;
    public:
        Tile(int, int, char);
        int getXPos();
        int getYPos();
        char getTerrain();
        bool getCompleted();
        bool isPokemon();
        bool isItem();
        Pokemon getPokemon();
        Item getItem();

        void setXPos(int);
        void setYPos(int);
        void setTerrain(char);
        void setCompleted();
        void setIsPokemon(bool);
        void setIsItem(bool);
        void setPokemon(Pokemon);
        void setItem(Item);
};
#endif