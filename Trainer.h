//Nicholas Lumiere
//CS1300 UCB 
//Final Project - Move Class

#ifndef TRAINER_H
#define TRAINER_H
using namespace std;
#include <vector>

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
        string getName();
        vector<Pokemon> getPokemon();
        vector<Item> getItems();
        int getSteps();
        double getPower();
        int getXPos();
        int getYPos();

        void setName(string);
        void addPokemon(Pokemon);
        int releasePokemon(string);
        int addItem(Item);
        int addBadge(string);
        void moveUp();
        void moveDown();
        void moveLeft();
        void moveRight();
}
#endif