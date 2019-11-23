//Nicholas Lumiere
//CS1300 UCB 
//Final Project - Pokemon Game

/************************************************************************************************************
 * Important: In case you skipped the README, all class comments are in my *header* files not my .cpp files *
 ************************************************************************************************************/

#include <iostream>
#include <string>
#include "Trainer.h"
#include "Move.h"
#include "Pokemon.h"
#include "Item.h"
#include "Map.h"
#include "Tile.h"
#include <vector>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

Trainer welcome(){
    string username;
    int choice;
    int pokemonNum;
    bool valid = false;
    cout << "Welcome to Pokemon!" << endl;
    cout << "Please state your name: ";
    cin >> username;
    cout << "Welcome, " << username << "!" << endl;
    cout << "Before you can begin your Pokémon adventure, you must choose a starting Pokémon, courtesy of the Professor." << endl;
    while(!valid){
        cout << "Please choose from the following Pokémon:" << endl;
        cout << "   1. Bulbasaur" << endl;
        cout << "   2. Charmander" << endl;
        cout << "   3. Squirtle" << endl;
        cout << "   4. Pikachu" << endl;
        cin >> choice;
        if(choice == 1){
            pokemonNum = 1;
            valid = true;
        }
        else if(choice == 2){
            pokemonNum = 4;
            valid = true;
        }
        else if(choice  == 3){
            pokemonNum = 7;
            valid = true;
        }
        else if(choice == 4){
            pokemonNum = 25;
            valid = true;
        }
        else{
            cout << "Invalid choice" << endl;
        }
    }
    Trainer player = Trainer();
    player.setName(username);
    Pokemon p = Pokemon(pokemonNum, 5);
    int firstSuccess = player.addPokemon(p);
    if(firstSuccess == 1){
        cout << p.imports[pokemonNum][0] << " was successfully added to your pokedex." << endl; 
    }
    else{
        cout << "There was an error." << endl;
        player.addPokemon(Pokemon(25,5));
        cout << "Pikachu was successfully added to your pokedex.";
    }

    return player;
}

Pokemon generate_pokemon(Trainer player){
    int level;
    int id;
    srand(time(0));
    double power = player.calcPowerLevel();
    if(power > 40){
        id = (int)((151*((double)rand())/RAND_MAX) + 1);
        level = (int)((10*((double)rand())/RAND_MAX) - 7);
    }
    else{
        level = (int)((6*((double)rand())/RAND_MAX) - 4);
        id = (int)((143*((double)rand())/RAND_MAX) + 1);
    }
    return Pokemon(id, level);
}

int main(){
    Trainer player = welcome();
    vector<Trainer> trainers;
    vector<Pokemon> wild_pokemon;
    
    cout << "Half-sized map or full-sized map? (Enter \"1\" or \"2\"): ";
    int size; cin >> size; 
    cout << "What should the map's seed be? (0 for defualt)" << endl;
    int seed; cin >> seed;
    Map map = Map(size, seed);
    map.printMap();
    srand(time(0));
    bool valid_terrain = false;
    while(!valid_terrain){
        int y = (int)(map.getMaxY()*((double)(rand())/RAND_MAX));
        int x = (int)(map.getMaxX()*((double)(rand())/RAND_MAX));
        if(map.tiles[y][x].getTerrain() == '.'){
            player.setXPos(x);
            player.setYPos(y);
            valid_terrain = true;
        }
    }
    // cout << endl;
    // cout << player.getXPos() << endl;
    // cout << player.getYPos() << endl;

    // for(int ii = 0; ii < size*20; ii++){

    // }

    // generate_pokemon(player);

    return 0;
}

/**
 * Stuff I'm going to add
 * Put the player on a map
 * Put pokemon and trainers on a map, scattered randomly. Have a temporary terrain tile representing trainers and the player
 * Have the map only show 6 tiles in all directions of the player instead of the entire thing
 * Allow the player to move around
 *      Chance to encounter wild pokemon when in tall grass
 * 
 * Write a battle method for wild pokemon
 *      Use weighted random numbers to calculate the likelihood of attacking/fleeing
 *          Randomly select from viable tall grass tiles where the wild pokemon flees to
 *      Use weighted randomness to determine which moves to use
 *      Determine likelihood of capturing the wild pokemon
 *          Method for this too
 * Write a similar battle method for trainers
 *      Weighted randomness for how trainers choose the pokemon they send in
 * 
 * Allow player to buy items from shops when at shops
 * Allow player to heal and reorder *all* pokemon when at pokemon centers
 * Checks to see if there is certain terrain present to use additional functions
 * Implement additional battles for gym leaders
 * Implement additional battles for elite 4 and champion
 */