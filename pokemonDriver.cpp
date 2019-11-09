using namespace std;
#include "Pokemon.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <time.h>
#include <stdio.h> 
#include <stdlib.h> 

int main(){
    Pokemon pika = Pokemon();
    Pokemon two = Pokemon(2, 9);
    
    cout << pika.getName() << endl;
    cout << pika.getLevel() << endl;
    cout << pika.getAttAffinity() << endl;
    cout << pika.getId() << endl;
    cout << pika.getLevel() << endl;
    cout << endl;
    cout << two.getName() << endl;
    cout << two.getHpAffinity() << endl;
    cout << two.getAttAffinity() << endl;
    cout << two.getDefAffinity() << endl;
    cout << two.getSpAttAffinity() << endl;
    cout << two.getSpDefAffinity() << endl;
    cout << two.getSpdAffinity() << endl;
    cout << two.getHpIv() << endl;

    return 0;
}