//Nicholas Lumiere
//CS1300 UCB 
//Final Project - Trainer Class

using namespace std;
#include <vector>
#include <string>
#include "Pokemon.h"
#include "Move.h"
#include "Item.h"
#include "Trainer.h"

string playerName;
vector<Pokemon> pokemon;
vector<Item> items;
vector<string> badges;
int steps;
double power;
int xPos;
int yPos;

Trainer::Trainer(){
    playerName = "";
    steps = 0;
    power = 0;
    xPos = 0;
    yPos = 0;
}

Trainer::Trainer(string name , int x, int y){
    playerName = name;
    steps = 0;
    power = 0;
    xPos = x;
    yPos = y;
}

string Trainer::getName(){
    return playerName;
}

vector<Pokemon> Trainer::getPokemon(){
    return pokemon;
}

Pokemon Trainer::getPokemonAt(int i){
    return pokemon.at(i);
}

vector<Item> Trainer::getItems(){
    return items;
}

Item Trainer::getItemAt(int i){
    return items.at(i);
}

vector<string> Trainer::getBadges(){
    return badges;
}

int Trainer:: getNumBadges(){
    int count = 0;
    for(string b : badges){
        count++;
    }
    return count;
}

int Trainer::getSteps(){
    return steps;
}

double Trainer::getPower(){
    return power;
}

int Trainer::getXPos(){
    return xPos;
}

int Trainer::getYPos(){
    return yPos;
}

void Trainer::setName(string name){
    playerName = name;
}

void Trainer::addPokemon(Pokemon p){
    pokemon.push_back(p);
}

int Trainer::addItem(Item item){
    items.push_back(item);
}

int Trainer::addBadge(string badgeName){
    badges.push_back(badgeName);
}

void Trainer::moveUp(){
    yPos--;
}

void Trainer::moveDown(){
    yPos++;
}

void Trainer::moveLeft(){
    xPos++;
}

void Trainer::moveRight(){
    xPos--;
}