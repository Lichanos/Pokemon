//Nicholas Lumiere
//CS1300 UCB 
//Final Project - Pokemon Class

#include "Pokemon.h"
#include <string>
#include <fstream>
#include <math.h>
#include <iostream>
#include <random>
#include <time.h>
#include <chrono>
#include <stdio.h> 
#include <stdlib.h> 

using namespace std;

string name;
int id;
string nickname;
int level;
int xp;
string type[2] = {};
Move moves[4] = {};

double maxStat[6];
double tempStat[6];
double statAff[6];
int iv[6];

string imports[152][9] = {""};
double affinities[152][6] = {0};

int Pokemon::getIv(){
    unsigned seed = chrono::system_clock::now().time_since_epoch().count();
    default_random_engine generator (seed);
    int number = -1;
    normal_distribution<double> distribution (18,9);
    while(number > 36.99 || number < 0){
        number = (int)distribution(generator);
    }
    return (int)number;
}

/**
 * Function (copied from hmwk4):
 * Takes in four paramters: The string, the delimiter, the array of pieces, and length
 * Checks to make sure the length of the array is greater than 0
 * Initialize variables
 * Run a for loop to traverse the string
 *      Check to see if the current character is equal to the delimiter
 *          If the string-in-progress is not empty, set that piece equal to the next item in the array
 *          Increase the count of how many pieces there are
 *          Set the string-in-progress back to empty
 * After the for loop, repeat the process above to account for the final piece
 * Return the number of pieces
 */
int split(string initial, char delimiter, string pieces[], int length){
    //Array length check
    if(length > 0){
        string build = "";
        int num = 0;
        for(int ii = 0; ii < initial.length(); ii++){
            //Checks to see if the current character is equal to the delimiter, but makes sure the string build is not empty
            if(initial[ii] == delimiter){
                if(build != ""){
                    //Adds the string to the array, increases the count, sets the string to empty
                    pieces[num] = build;
                    num++;
                    build = "";
                }
            }
            //Adds to the string one character at a time
            else{
                build += initial[ii];
            }
        }
        //Adds the final string piece to the array, increases the count by 1, as long as build is not empty
        if(build != ""){
            pieces[num] = build;
            num++;
        }
        return num;
    }
    else{
        return -1;
    }
}

/**
 * Reads in from a file sets the imports array to be everything in the file
 * Next reads the affinity values from the middle of the imports array to the affinities array
 * Returns status of function call
 */
int initialize(string imports[152][9], double affinities[152][6]){
    //imports[0][] = {"name","hp","att","def","spAtt","spDef","spd","type1","type2"};
    ifstream reader;
    reader.open("pokemon.txt");
    if(reader.is_open()){
        string line = "";
        for(int ii = 1; ii < 152; ii++){
            getline(reader, line);
            string pieces[9] = {};
            if(line != ""){
                split(line,',',pieces,9);
                for(int jj = 0; jj < 9; jj++){
                    //cout << pieces[jj] << endl;
                    imports[ii][jj] = pieces[jj];
                }
            }
        }
    }
    reader.close();
    imports[1][0] = "Bulbasaur";
    for(int ii = 1; ii < 152; ii++){
        //cout << ii << ": ";
        for(int jj = 0; jj < 6; jj++){
            affinities[ii][jj] = stod(imports[ii][jj + 1]);
            //cout << affinities[ii][jj] << ", ";
        }
        //cout << endl;
    }

    if(affinities[1][0] != 0 && imports[1][0] != ""){
        return 1;
    }
    return 0;
}

Pokemon::Pokemon(){
    initialize(imports, affinities);
    name = "Pikachu";
    id = 25;
    nickname = "Pikachu";
    level = 5;
    xp = 0;
    type[0] = imports[id][8];
    type[1] = imports[id][9];

    for(int ii = 0; ii < 6; ii++){
        statAff[ii] = affinities[25][ii];
        iv[ii] = getIv();
    }

    maxStat[0] = 10 + statAff[0];
    maxStat[1] = 4 + statAff[1];
    maxStat[2] = 3 + statAff[2];
    maxStat[3] = 4 + statAff[3];
    maxStat[4] = 3 + statAff[4];
    maxStat[5] = 4 + statAff[5];
    for(double ii = 1.0; ii <= level; ii++){
        for(int jj = 0; jj < 6; jj++){
            maxStat[jj] += (pow(1.05,ii/10)*(3.5/4)*statAff[jj]*(.9+(.2*iv[jj]/36)));
        }
    }
    for(int ii = 0; ii < 6; ii++){
        tempStat[ii] = maxStat[ii];
    }

    moves[0] = Move("Tackle","Normal",0,40.0,30);
    moves[1] = Move(imports[id][8] + "Whack","Normal",0,50.0,20);
    moves[2] = Move("Tail whip","Normal",2,20,25);
}

Pokemon::Pokemon(int ID, int startLevel){
    initialize(imports, affinities);
    name = imports[ID][0];
    id = ID;
    nickname = imports[ID][0];
    level = startLevel;
    xp = 0;
    type[0] = imports[ID][8];
    type[1] = imports[ID][9];

    for(int ii = 0; ii < 6; ii++){
        statAff[ii] = affinities[ID][ii];
        iv[ii] = getIv();
    }

    maxStat[0] = 10 + statAff[0];
    maxStat[1] = 4 + statAff[1];
    maxStat[2] = 3 + statAff[2];
    maxStat[3] = 4 + statAff[3];
    maxStat[4] = 3 + statAff[4];
    maxStat[5] = 4 + statAff[5];
    for(double ii = 1.0; ii <= level; ii++){
        for(int jj = 0; jj < 6; jj++){
            maxStat[jj] += (pow(1.05,ii/10)*(3.5/4)*statAff[jj]*(.9+(.2*iv[jj]/36)));
        }
    }
    for(int ii = 0; ii < 6; ii++){
        tempStat[ii] = maxStat[ii];
    }

    moves[0] = Move("Tackle","Normal",0,40.0,30);
    moves[1] = Move(imports[id][8] + "Whack","Normal",0,50.0,20);
    moves[2] = Move("Tail whip","Normal",2,20,25);
}

string Pokemon::getName(){
    return name;
}

int Pokemon::getId(){
    return id;
}

string Pokemon::getNickname(){
    return nickname;
}

int Pokemon::getLevel(){
    return level;
}

int Pokemon::getXp(){
    return xp;
}

double Pokemon::getMaxStat(int i){
    return maxStat[i];
}

double Pokemon::getStat(int i){
    return tempStat[i];
}

double Pokemon::getAffinity(int i){
    return statAff[i];
}

int Pokemon::getIv(int i){
    return iv[i];
}

void Pokemon::setNickname(string newName){
    nickname = newName;
}

void Pokemon::setLevel(int newLevel){
    level = newLevel;
}

void Pokemon::setXp(int newXp){
    xp = newXp;
}

void Pokemon::modStat(int i, double newStat){
    tempStat[i] = newStat;
}

Move Pokemon::getMove(int i){
    return moves[i];
}

void Pokemon::addMove(int i, Move m){
    moves[i] = m;
}

int Pokemon::replaceMove(string name, Move m){
    for(int ii = 0; ii < 4; ii++){
        if(moves[ii].getMoveName() == name){
            moves[ii] = m;
            return 1;
        }
    }
    return 0;
}

void Pokemon::levelUp(){
    level++;
    for(int ii = 0; ii < 6; ii++){
        maxStat[ii] += (pow(1.05,level/10)*(3.5/4)*statAff[ii]*(.9+(.2*iv[ii]/36)));
        tempStat[ii] += (pow(1.05,level/10)*(3.5/4)*statAff[ii]*(.9+(.2*iv[ii]/36)));
    }
}

void Pokemon::addXp(int n){
    xp += n;
}