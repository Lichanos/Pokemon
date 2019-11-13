//Nicholas Lumiere
//CS1300 UCB 
//Final Project - Map Class

#include "Tile.h"
#include "Pokemon.h"
#include <vector>
#include <stdio.h>
#include <stdlib.h> 
using namespace std;

#ifndef MAP_H
#define MAP_H
class Map{
    private:
        int maxX;
        int maxY;
        int seed;
    public:
        Tile tiles[100][100];
        vector<Pokemon> mapPokemon;

        Map();
        Map(int, int);
        void generateMap(int, int, int);
        int getMaxX();
        int getMaxY();
        void printMap();
};
#endif