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
        //Pokemon's name
        string name;
        //Pokemon's nickname
        string nickname;
        //id of the pokemon 1-151
        int id;
        //Level of the pokemon
        int level;
        //xp of the pokemon
        int xp;

        //Maximum stats of the pokemon
        double maxStat[6];
        //Temp stats
        double tempStat[6];
        //Affinity for each stat
        double statAff[6];
        //IVs for stats
        int iv[6];

        int numMoves;

    public:
        //Import array which the file reads into
        string imports[152][9];
        //Affinities table from which to calculate stats upon level up
        double affinities[152][6];
        //Array of pokemon types
        string type[2] = {};
        //Array of moves each pokemon can use
        Move moves[4] = {};

        //Default constructor for pokemon
        Pokemon();
        //Parameterized constructor for pokemon
        Pokemon(int, int);
        //returns name of the pokemon
        string getName();
        //Returns id of the pokemon
        int getId();
        //Returns nickname of the pokemon
        string getNickname();
        //Returns level of the pokemon
        int getLevel();
        //Returns xp of the pokemon
        int getXp();
        //Returns the max stat of the pokemon at a certain index (corresponding stat)
        double getMaxStat(int);
        //Returns the current stat of the pokemon at a certain index
        double getStat(int);
        //Returns the affinity of a pokemon at a certain index
        double getAffinity(int);
        //Gets a randomly generated IV between 1 and 36
        int getIv();
        //Returns the iv of the indexed stat
        int getIv(int);

        //Sets the nickname of the pokemon
        void setNickname(string);
        //Sets the level of the pokemon
        void setLevel(int);
        //Sets xp
        void setXp(int);
        //Changes stat of a certain index by a certain amount
        void modStat(int, double);
        //Sets a stat
        void setStat(int, double);

        //Gets a move by an index
        Move getMove(int);
        //Adds a move at a certain index
        void addMove(int, Move);
        //Adds a move to replace an existing move
        int replaceMove(string, Move);

        //Pokemon levels up, stats increase
        void levelUp();
        //Adds xp
        void addXp(int n);

        //prints moves
        void printMoves();

        //prints stats
        void printStats();

        int getNumMoves();
};
#endif
