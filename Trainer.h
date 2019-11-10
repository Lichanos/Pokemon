//Nicholas Lumiere
//CS1300 UCB 
//Final Project - Move Class

#ifndef TRAINER_H
#define TRAINER_H
using namespace std;
#include <vector>
#include <string>
#include "Pokemon.h"
#include "Move.h"
#include "Item.h"

class Trainer{
    private:
        string playerName;
        vector<Pokemon> pokemon;
        vector<Item> items;
        vector<string> badges;
        int steps;
        double power;
        int xPos;
        int yPos;
    public:
        Trainer();
        Trainer(string, int, int);

        string getName();
        vector<Pokemon> getPokemon();
        Pokemon getPokemonAt(int i);
        vector<Item> getItems();
        Item getItemAt(int i);
        vector<string> getBadges();
        int getNumBadges();
        int getSteps();
        double getPower();
        int getXPos();
        int getYPos();

        void setName(string);
        void addPokemon(Pokemon);
        int addItem(Item);
        int addBadge(string);
        void moveUp();
        void moveDown();
        void moveLeft();
        void moveRight();
};
#endif