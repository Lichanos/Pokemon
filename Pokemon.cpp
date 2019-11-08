//Nicholas Lumiere
//CS1300 UCB 
//Final Project - Pokemon Class

#include "Pokemon.h"
#include <string>
#include <fstream>
using namespace std;

string name;
int id;
string nickname;
int level;
int xp;
string type[2] = {};

int hpIv;
int attIv;
int defIv;
int spAttIv;
int spDefIv;
int spdIv;
double hpAffinity;
double attAffinity;
double defAffinity;
double spAttAfinity;
double spDefAffinity;
double spdAffinity;
double tempHp;
double tempAtt;
double tempDef;
double tempSpDef;
double tempSpAtt;
double tempSpd;

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

string imports[152][9] = {};
double affinities[152][6] = {0};
int initialize(){
    imports[0][] = {"name","hp","att","def","spAtt","spDef","spd","type1","type2"};
    ifstream reader;
    reader.open("pokemon.txt");
    if(reader.is_open()){
        string line = "";
        for(int ii = 1; ii < 152; ii++){
            string pieces[9] = {};
            if(line != ""){
                split(line,',',pieces,9);
                for(int jj = 0; jj < 9; jj++){
                    imports[ii][jj] = pieces[jj];
                }
            }
        }
    }
    reader.close();
    affinities[0][] = {"hp","att","def","spAtt","spDef","spd"};
    for(int ii = 1; ii < 151; ii++){
        for(int jj = 0; jj < 6; jj++){
            affinities[ii][jj] = stod(imports[ii][jj + 1]);
        }
    }
}

Pokemon::Pokemon(){
    initialize();
    name = "Pikachu";
    id = 25;
    nickname = "Pikachu";
    level = 5;
    xp = 0;
    type[0] = imports[ID][8];
    if(imports[9] != ""){
        type[1] = imports[ID][9];
    } else {
        type[1] = "";
    }

    hpAffinity = affinities[25][0];
    attAffinity = affinities[25][1];
    defAffinity = affinities[25][2];
    spAttAfinity = affinities[25][3];
    spDefAffinity = affinities[25][4];
    spdAffinity = affinities[25][5];
    hpIv = 0;
    attIv = 0;
    defIv = 0;
    spAttIv = 0;
    spDefIv = 0;
    spdIv = 0;
}

Pokemon::Pokemon(int ID, int startLevel){
    initialize();
    name = imports[ID][0];
    id = ID;
    nickname = imports[ID][0];
    level = startLevel;
    xp = 0;
    type[0] = imports[ID][8];
    if(imports[9] != ""){
        type[1] = imports[ID][9];
    } else {
        type[1] = "";
    }

    hpAffinity = affinities[ID][0];
    attAffinity = affinities[ID][1];
    defAffinity = affinities[ID][2];
    spAttAfinity = affinities[ID][3];
    spDefAffinity = affinities[ID][4];
    spdAffinity = affinities[ID][5];
    hpIv = 0;
    attIv = 0;
    defIv = 0;
    spAttIv = 0;
    spDefIv = 0;
    spdIv = 0;
}