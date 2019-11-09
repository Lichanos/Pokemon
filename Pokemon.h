//Nicholas Lumiere
//CS1300 UCB 
//Final Project - Pokemon Class

#include <string>
#include <fstream>
#include <math.h>
#include "Move.h"
#include <time.h>
#include <stdio.h> 
#include <stdlib.h> 
using namespace std;

#ifndef POKEMON_H
#define POKEMON_H
class Pokemon{
    private:
        string name;
        string nickname;
        int id;
        int level;
        int xp;

        int maxHp;
        int maxAtt;
        int maxDef;
        int maxSpAtt;
        int maxSpDef;
        int maxSpd;
        int hpIv;
        int attIv;
        int defIv;
        int spAttIv;
        int spDefIv;
        int spdIv;
        double hpAffinity;
        double attAffinity;
        double defAffinity;
        double spAttAffinity;
        double spDefAffinity;
        double spdAffinity;
        double tempHp;
        double tempAtt;
        double tempDef;
        double tempSpAtt;
        double tempSpDef;
        double tempSpd;

        string imports[152][9];
        double affinities[152][6];
    public:
        string type[2] = {};
        //Move moves[4];

        int getIv();
        //int split(string, char, string pieces[], int);
        Pokemon();
        Pokemon(int, int);
        string getName();
        int getId();
        string getNickname();
        int getLevel();
        int getXp();
        double getMaxHP();
        double getmaxAtt();
        double getMaxDef();
        double getMaxSpAtt();
        double getMaxSpDef();
        double getMaxSpd();
        double getTempHp();
        double getTempAtt();
        double getTempDef();
        double getTempSpAtt();
        double getTempSpDef();
        double getTempSpd();

        int getHpIv();
        int getAttIv();
        int getDefIv();
        int getSpAttIv();
        int getSpDefIv();
        int getSpdIv();
        double getHpAffinity();
        double getAttAffinity();
        double getDefAffinity();
        double getSpAttAffinity();
        double getSpDefAffinity();
        double getSpdAffinity();

        void setNickname(string);
        void setLevel(int);
        void setXp(int);
        void modHp(double);
        void modAtt(double);
        void modDef(double);
        void modSpAtt(double);
        void modSpDef(double);
        void modSpd(double);

        void levelUp();
        void addXp(int n);
};
#endif
