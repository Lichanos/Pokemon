//Nicholas Lumiere
//CS1300 UCB 
//Final Project - Move Class

using namespace std;
#include <string>
#include <iostream>
#include <fstream>
#include "Move.h"

string moveName;
string moveType;
int stat;
double damage;
int maxPP;
int PP;

Move::Move(){
    moveName = "";
    moveType = "Normal";
    stat = 0;
    damage = 0;
    maxPP = 0;
    PP = maxPP;
}

Move::Move(string newName, string newType, int newStat, double newDamage, int newMaxPP){
    moveName = newName;
    moveType = newType;
    stat = newStat;
    damage = newDamage;
    maxPP = newMaxPP;
    PP = maxPP;
}

string Move::getMoveName(){
    return moveName;
}

string Move::getMoveType(){
    return moveType;
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

void Move::setMoveName(string newName){
    moveName = newName;
}

void Move::setMoveType(string newType){
    moveType = newType;
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

