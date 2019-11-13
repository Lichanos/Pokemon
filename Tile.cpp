//Nicholas Lumiere
//CS1300 UCB 
//Final Project - Tile Class

#include "Tile.h"
#include "Pokemon.h"
#include "Item.h"
using namespace std;
#include <iostream>

int xCoord;
int yCoord;
char terrain;
bool completed;
bool isItPokemon;
bool isItItem;

Tile::Tile(){
    xCoord = 0;
    yCoord = 0;
    terrain = 'C';
    completed = false;
}

Tile::Tile(int newX, int newY, char newTerrain){
    xCoord = newX;
    yCoord = newY;
    terrain = newTerrain;
    completed = false;
}

int Tile::getXCoord(){
    return xCoord;
}

int Tile::getYCoord(){
    return yCoord;
}

char Tile::getTerrain(){
    return terrain;
}

bool Tile::getCompleted(){
    return completed;
}

bool Tile::isPokemon(){
    return isItPokemon;
}

bool Tile::isItem(){
    return isItItem;
}

void Tile::setXCoord(int newX){
    xCoord = newX;
}

void Tile::setYCoord(int newY){
    yCoord = newY;
}

void Tile::setTerrain(char terrainType){
    terrain = terrainType;
}

void Tile::setCompleted(){
    completed = true;
}

void setIsPokemon(bool pokemonUpdate){
    isItPokemon = pokemonUpdate;
}

void setIsItem(bool itemUpdate){
    isItItem = itemUpdate;
}