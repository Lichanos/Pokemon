//Nicholas Lumiere
//CS1300 UCB 
//Final Project - Map Class

#include "Tile.h"
#include "Pokemon.h"
#include "Map.h"
#include <vector>
using namespace std;

int maxX;
int maxY;
vector<Tile> tiles;
vector<Pokemon> pokemon;

Map::Map(int maxx, int maxy){
    maxX = maxx;
    maxY = maxy;
}
int getMaxX(){
    return maxX;
}
int getMaxY(){
    return maxY;
}
