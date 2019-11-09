//Nicholas Lumiere
//CS1300 UCB 
//Final Project - Move Class

using namespace std;
#include <string>
#include <iostream>
#include <fstream>
#include "Move.h"

string name;
string type;
int stat;
double damage;
int maxPP;
int PP;

Move::Move(){
    name = "";
    type = "Normal";
    stat = 0;
    damage = 0;
    maxPP = 0;
    PP = maxPP;
}

Move::Move(string newName, string newType, int newStat, double newDamage, int newMaxPP){
    name = newName;
    type = newType;
    stat = newStat;
    damage = newDamage;
    maxPP = newMaxPP;
    PP = maxPP;
}

string Move::getName(){
    return name;
}

string Move::getType(){
    return type;
}

int Move::getStat(){
    return stat;
}

double Move::getDamage(){
    return damage;
}

int Move::getMaxPP(){
    return maxPP;
}

int Move::getPP(){
    return PP;
}

void Move::setName(string newName){
    name = newName;
}

void Move::setType(string newType){
    type = newType;
}

void Move::setStat(int newStat){
    stat = newStat;
}

void Move::setDamage(double newDamage){
    damage = newDamage;
}

void Move::setMaxPP(int newMaxPP){
    maxPP = newMaxPP;
}

void Move::decrementPP(){
    PP--;
}

void Move::resetPP(){
    PP = maxPP;
}

