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
        int xCoord;
        int yCoord;
        char terrain;
        bool completed;
        bool isItPokemon;
        bool isItItem;
    public:
        Tile();
        Tile(int, int, char);
        int getXCoord();
        int getYCoord();
        char getTerrain();
        bool getCompleted();
        bool isPokemon();
        bool isItem();

        void setXCoord(int);
        void setYCoord(int);
        void setTerrain(char);
        void setCompleted();
        void setIsPokemon(bool);
        void setIsItem(bool);
};
#endif