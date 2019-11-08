using namespace std;
#include "Pokemon.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

int main(){
    Pokemon pika = Pokemon();
    Pokemon two = Pokemon(2, 9);
    cout << pika.getAttAffinity() << endl;
    cout << pika.getId() << endl;
    cout << pika.getLevel() << endl;
    cout << endl;
    cout << two.getName() << endl;
    cout << two.getAttAffinity() << endl;
    cout << two.getHpIv() << endl;

    return 0;
}