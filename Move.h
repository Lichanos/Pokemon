//Nicholas Lumiere
//CS1300 UCB 
//Final Project - Move Class

#ifndef MOVE_H
#define MOVE_H
using namespace std;

class Move{
    private:
        string name;
        int type;
        int stat;
        double damage;
        const int maxPP;
        int PP;
    public:
        string getName();
        int getType();
        int getStat()
        double getDamage();
        int getMaxPP();
        int getPP();

        void setName(string);
        void setType(int);
        void setStat(int);
        void setDamage(double);
        void setMaxPP(int);
        void decrementPP();
        void resetPP();

}#endif