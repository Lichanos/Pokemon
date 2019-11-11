//Nicholas Lumiere
//CS1300 UCB 
//Final Project - Tile Class

#include "Tile.h"
#include "Pokemon.h"
#include "Item.h"
using namespace std;
#include <iostream>

int xPos;
int yPos;
char terrain;
bool completed;
bool isPokemon;
bool isItem;
Pokemon p;
Item i;

Tile::Tile(int newX, int newY, char terrainType){
    xPos = newX;
    yPos = newY;
    terrain = terrainType;
}

int Tile::getXPos(){
    return xPos;
}

int Tile::getYPos(){
    return yPos;
}

char Tile::getTerrain(){
    return terrain;
}

bool Tile::getCompleted(){
    return completed;
}

bool Tile::isPokemon(){
    return isPokemon;
}

bool Tile::isItem(){
    return isItem;
}

Pokemon Tile::getPokemon(){
    return p;
}

Item Tile::getItem(){
    return i;
}

void Tile::setXPos(int newX){
    xPos = newX;
}

void Tile::setYPos(int newY){
    yPos = newY;
}

void Tile::setTerrain(char terrainType){
    terrain = terrainType;
}

void Tile::setCompleted(){
    completed = true;
}

void setIsPokemon(bool pokemonUpdate){
    isPokemon = pokemonUpdate;
}

void setIsItem(bool itemUpdate){
    isItem = itemUpdate;
}

void setPokemon(Pokemon newPokemon){
    p = newPokemon;
}

void setItem(Item newItem){
    i = newItem;
}