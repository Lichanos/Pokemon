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
    cout << pika.getAffinity(0) << endl;
    cout << pika.getId() << endl;
    cout << pika.getLevel() << endl;
    cout << endl;
    cout << two.getName() << endl;
    for(int ii = 0; ii < 6; ii++){
        cout << two.getAffinity(ii) << endl;
    }
    cout << two.getIv(5) << endl;

    return 0;
}