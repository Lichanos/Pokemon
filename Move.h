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
        string moveName;
        string moveType;
        int stat;
        double damage;
        int maxPP;
        int PP;
    public:
        Move();
        Move(string, string, int, double, int);

        string getMoveName();
        string getMoveType();
        int getStat();
        double getDamage();
        int getMaxPP();
        int getPP();

        void setMoveName(string);
        void setMoveType(string);
        void setStat(int);
        void setDamage(double);
        void setMaxPP(int);
        void decrementPP();
        void resetPP();

};
#endif