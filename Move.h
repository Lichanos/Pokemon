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
        //Name of themove
        string moveName;
        //Type of the move
        string moveType;
        //Stat which the move affects
        int stat;
        //Damage of the move
        double damage;
        //Max PP of move
        int maxPP;
        //Current PP of the move
        int PP;
    public:
        //Default constructor for move
        Move();
        //Parameterized constructor for move
        Move(string, string, int, double, int);

        //Returns the move name
        string getMoveName();
        //Returns the move type
        string getMoveType();
        //Returns the stat which the move affects
        int getStat();
        //Returns the damage of the move
        double getDamage();
        //Returns the max PP of the move
        int getMaxPP();
        //Returns the current PP of the move
        int getPP();

        //Sets the name of the move
        void setMoveName(string);
        //Sets the type of the move
        void setMoveType(string);
        //Sets the stat which the move affects
        void setStat(int);
        //Sets the damage of the move
        void setDamage(double);
        //Sets the maxPP of the move
        void setMaxPP(int);
        //Subtracts 1 from the current PP
        void decrementPP();
        //Sets the PP back to the maximum
        void resetPP();

};
#endif