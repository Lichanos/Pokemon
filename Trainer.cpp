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
#include <iostream>
#include "Tile.h"

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

int Trainer::addPokemon(Pokemon p){
    pokemon.push_back(p);
    for(Pokemon p1 : pokemon){
        if(p1.getName() == p.getName()){
            for(int ii = 0; ii < 6; ii++){
                if(p1.getIv(ii) != p.getIv(ii)){
                    return 0;
                }
            }
            return 1;
        }
    }
    return 0;
}

void Trainer::addItem(Item item){
    items.push_back(item);
}

void Trainer::addBadge(string badgeName){
    badges.push_back(badgeName);
}

void Trainer::setXPos(int x){
    xPos = x;
}

void Trainer::setYPos(int y){
    yPos = y;
}

int Trainer::moveUp(Tile t, int i){
    cout << i << endl;
    srand(i);
    if(t.getTerrain() == '.'){
        yPos--;
        return 1;
    }
    else if(t.getTerrain() == '#'){
        yPos--;
        double test = 8*((double)rand())/RAND_MAX;
        if(test > 5){
            return 2;
        }
        else{
            return 1;
        }
    }
    else if(t.getTerrain() == 'C'){
        yPos--;
        return 3;
    }
    else if(t.getTerrain() == 'G'){
        yPos--;
        if(t.getCompleted()){
            return 1;
        }
        else{
            return 4;
        }
    }
    else{
        return 0;
    }
    return 0;
}

int Trainer::moveDown(Tile t, int i){
    srand(i);
    if(t.getTerrain() == '.'){
        yPos++;
        return 1;
    }
    else if(t.getTerrain() == '#'){
        yPos++;
        double test = 8*((double)rand())/RAND_MAX;
        if(test > 5){
            return 2;
        }
        else{
            return 1;
        }
    }
    else if(t.getTerrain() == 'C'){
        yPos++;
        return 3;
    }
    else if(t.getTerrain() == 'G'){
        yPos++;
        if(t.getCompleted()){
            return 1;
        }
        else{
            return 4;
        }
    }
    else{
        return 0;
    }
    return 0;
}

int Trainer::moveLeft(Tile t, int i){
    srand(i);
    if(t.getTerrain() == '.'){
        xPos--;
        return 1;
    }
    else if(t.getTerrain() == '#'){
        xPos--;
        double test = 8*((double)rand())/RAND_MAX;
        //cout << test << endl;
        if(test > 5){
            return 2;
        }
        else{
            return 1;
        }
    }
    else if(t.getTerrain() == 'C'){
        xPos--;
        return 3;
    }
    else if(t.getTerrain() == 'G'){
        xPos--;
        if(t.getCompleted()){
            return 1;
        }
        else{
            return 4;
        }
    }
    else{
        return 0;
    }
    return 0;
}

int Trainer::moveRight(Tile t, int i){
    srand(i);
    if(t.getTerrain() == '.'){
        xPos++;
        return 1;
    }
    else if(t.getTerrain() == '#'){
        xPos++;
        double test = 8*((double)rand())/RAND_MAX;
        //cout << test << endl;
        if(test > 5){
            return 2;
        }
        else{
            return 1;
        }
    }
    else if(t.getTerrain() == 'C'){
        xPos++;
        return 3;
    }
    else if(t.getTerrain() == 'G'){
        xPos++;
        if(t.getCompleted()){
            return 1;
        }
        else{
            return 4;
        }
    }
    else{
        return 0;
    }
    return 0;
}

double Trainer::calcPowerLevel(){
    double total;
    if(pokemon.size() < 6){
        for(Pokemon p : pokemon){
            total += p.getLevel();
        }
        total/=pokemon.size();
    }
    else{
        for(int ii = 0; ii < 6; ii++){
            total += pokemon.at(ii).getLevel();
        }
        total/=6;
    }
    return total;
}