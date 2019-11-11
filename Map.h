//Nicholas Lumiere
//CS1300 UCB 
//Final Project - Map Class

#include "Tile.h"
#include "Pokemon.h"
#include <vector>
using namespace std;

#ifndef MAP_H
#define MAP_H
class Map{
    private:
        int maxX;
        int maxY;
    public:
        vector<Tile> tiles;
        vector<Pokemon> pokemon;
        Map(int, int);
        int getMaxX();
        int getMaxY();
};
#endif