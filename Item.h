//Nicholas Lumiere
//CS1300 UCB 
//Final Project - Move Class

#ifndef ITEM_H
#define ITEM_H
#include <string>
using namespace std;

class Item{
    private:
        //Name of the item
        string itemName;
        //Number of the item
        int number;
        //Cost of the item
        int cost;
    public:
        //Default constructor for item, creates a pokeball
        Item();
        //Parameterized constructor for item, creates with a given itemName and id
        Item(string);
        //Additional parameterized constructor for item, also creates with a given number
        Item(string, int number);
        //Returns the name of the item
        string getItemName();
        //Returns the id of the item
        int getNumber();
        //Returns the cost of the item
        int getCost();

        //Sets the name of the item to a given parameter
        void setItemName(string);
        //Sets the id of the item to a given parameter
        void addNumber(int);
        //Subtracts 1 from the item
        void decrement();
        //Sets the cost of the item
        void setCost(int);
};
#endif