//Nicholas Lumiere
//CS1300 UCB 
//Final Project - Pokemon Class

#include "Pokemon.h"
using namespace std;

string name;
int id;
string nickname;
int level;
int xp;

double maxHp;
double maxAtt;
double maxDef;
double maxSpAtt;
double maxSpDef;
double maxSpd;
double tempHp;
double tempAtt;
double tempDef;
double tempSpDef;
double tempSpAtt;
double tempSpd;

Pokemon::Pokemon(){
    name = "Pikachu";
    id = 25;
    nickname = "Pikachu";
    level = 5;
    xp = 0;
}

Pokemon::Pokemon(int ID, int startLevel){
    name = "";
    id = ID;
    nickname = name;
    level = startLevel;
    xp = 0;
}