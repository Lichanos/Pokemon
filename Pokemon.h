//Nicholas Lumiere
//CS1300 UCB 
//Final Project - Pokemon Class

#ifndef POKEMON_H
#define POKEMON_H
using namespace std;

class Pokemon{
    private:
        string name;
        string nickname;
        int id;
        int level;
        int xp;

        const double maxHp;
        const double maxAtt;
        const double maxDef;
        const double maxSpAtt;
        const double maxSpDef;
        const double maxSpd;
        double tempHp;
        double tempAtt;
        double tempDef;
        double tempSpAtt;
        double tempSpDef;
        double tempSpd;
    public:
        int type[2];
        Move moves[4];

        Pokemon();
        Pokemon(int, int);
        string getName();
        int const getId();
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

        string setNickname(string);
        void setLevel(int);
        void setXp(int);
        void changeHp(double);
        void setTempAtt(double);
        void setTempDef(double);
        void setTempSpAtt(double);
        void setTempSpDef(double);
        void getTempSpd(double);

}#endif
