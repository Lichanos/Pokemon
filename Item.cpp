//Nicholas Lumiere
//CS1300 UCB 
//Final Project - Move Class

#include <string>
#include "Item.h"
using namespace std;

string itemName;
int number;
int cost;

Item::Item(){
    itemName = "Pokeball";
    number = 1;
    cost = 0;
}

Item::Item(string name){
    itemName = name;
    number = 1;
    cost = 0;
}

Item::Item(string name, int num){
    itemName = name;
    number = num;
    cost = 0;
}

string Item::getItemName(){
    return itemName;
}

int Item::getNumber(){
    return number;
}

int Item::getCost(){
    return cost;
}

void Item::setItemName(string name){
    itemName = itemName;
}

void Item::addNumber(int num){
    number += num;
}

void Item::decrement(){
    number--;
}

void Item::setCost(int cost1){
    cost = cost1;
}
