//Nicholas Lumiere
//CS1300 UCB 
//Final Project - Map Class

#include "Tile.h"
#include "Pokemon.h"
#include "Map.h"
#include <vector>
#include <iostream>
#include <stdio.h>
#include <stdlib.h> 
#include <fstream>
using namespace std;

int maxX;
int maxY;
int seed;
Tile tiles[60][90];
vector<Pokemon> mapPokemon;

Map::Map(){
    seed = 0;
    maxX = 90;
    maxY = 60;
    generateMap(maxX, maxY, seed);
}

Map::Map(int size, int newSeed){
    seed = newSeed;
    maxX = 90;
    maxY = 30*size;
    generateMap(maxX, maxY, seed);
}

void Map::generateMap(int maxX, int maxY, int seed){

    char baseMap[maxY][maxX];
    char chunks[maxY/15][maxX/30][15][30];
    ifstream reader;
    reader.open("map.txt");
    if(!reader.is_open()){
        cout << "Error opening file" << endl;
    }
    else{
        string line  = "";
        for(int ii = 0; ii < maxY; ii++){
            getline(reader, line);
            for(int jj = 0; jj < maxX; jj++){
                if(line != ""){
                    baseMap[ii][jj] = line[jj];
                }
            }
        }
    }
    reader.close();

    for(int ii = 0; ii < maxY/15; ii++){
        for(int jj = 0; jj < maxX/30; jj++){
            for(int kk = ii*15; kk<ii*15+15; kk++){
                for(int ll = jj*30; ll < jj*30+30; ll++){
                    chunks[ii][jj][(ii*15+14)-kk][(jj*30+29)-ll] = baseMap[kk][ll];
                }
            }
        }
    }
    srand(seed);
    int r1;
    int r2;
    for(int i = 0; i < maxY/15; i++){
        for(int j = 0; j < maxX/30; j++){
            r1 = (int)((maxY/15)*(((double)rand())/RAND_MAX));
            r2 = (int)((maxX/30)*(((double)rand())/RAND_MAX));
            for(int ii = 0; ii < 15; ii++){
                for(int jj = 0; jj < 30; jj++){
                    //cout << (int)(6*(((double)rand())/RAND_MAX)) << endl;
                    baseMap[i*15+ii][j*30+jj] = chunks[r1][r2][ii][jj];
                    //cout << chunks[r1][r2][ii][jj];
                }
                //cout << endl;
            }
            //cout << endl;
        }
    }

    char terrain;
    for(int ii = 0; ii < maxY; ii++){
        for(int jj = 0; jj < maxX; jj++){
            terrain = baseMap[ii][jj];
            tiles[ii][jj] = Tile(ii, jj, terrain);
        }
    }
}

int Map::getMaxX(){
    return maxX;
}

int Map::getMaxY(){
    return maxY;
}

void Map::printMap(){
    cout << endl;
    for(int ii = 0; ii < maxY; ii++){
        for(int jj = 0; jj < maxX; jj++){
            cout << tiles[ii][jj].getTerrain();
        }
        cout << endl;
    }
}
