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
        //x coordinate
        int xCoord;
        //y cooridinate
        int yCoord;
        //a character which represents what type of terrain the tile is
        char terrain;
        //Signifies if the tile has been completed in the case of a gym
        bool completed;
        //*subject to change* boolean which represents whether or not there's a pokemon on the tile
        bool isItPokemon;
        //*subject to change* boolean which represents whether or not there's an item on the tile
        bool isItItem;
    public:
        //Default constructor for tile
        Tile();
        //Parameterized constructor for tile
        Tile(int, int, char);
        //Returns x coordinate
        int getXCoord();
        //Returns y coordinate
        int getYCoord();
        //Returns the terrain type as a character
        char getTerrain();
        //Returns a boolean for if the player has completed the tile
        bool getCompleted();
        //Returns whether or not there's a pokemon on the tile
        bool isPokemon();
        //Returns whether or not there's an item on the tile
        bool isItem();

        //Sets the x coordinate
        void setXCoord(int);
        //sets the y coordinate
        void setYCoord(int);
        //Sets the terrain type
        void setTerrain(char);
        //Sets the tile's state of completion
        void setCompleted();
        //Sets whether or not there's a pokemon on the tile
        void setIsPokemon(bool);
        //Sets whether or not there's an item on the tile
        void setIsItem(bool);
};
#endif