//Nicholas Lumiere
//CS1300 UCB 
//Final Project - Move Class

#ifndef ITEM_H
#define ITEM_H
using namespace std;

class Item{
    private:
        string name;
        int id;
        int number;
        int cost;
    public:
        Item();
        Item(string, int id);
        Item(string, int id, int number);
        string getName();
        int getId();
        int getNumber();
        int getCost();

        void setName();
        void setId();
        void addNumber()
        void decrement();
        void setCost();
}
#endif