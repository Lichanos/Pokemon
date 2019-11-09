//Nicholas Lumiere
//CS1300 UCB 
//Final Project - Pokemon Game

#include <iostream>
#include <string>
#include "Trainer.h"
#include "Move.h"
#include "Pokemon.h"
#include "Item.h"
using namespace std;

void welcome(){
    string username;
    int choice;
    cout << "Welcome to Pokémon!" << endl;
    cout << "Please state your name: ";
    cin >> username;
    cout << "Welcome, " << username << "!" << endl;
    cout << "Before you can begin your Pokémon adventure, you must choose a starting Pokémon, courtesy of the Professor." << endl;
    cout << "Please choose from the following Pokémon:" << endl;
    cout << "   1. Bulbasaur" << endl;
    cout << "   2. Charmander" << endl;
    cout << "   3. Squirtle" << endl;
    cout << "   4. Pikachu" << endl;
    cin >> choice;
}

int main(){

    return 0;
}