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
        cout << p.imports[pokemonNum][0] << " was successfully added to your pokedex." << endl << endl; 
    }
    else{
        cout << "There was an error." << endl;
        player.addPokemon(Pokemon(25,5));
        cout << "Pikachu was successfully added to your pokedex." << endl << endl;
    }

    return player;
}

Pokemon generate_pokemon(Trainer &player, int i){
    srand(i + player.getSteps());
    int level;
    int id;
    double rand1 = ((double)rand())/RAND_MAX;
    double rand2 = ((double)rand())/RAND_MAX;
    cout << "Randoms: " << rand1 << " " << rand2 << endl;
    double power = player.calcPowerLevel();
    if(power > 40){
        id = (int)(151*(rand1) + 1);
        level = (int)((4 + power)*(rand2) - 7);
    }
    else{
        level =  (int)((2+power)*(rand1) - 4);
        id = (int)(143*(rand2) + 1);
    }
    if(level < 1){
        level = 1;
    }
    return Pokemon(id, level);
}

int chooseActive(Trainer &player, int curr_pokemon){
    cout << "Change active pokemon" << endl;
    if(player.pokemon.size() < 6){
        int ii = 0;
        for(Pokemon p : player.pokemon){
            if((player.pokemon).at(ii).getStat(0) > 0 && ii != curr_pokemon){
                cout << ii+1 << ": " << (player.pokemon).at(ii).getName() << endl;
            }
            ii++;
        }
    }
    else{
        for(int ii = 0; ii < 6; ii++){
            if((player.pokemon).at(ii).getStat(0) > 0 && ii != curr_pokemon){
                cout << ii+1 << ": " << (player.pokemon).at(ii).getName() << endl;
            }
        }
    }
    string response = "";
    bool valid = false;
    while(!valid){
        cin >> response;  
        if(response != "1" || response != "2" || response != "3" || response != "4" || response != "5" || response != "0" || response != "cancel"){
            if(response == "cancel"){
                return -1;
            }
            else{
                int choice = stoi(response) - 1;
                if(choice >= 0 && choice < player.pokemon.size()){
                    if((player.pokemon).at(choice).getStat(0) > 0 && choice != curr_pokemon){
                        return choice;
                    }
                    else{
                        cout << "Invalid pokemon." << endl;
                    }
                }
                else{
                    cout << "Invalid pokemon." << endl;
                }
            }
        }
    }
    return -1;
}

int turn(Trainer &player, Pokemon &p, int &curr_pokemon, int i){
    srand(i + player.getXPos());
    cout << "Current Pokemon: " << (player.pokemon).at(curr_pokemon).getName() << " Lv. " << (player.pokemon).at(curr_pokemon).getLevel() << endl;
    (player.pokemon).at(curr_pokemon).printStats();
    cout << endl;
    cout << "Enemy " << p.getName() << endl;
    cout << "Lv. " << p.getLevel() << "  HP: " << (p.getStat(0)/p.getMaxStat(0))*100 << "%" << endl;
    cout << p.getStat(0) << endl;
    // p.printStats();
    cout << endl;

    cout << "What do you want to do?" << endl;
    cout << "1. Attack" << endl;
    cout << "2. Switch Pokemon" << endl;
    cout << "3. Bag" << endl;
    cout << "4. Run" << endl;

    string reply = "";
    bool valid = false;
    while(!valid){
        cin >> reply;
        if(reply != "1" && reply != "2" && reply != "3" && reply != "4"){
            cout << "Invalid. Try again." << endl;
        }
        else{
            valid = true;
        }
    }
    if(reply == "1"){
        int moveNum;
        int statAffected;
        (player.pokemon).at(curr_pokemon).printMoves();
        cin >> moveNum;
        if(moveNum > 0 && moveNum < 5){
            cout << (player.pokemon).at(curr_pokemon).getName() << " used " << (player.pokemon).at(curr_pokemon).getMove(moveNum-1).getMoveName() << endl;
            statAffected = (player.pokemon).at(curr_pokemon).getMove(moveNum-1).getStatType();
            
            if(statAffected == 0 && (player.pokemon).at(curr_pokemon).getMove(moveNum-1).getSpecial()){
                p.modStat(0, -1*((player.pokemon).at(curr_pokemon).getMove(moveNum-1).getDamage()) * (player.pokemon).at(curr_pokemon).getStat(3)/p.getStat(4) * 1.5 * ((double)(player.pokemon).at(curr_pokemon).getLevel())/50);
            }
            else if(statAffected != 0 && !(player.pokemon).at(curr_pokemon).getMove(moveNum-1).getTargetSelf()){
                if(p.getStat(statAffected)/p.getMaxStat(statAffected) != 1){
                    cout << "Reduced effects due to repeated use." << endl;
                }
                p.modStat(statAffected, (-1*(player.pokemon).at(curr_pokemon).getMove(moveNum).getDamage()/100)*p.getStat(statAffected));
            }
            else if(statAffected != 0 && (player.pokemon).at(curr_pokemon).getMove(moveNum-1).getTargetSelf()){
                if((player.pokemon).at(curr_pokemon).getStat(statAffected)/(player.pokemon).at(curr_pokemon).getMaxStat(statAffected) != 1){
                    cout << "Reduced effects due to repeated use." << endl;
                }
                (player.pokemon).at(curr_pokemon).modStat(statAffected, pow(((player.pokemon).at(curr_pokemon).getMaxStat(statAffected)/(player.pokemon).at(curr_pokemon).getStat(statAffected)),2)*(player.pokemon).at(curr_pokemon).getMove(moveNum).getDamage()/100);
            }
            else{
                double damage_dealt = (-1*((player.pokemon).at(curr_pokemon).getMove(moveNum-1).getDamage()) * (player.pokemon).at(curr_pokemon).getStat(1)/p.getStat(2) * 2 * (((double)(player.pokemon).at(curr_pokemon).getLevel())/50));
                cout << "damage dealt: " << damage_dealt << endl;
                p.modStat(0, damage_dealt);
            }
            if(p.getStat(0) <= 0){
                cout << endl << p.getName() << " HP: 0%" << endl;
                cout << "The enemy " << p.getName() << " has fainted!" << endl;
                //Adding xp
                int earned_xp = p.getLevel()*10;
                (player.pokemon).at(curr_pokemon).setXp((player.pokemon).at(curr_pokemon).getXp() + earned_xp);
                cout << (player.pokemon).at(curr_pokemon).getName() << " earned " << earned_xp << " xp!" << endl;
                //levels up
                if((player.pokemon).at(curr_pokemon).getXp() > (player.pokemon).at(curr_pokemon).getLevel() * 10){
                    (player.pokemon).at(curr_pokemon).setXp((player.pokemon).at(curr_pokemon).getXp() - ((player.pokemon).at(curr_pokemon).getLevel() * 10));
                    (player.pokemon).at(curr_pokemon).levelUp();
                    cout << player.pokemon.at(curr_pokemon).getName() << " has leveled up to level " << player.pokemon.at(curr_pokemon).getLevel() << "!" << endl;
                }
                //cout << "about to return 1" << endl;
                return 1;
            }
            cout << "Enemy pokemon HP: " << p.getStat(0) << endl << endl;
        }
        else{
            cout << "Invalid" << endl;
        }
    }
    else if(reply == "2"){        
        int temp = chooseActive(player, curr_pokemon);
        if(temp != -1){
            curr_pokemon = temp;
        }
        else{
            //Technically recursion :)
            return turn(player, p, curr_pokemon, i);
        }
    }
    //bag stuff
    else if(reply == "3"){
        int ii = 1;
        cout << "Choose which item to use" << endl;
        for(Item thing : player.items){
            cout << ii << ". " << thing.getItemName() << "  " << thing.getNumber() << endl;
            ii++;
        }
        bool valid = false;
        int itemNum;
        while(!valid){
            cin >> itemNum;
            if(itemNum > 0 && itemNum <= player.items.size()){
                itemNum -= 1;
                valid = true;
            }
            else{
                cout << "Invalid response, try again." << endl;
            }
        }
        double j;
        if(player.items.at(itemNum).getItemName() == "Pokeball"){
            player.items.at(itemNum).decrement();
            j = ((double)rand())/RAND_MAX;
            cout << j << endl;
            if(j < .66*((.2 + p.getMaxStat(0) - p.getStat(0)) * (((double)player.pokemon.at(curr_pokemon).getLevel())/p.getLevel()))){
                for(int jj = 1; jj < 6; jj++){
                    p.setStat(jj, p.getMaxStat(jj));
                }
                player.addPokemon(p);
                cout << player.pokemon.size() << endl;
                cout << "You have successfully caught " << p.getName() << endl;
                return 1;
            }
            else{
                cout << "Oh no! The wild pokemon broke free!" << endl;
            }
        }
        else if(player.items.at(itemNum).getItemName() == "Great Ball"){
            player.items.at(itemNum).decrement();
            j = ((double)rand())/RAND_MAX;
            if(j < .8*((.2 + p.getMaxStat(0) - p.getStat(0)) * (((double)player.pokemon.at(curr_pokemon).getLevel())/p.getLevel()))){
                for(int jj = 1; jj < 6; jj++){
                    p.setStat(jj, p.getMaxStat(jj));
                }
                player.addPokemon(p);
                cout << "You have successfully caught " << p.getName() << endl;
                return 1;
            }
            else{
                cout << "Oh no! The wild pokemon broke free!" << endl;
            }
        }
        else if(player.items.at(itemNum).getItemName() == "Ultra Ball"){
            player.items.at(itemNum).decrement();
            j = ((double)rand())/RAND_MAX;
            if(j < .9*((.2 + p.getMaxStat(0) - p.getStat(0)) * (((double)player.pokemon.at(curr_pokemon).getLevel())/p.getLevel()))){
                for(int jj = 1; jj < 6; jj++){
                    p.setStat(jj, p.getMaxStat(jj));
                }
                player.addPokemon(p);
                cout << "You have successfully caught " << p.getName() << endl;
                return 1;
            }
            else{
                cout << "Oh no! The wild pokemon broke free!" << endl;
            }
        }
        else if(player.items.at(itemNum).getItemName() == "Potion"){
            player.items.at(itemNum).decrement();
            player.pokemon.at(curr_pokemon).modStat(0, 20);
        }
        else if(player.items.at(itemNum).getItemName() == "Super Potion"){
            player.items.at(itemNum).decrement();
            player.pokemon.at(curr_pokemon).modStat(0, 50);
        }
        else if(player.items.at(itemNum).getItemName() == "Hyper Potion"){
            player.items.at(itemNum).decrement();
            player.pokemon.at(curr_pokemon).modStat(0, 200);
        }
        else{
            cout << "Invalid item" << endl;
        }
        if(player.pokemon.at(curr_pokemon).getStat(0) > player.pokemon.at(curr_pokemon).getMaxStat(0)){
            player.pokemon.at(curr_pokemon).setStat(0, player.pokemon.at(curr_pokemon).getMaxStat(0));
        }
    }
    //Run
    else if(reply == "4"){
        cout << "You have successfully escaped!" << endl;
        return 2;
    }
    else{
        cout << "Invalid response." << endl;
    }
    return 0;
}

//ENCOUNTER
void encounter(Trainer &player, Pokemon &p, int i){
    srand(i+player.getSteps());
    cout << "You've encountered a wild " << p.getName() << endl;
    bool resolved = false;
    int reply = 0;
    int curr_pokemon;
    for(int ii = 0; ii < 6; ii++){
        if(player.getPokemonAt(ii).getStat(0) > 0){
            curr_pokemon = ii;
            break;
        }
    }

    while(!resolved){
        cout << "Your turn." << endl;
        int result = 0;
        result = turn(player, p, curr_pokemon, rand());
        //cout << result << endl;
        if(result == 1){
            resolved = true;
        }
        else if(result == 2){
            resolved = true;
        }
        else{
            cout << "Enemy's turn." << endl;
            double decision;
            decision = p.getNumMoves()*((double)rand())/RAND_MAX;
            int moveNum;
            if(decision < 1){
                moveNum = 0;
            }
            else if(decision < 2){
                moveNum = 1;
            }
            else if(decision < 3){
                moveNum = 2;
            }
            else{
                moveNum = 3;
            }
            int statAffected = p.getMove(moveNum).getStatType();
            if(statAffected == 0 && p.getMove(moveNum).getSpecial()){
                double damage_dealt = -1*(p.getMove(moveNum).getDamage()) * p.getStat(3)/(player.pokemon).at(curr_pokemon).getStat(4) * 2 * ((double)p.getLevel())/50;
                (player.pokemon).at(curr_pokemon).modStat(0, damage_dealt);
            }
            else if(statAffected != 0 && !p.getMove(moveNum).getTargetSelf()){
                (player.pokemon).at(curr_pokemon).modStat(statAffected, -1*(p.getMove(moveNum).getDamage()/100)*(player.pokemon).at(curr_pokemon).getStat(statAffected));
            }
            else if(statAffected != 0 && p.getMove(moveNum).getTargetSelf()){
                p.modStat(statAffected, pow(p.getMaxStat(statAffected)/p.getStat(statAffected),2)*(p.getMove(moveNum).getDamage()/100));
            }
            else{
                double damage_dealt = -1*(p.getMove(moveNum).getDamage()) * p.getStat(1)/(player.pokemon).at(curr_pokemon).getStat(2) * 2 * ((double)p.getLevel())/50;
                (player.pokemon).at(curr_pokemon).modStat(0, damage_dealt);
            }
            cout << p.getName() << " used " << p.getMove(moveNum).getMoveName() << "!" << endl;
            cout << endl; 

            if((player.pokemon).at(curr_pokemon).getStat(0) < 0){
                cout << (player.pokemon).at(curr_pokemon).getName() << " has fainted" << endl;
                curr_pokemon = chooseActive(player, curr_pokemon);
            }
        }
    }
    //Restores all non-hp stats to normal
    if(player.getPokemon().size() < 6){
        int ii = 0;
        for(Pokemon p : player.getPokemon()){
            for(int jj = 1; jj < 6; jj++){
                ((player.pokemon).at(ii)).setStat(jj, player.getPokemonAt(ii).getMaxStat(jj));
            }
            ii++;
        }
    }
    else{
        for(int ii = 0; ii < 6; ii++){
            for(int jj = 1; jj < 6; jj++){
                ((player.pokemon).at(ii)).setStat(jj, player.getPokemonAt(ii).getMaxStat(jj));
            }
        }
    }
}

void encounter(Trainer &player, Trainer &t, int i){
    
}

//i just for passing into generate pokemon
void step(Trainer player, vector<Trainer> trainers, Map map, int i){
    srand(i+player.getSteps());
    bool br = false;
    while(!br){
        //Keystroke madness
        string s = "";
        cin >> s;
        int result;
        if(s == "w"){
            if(player.getYPos() > 0){
                result = player.moveUp(map.tiles[player.getYPos()-1][player.getXPos()], rand());
            }
            else {
                cout << "You cannot move any further in this direction." << endl;
            }
        }
        else if(s == "a"){
            if(player.getXPos() > 0){
                result = player.moveLeft(map.tiles[player.getYPos()][player.getXPos()-1], rand());
            }
            else {
                cout << "You cannot move any further in this direction." << endl;
            }
        }
        else if(s == "s"){
            if(player.getYPos() < (map.getMaxY()-1)){
                result = player.moveDown(map.tiles[player.getYPos()+1][player.getXPos()], rand());
            }
            else {
                cout << "You cannot move any further in this direction." << endl;
            }
        }
        else if(s == "d"){
            if(player.getXPos() < (map.getMaxX() -1)){
                result = player.moveRight(map.tiles[player.getYPos()][player.getXPos()+1], rand());
            }
            else {
                cout << "You cannot move any further in this direction." << endl;
            }
        }

        if(result == 1){
            map.printMapAroundPlayer(player.getXPos(), player.getYPos(), trainers);
        }
        else if(result == 2){
            Pokemon p = generate_pokemon(player, i);
            //encounter
            encounter(player, p, rand());
            map.printMapAroundPlayer(player.getXPos(), player.getYPos(), trainers);
        }
        else if(result == 3){
            //pokemon center things
        }
        else if(result == 4){
            //gym things
        }
    }
}

int main(){
    Trainer player = welcome();
    player.addItem(Item("Pokeball",10));
    player.addItem(Item("Potion",5));
    vector<Trainer> trainers;
    
    cout << "Half-sized map or full-sized map? (Enter \"1\" or \"2\"): ";
    int size; cin >> size; 
    cout << "What should the map's seed be? (0 for defualt)" << endl;
    cout << "Note: The the seed only impacts the map, not the placement of the player." << endl;
    int seed; cin >> seed;
    Map map = Map(size, seed);
    map.printMap();
    srand(time(0) + player.getSteps());
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

    for(int ii = 0; ii < size*10; ii++){
        int numPokemon = (int)(4*((double)rand())/RAND_MAX);
        int x;
        int y;
        bool valid_terrain = false;
        while(!valid_terrain){
            y = (int)(map.getMaxY()*((double)(rand())/RAND_MAX));
            x = (int)(map.getMaxX()*((double)(rand())/RAND_MAX));
            bool trainer_here = false;
            for(Trainer t : trainers){
                if(t.getXPos() == x && t.getYPos() == y){
                    trainer_here = true;
                }
            }
            if((map.tiles[y][x].getTerrain() == '.' || map.tiles[y][x].getTerrain() == '#') && !trainer_here){
                valid_terrain = true;
            }
        }
        trainers.push_back(Trainer("PokeFan", x, y));
        map.tiles[trainers.at(ii).getYPos()][trainers.at(ii).getXPos()].setTerrain('!');
        for(int jj = 0; jj < numPokemon; jj++){
            trainers.at(ii).addPokemon(generate_pokemon(player, rand()));
        }
    }

    map.printMapAroundPlayer(player.getXPos(), player.getYPos(), trainers);

    bool quit = false;
    while(!quit){
        step(player, trainers, map, rand());
    }

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