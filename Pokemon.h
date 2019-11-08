//Nicholas Lumiere
//CS1300 UCB 
//Final Project - Pokemon Class

#ifndef POKEMON_H
#define POKEMON_H
#include <string>
#include <fstream>
using namespace std;

class Pokemon{
    private:
        string name;
        string nickname;
        int id;
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
        double tempSpAtt;
        double tempSpDef;
        double tempSpd;

        string imports[152][9];
        double affinities[152][6];
    public:
        int type[2];
        Move moves[4];

        int split(string, char, string pieces[], int);
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
        double getSpAttAfinity();
        double getSpDefAffinity();
        double getSpdAffinity();

        string setNickname(string);
        void setLevel(int);
        void setXp(int);
        void changeHp(double);
        void setTempAtt(double);
        void setTempDef(double);
        void setTempSpAtt(double);
        void setTempSpDef(double);
        void getTempSpd(double);

        void shuffleIvs();

}#endif
