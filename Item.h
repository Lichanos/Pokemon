//Nicholas Lumiere
//CS1300 UCB 
//Final Project - Move Class

#ifndef ITEM_H
#define ITEM_H
#include <string>
using namespace std;

class Item{
    private:
        string itemName;
        int itemId;
        int number;
        int cost;
    public:
        Item();
        Item(string, int id);
        Item(string, int id, int number);
        string getItemName();
        int getItemId();
        int getNumber();
        int getCost();

        void setItemName(string);
        void setItemId(int);
        void addNumber(int);
        void decrement();
        void setCost(int);
};
#endif