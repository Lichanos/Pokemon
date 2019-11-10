//Nicholas Lumiere
//CS1300 UCB 
//Final Project - Move Class

#include <string>
#include "Item.h"
using namespace std;

string itemName;
int itemId;
int number;
int cost;

Item::Item(){
    itemName = "Pokeball";
    itemId = 0;
    number = 1;
    cost = 0;
}

Item::Item(string name, int ID){
    itemName = name;
    itemId = ID;
    number = 1;
    cost = 0;
}

Item::Item(string name, int ID, int num){
    itemName = name;
    itemId = ID;
    number = num;
    cost = 0;
}

string Item::getItemName(){
    return itemName;
}

int Item::getItemId(){
    return itemId;
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

void Item::setItemId(int ID){
    itemId = ID;
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
