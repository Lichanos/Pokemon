//Nicholas Lumiere
//CS1300 UCB 
//Final Project - Move Class

#ifndef MOVE_H
#define MOVE_H
using namespace std;
#include <string>
#include <fstream>

class Move{
    private:
        string name;
        string type;
        int stat;
        double damage;
        int maxPP;
        int PP;
    public:
        Move();
        Move(string, string, int, double, int);

        string getName();
        string getType();
        int getStat();
        double getDamage();
        int getMaxPP();
        int getPP();

        void setName(string);
        void setType(string);
        void setStat(int);
        void setDamage(double);
        void setMaxPP(int);
        void decrementPP();
        void resetPP();

};
#endif