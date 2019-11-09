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

        double maxStat[6];
        double tempStat[6];
        double statAff[6];
        int iv[6];

        string imports[152][9];
        double affinities[152][6];
    public:
        string type[2] = {};
        Move moves[4] = {};

        int getIv();
        //int split(string, char, string pieces[], int);
        Pokemon();
        Pokemon(int, int);
        string getName();
        int getId();
        string getNickname();
        int getLevel();
        int getXp();
        double getMaxStat(int);
        double getStat(int);
        double getAffinity(int);
        int getIv(int);

        void setNickname(string);
        void setLevel(int);
        void setXp(int);
        void modStat(int, double);

        Move getMove(int);
        void addMove(int, Move);
        int replaceMove(string, Move);

        void levelUp();
        void addXp(int n);
};
#endif
