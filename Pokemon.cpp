//Nicholas Lumiere
//CS1300 UCB 
//Final Project - Pokemon Class

#include "Pokemon.h"
#include <string>
#include <fstream>
#include <math.h>
#include <iostream>
using namespace std;

string name;
int id;
string nickname;
int level;
int xp;
string type[2] = {};

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
double tempSpDef;
double tempSpAtt;
double tempSpd;

string imports[152][9] = {""};
double affinities[152][6] = {0};

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

    hpAffinity = affinities[25][0];
    attAffinity = affinities[25][1];
    defAffinity = affinities[25][2];
    spAttAffinity = affinities[25][3];
    spDefAffinity = affinities[25][4];
    spdAffinity = affinities[25][5];
    hpIv = 0;
    attIv = 0;
    defIv = 0;
    spAttIv = 0;
    spDefIv = 0;
    spdIv = 0;

    maxHp = 10 + hpAffinity;
    maxAtt = 4 + attAffinity;
    maxDef = 3 + defAffinity;
    maxSpAtt = 4 + spAttAffinity;
    maxSpDef = 3 + spDefAffinity;
    maxSpd = 4 + spdAffinity;
    for(double ii = 1.0; ii <= level; ii++){
        maxHp += (pow(1.05,ii/10)*(3.5/4)*hpAffinity*(.9+(.2*hpIv/36)));
        maxAtt += (pow(1.05,ii/10)*(3.5/4)*attAffinity*(.9+(.2*attIv/36)));
        maxDef += (pow(1.05,ii/10)*(3.5/4)*defAffinity*(.9+(.2*defIv/36)));
        maxSpAtt += (pow(1.05,ii/10)*(3.5/4)*spAttAffinity*(.9+(.2*spAttIv/36)));
        maxSpDef += (pow(1.05,ii/10)*(3.5/4)*spDefAffinity*(.9+(.2*spDefIv/36)));
        maxSpd += (pow(1.05,ii/10)*(3.5/4)*spdAffinity*(.9+(.2*spdIv/36)));
    }
    tempHp = maxHp;
    tempAtt = maxAtt;
    tempDef = maxDef;
    tempSpAtt = maxSpAtt;
    tempSpDef = maxSpDef;
    tempSpd = maxSpd;

    //moves
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

    hpAffinity = affinities[ID][0];
    attAffinity = affinities[ID][1];
    defAffinity = affinities[ID][2];
    spAttAffinity = affinities[ID][3];
    spDefAffinity = affinities[ID][4];
    spdAffinity = affinities[ID][5];
    hpIv = 0;
    attIv = 0;
    defIv = 0;
    spAttIv = 0;
    spDefIv = 0;
    spdIv = 0;

    maxHp = 10 + hpAffinity;
    maxAtt = 4 + attAffinity;
    maxDef = 3 + defAffinity;
    maxSpAtt = 4 + spAttAffinity;
    maxSpDef = 3 + spDefAffinity;
    maxSpd = 4 + spdAffinity;
    for(double ii = 1.0; ii <= level; ii++){
        maxHp += (pow(1.05,ii/10)*(3.5/4)*hpAffinity*(.9+(.2*hpIv/36)));
        maxAtt += (pow(1.05,ii/10)*(3.5/4)*attAffinity*(.9+(.2*attIv/36)));
        maxDef += (pow(1.05,ii/10)*(3.5/4)*defAffinity*(.9+(.2*defIv/36)));
        maxSpAtt += (pow(1.05,ii/10)*(3.5/4)*spAttAffinity*(.9+(.2*spAttIv/36)));
        maxSpDef += (pow(1.05,ii/10)*(3.5/4)*spDefAffinity*(.9+(.2*spDefIv/36)));
        maxSpd += (pow(1.05,ii/10)*(3.5/4)*spdAffinity*(.9+(.2*spdIv/36)));
    }
    tempHp = maxHp;
    tempAtt = maxAtt;
    tempDef = maxDef;
    tempSpAtt = maxSpAtt;
    tempSpDef = maxSpDef;
    tempSpd = maxSpd;

    //moves
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

double Pokemon::getMaxHP(){
    return maxHp;
}

double Pokemon::getmaxAtt(){
    return maxAtt;
}

double Pokemon::getMaxDef(){
    return maxDef;
}

double Pokemon::getMaxSpAtt(){
    return maxSpAtt;
}

double Pokemon::getMaxSpDef(){
    return maxSpDef;
}

double Pokemon::getMaxSpd(){
    return maxSpd;
}

double Pokemon::getTempHp(){
    return tempHp;
}

double Pokemon::getTempAtt(){
    return tempAtt;
}

double Pokemon::getTempDef(){
    return tempDef;
}

double Pokemon::getTempSpAtt(){
    return tempSpAtt;
}

double Pokemon::getTempSpDef(){
    return tempSpDef;
}

double Pokemon::getTempSpd(){
    return tempSpd;
}

int Pokemon::getHpIv(){
    return hpIv;
}

int Pokemon::getAttIv(){
    return attIv;
}

int Pokemon::getDefIv(){
    return defIv;
}

int Pokemon::getSpAttIv(){
    return spAttIv;
}

int Pokemon::getSpDefIv(){
    return spDefIv;
}

int Pokemon::getSpdIv(){
    return spdIv;
}

double Pokemon::getHpAffinity(){
    return hpAffinity;
}

double Pokemon::getAttAffinity(){
    return attAffinity;
}

double Pokemon::getDefAffinity(){
    return defAffinity;
}

double Pokemon::getSpAttAfinity(){
    return spAttAffinity;
}

double Pokemon::getSpDefAffinity(){
    return spDefAffinity;
}

double Pokemon::getSpdAffinity(){
    return spdAffinity;
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

void Pokemon::modHp(double newHp){
    tempHp += newHp;
}

void Pokemon::modAtt(double newAtt){
    tempAtt += newAtt;
}

void Pokemon::modDef(double newDef){
    tempDef += newDef;
}

void Pokemon::modSpAtt(double newSpAtt){
    tempSpAtt += newSpAtt;
}

void Pokemon::modSpDef(double newSpDef){
    tempSpDef += newSpDef;
}

void Pokemon::modSpd(double newSpd){
    tempSpd += newSpd;
}

void Pokemon::levelUp(){
    level++;
    maxHp += (pow(1.05,level/10)*(3.5/4)*hpAffinity*(.9+(.2*hpIv/36)));
    maxAtt += (pow(1.05,level/10)*(3.5/4)*attAffinity*(.9+(.2*attIv/36)));
    maxDef += (pow(1.05,level/10)*(3.5/4)*defAffinity*(.9+(.2*defIv/36)));
    maxSpAtt += (pow(1.05,level/10)*(3.5/4)*spAttAffinity*(.9+(.2*spAttIv/36)));
    maxSpDef += (pow(1.05,level/10)*(3.5/4)*spDefAffinity*(.9+(.2*spDefIv/36)));
    maxSpd += (pow(1.05,level/10)*(3.5/4)*spdAffinity*(.9+(.2*spdIv/36)));
    tempHp += (pow(1.05,level/10)*(3.5/4)*hpAffinity*(.9+(.2*hpIv/36)));
    tempAtt += (pow(1.05,level/10)*(3.5/4)*attAffinity*(.9+(.2*attIv/36)));
    tempDef += (pow(1.05,level/10)*(3.5/4)*defAffinity*(.9+(.2*defIv/36)));
    tempSpAtt += (pow(1.05,level/10)*(3.5/4)*spAttAffinity*(.9+(.2*spAttIv/36)));
    tempSpDef += (pow(1.05,level/10)*(3.5/4)*spDefAffinity*(.9+(.2*spDefIv/36)));
    tempSpd += (pow(1.05,level/10)*(3.5/4)*spdAffinity*(.9+(.2*spdIv/36)));

    //moves
}

void Pokemon::addXp(int n){
    xp += n;
}