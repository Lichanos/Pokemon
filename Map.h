//Nicholas Lumiere
//CS1300 UCB 
//Final Project - Map Class

#include "Tile.h"
#include "Pokemon.h"
#include <vector>
#include <stdio.h>
#include <stdlib.h> 
#include "Trainer.h"
using namespace std;

#ifndef MAP_H
#define MAP_H
class Map{
    private:
        //max size of the map in the x direction
        int maxX;
        //max size of the map in the y direction
        int maxY;
        //seed of the map
        int seed;
    public:
        //Array of tiles for the map
        Tile tiles[60][90];
        
        //*subect to change* Vector of pokemon that appear on the map
        vector<Pokemon> mapPokemon;

        //Default constructor for the map
        Map();
        //Parameterized constructor for the map
        Map(int, int);
        /**
         * Reads in from a file
         * Saves map to 2d array of chars
         * Segments map into chunks
         * Psedo-randomly distributes chunks
         * Creates tiles based off the modified array of chars
         */
        void generateMap(int, int, int);
        //Returns max x value
        int getMaxX();
        //Returns max y value
        int getMaxY();
        //Iterates through all tiles of the map, prints the characters
        void printMap();

        //Prints a small subsection of the map which the user can see
        void printMapAroundPlayer(int, int, vector<Trainer>);
};
#endif