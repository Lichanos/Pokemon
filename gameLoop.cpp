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
    cout << "Before you can begin your Pokemon adventure, you must choose a starting Pokemon, courtesy of the Professor." << endl;
    while(!valid){
        cout << "Please choose from the following Pokemon:" << endl;
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

Pokemon generatePokemon(Trainer &player, int i){
    int level;
    int id;
    double rand1 = ((double)rand())/RAND_MAX;
    double rand2 = ((double)rand())/RAND_MAX;
    //cout << "Randoms: " << rand1 << " " << rand2 << endl;
    double power = player.calcPowerLevel();
    if(power > 40){
        id = (int)(151*(rand1) + 1);
        level = (int)((4 + power)*(rand2) - 7);
    }
    else{
        level =  (int)((3+power)*(rand1) - 4);
        id = (int)(143*(rand2) + 1);
    }
    if(level < 1){
        level = 1;
    }
    return Pokemon(id, level);
}

int chooseActive(Trainer &player, int curr_pokemon){
    cout << "Change active pokemon" << endl;
    bool fainted = true;
    if(player.pokemon.size() < 6){
        int ii = 0;
        for(Pokemon p : player.pokemon){
            if((player.pokemon).at(ii).getStat(0) > 0){
                cout << ii+1 << ": " << (player.pokemon).at(ii).getName() << "  HP: " << player.pokemon.at(ii).getStat(0) << endl;
                fainted = false;
            }
            ii++;
        }
    }
    else{
        for(int ii = 0; ii < 6; ii++){
            if((player.pokemon).at(ii).getStat(0) > 0){
                cout << ii+1 << ": " << (player.pokemon).at(ii).getName() << "  HP: " << player.pokemon.at(ii).getStat(0) << endl;
                fainted = false;
            }
        }
    }
    if(fainted){
        return -3;
    }
    string response = "";
    bool valid = false;
    while(!valid){
        cin >> response;  
        if(response != "1" || response != "2" || response != "3" || response != "4" || response != "5" || response != "6" || response != "cancel"){
            if(response == "cancel"){
                return -1;
            }
            else{
                int choice = stoi(response) - 1;
                cout << choice << endl;
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

void attack(Pokemon &p1, Pokemon &p2, int moveNum){
    int statAffected = p1.getMove(moveNum).getStatType();
    double damage_dealt;
    if(statAffected == 0 && p1.getMove(moveNum).getSpecial()){
        damage_dealt = -1*(p1.getMove(moveNum).getDamage()) * p1.getStat(3)/p2.getStat(4) * 2 * ((double)p1.getLevel())/50;
        p2.modStat(0, damage_dealt);
    }
    else if(statAffected != 0 && !p1.getMove(moveNum).getTargetSelf()){
        p2.modStat(statAffected, -1*(p1.getMove(moveNum).getDamage()/100)*p2.getStat(statAffected));
    }
    else if(statAffected != 0 && p1.getMove(moveNum).getTargetSelf()){
        p1.modStat(statAffected, pow(p1.getMaxStat(statAffected)/p1.getStat(statAffected),2)*(p1.getMove(moveNum).getDamage()/100));
    }
    else{
        damage_dealt = -1*(p1.getMove(moveNum).getDamage()) * p1.getStat(1)/p2.getStat(2) * 2 * ((double)p1.getLevel())/50;
        p2.modStat(0, damage_dealt);
    }
    cout << p1.getName() << " used " << p1.getMove(moveNum).getMoveName() << " dealing " << (int)damage_dealt << " damage!" << endl;
    cout << endl;
}

int yourTurn(Trainer &player, Pokemon &p, int &player_pokemon){
    cout << "Your turn" << endl;
    cout << "Current Pokemon: " << (player.pokemon).at(player_pokemon).getName() << " Lv. " << (player.pokemon).at(player_pokemon).getLevel() << endl;
    (player.pokemon).at(player_pokemon).printStats();
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
    string reply2 = "";
    bool valid;
    bool valid2;
    while(!valid){
        cin >> reply;
        if(reply == "1"){
            valid = true;
            int moveNum = -1;
            cout << "Select a move" << endl;
            player.pokemon.at(player_pokemon).printMoves();
            cin.clear();
            while(!valid2 || moveNum < 0){
                cin >> reply2;
                if(reply2 == "1"){
                    if(player.pokemon.at(player_pokemon).getNumMoves() > 0){
                        valid2 = true;
                        moveNum = 0;
                    }
                }
                else if(reply2 == "2"){
                    if(player.pokemon.at(player_pokemon).getNumMoves() > 1){
                        valid2 = true;
                        moveNum = 1;
                    }
                }
                else if(reply2 == "3"){
                    if(player.pokemon.at(player_pokemon).getNumMoves() > 2){
                        valid2 = true;
                        moveNum = 2;
                    }
                }
                else if(reply2 == "4"){
                    if(player.pokemon.at(player_pokemon).getNumMoves() > 3){
                        valid2 = true;
                        moveNum = 3;
                    }
                }
                else{
                    cout << "Invalid response" << endl;
                }
            }
            cout << moveNum << endl;
            if(valid2 == true && moveNum > -1){
                attack(player.pokemon.at(player_pokemon), p, moveNum);
                if(p.getStat(0) <= 0){
                    p.setStat(0, 0);
                    cout << "The enemy pokemon has fainted!" << endl;

                    //Adding xp
                    player.pokemon.at(player_pokemon).setXp(player.pokemon.at(player_pokemon).getXp() + p.getLevel()*10);
                    cout << player.pokemon.at(player_pokemon).getName() << " gained " << p.getLevel()*10 << "XP!" << endl;

                    //Check if level up
                    if((player.pokemon).at(player_pokemon).getXp() > (player.pokemon).at(player_pokemon).getLevel() * 10){
                        (player.pokemon).at(player_pokemon).setXp((player.pokemon).at(player_pokemon).getXp() - ((player.pokemon).at(player_pokemon).getLevel() * 10));
                        (player.pokemon).at(player_pokemon).levelUp();
                        cout << player.pokemon.at(player_pokemon).getName() << " has leveled up to level " << player.pokemon.at(player_pokemon).getLevel() << "!" << endl;
                    }
                    return 2;
                }
                return 1;
            }
        }
        else if(reply == "2"){  
            valid = true;      
            int temp = chooseActive(player, player_pokemon);
            if(temp != -1){
                player_pokemon = temp;
            }
            else{
                return yourTurn(player, p, player_pokemon);
            }
        }
        //bag stuff
        else if(reply == "3"){
            valid = true;
            int ii = 1;
            cout << "Choose which item to use" << endl;
            for(Item thing : player.items){
                cout << ii << ". " << thing.getItemName() << "  " << thing.getNumber() << endl;
                ii++;
            }
            bool valid2 = false;
            int itemNum;
            while(!valid2){
                cin >> itemNum;
                if(itemNum > 0 && itemNum <= player.items.size()){
                    itemNum -= 1;
                    valid2 = true;
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
                if(j < .66*((.2 + p.getMaxStat(0) - p.getStat(0)) * (((double)player.pokemon.at(player_pokemon).getLevel())/p.getLevel()))){
                    for(int jj = 1; jj < 6; jj++){
                        p.setStat(jj, p.getMaxStat(jj));
                    }
                    player.addPokemon(p);
                    cout << "You have successfully caught " << p.getName() << endl;
                    return 3;
                }
                else{
                    cout << "Oh no! The wild pokemon broke free!" << endl;
                }
            }
            else if(player.items.at(itemNum).getItemName() == "Great Ball"){
                player.items.at(itemNum).decrement();
                j = ((double)rand())/RAND_MAX;
                if(j < .8*((.2 + p.getMaxStat(0) - p.getStat(0)) * (((double)player.pokemon.at(player_pokemon).getLevel())/p.getLevel()))){
                    for(int jj = 1; jj < 6; jj++){
                        p.setStat(jj, p.getMaxStat(jj));
                    }
                    player.addPokemon(p);
                    cout << "You have successfully caught " << p.getName() << endl;
                    return 3;
                }
                else{
                    cout << "Oh no! The wild pokemon broke free!" << endl;
                }
            }
            else if(player.items.at(itemNum).getItemName() == "Ultra Ball"){
                player.items.at(itemNum).decrement();
                j = ((double)rand())/RAND_MAX;
                if(j < .9*((.2 + p.getMaxStat(0) - p.getStat(0)) * (((double)player.pokemon.at(player_pokemon).getLevel())/p.getLevel()))){
                    for(int jj = 1; jj < 6; jj++){
                        p.setStat(jj, p.getMaxStat(jj));
                    }
                    player.addPokemon(p);
                    cout << "You have successfully caught " << p.getName() << endl;
                    return 3;
                }
                else{
                    cout << "Oh no! The wild pokemon broke free!" << endl;
                }
            }
            else if(player.items.at(itemNum).getItemName() == "Potion"){
                player.items.at(itemNum).decrement();
                player.pokemon.at(player_pokemon).modStat(0, 20);
            }
            else if(player.items.at(itemNum).getItemName() == "Super Potion"){
                player.items.at(itemNum).decrement();
                player.pokemon.at(player_pokemon).modStat(0, 50);
            }
            else if(player.items.at(itemNum).getItemName() == "Hyper Potion"){
                player.items.at(itemNum).decrement();
                player.pokemon.at(player_pokemon).modStat(0, 200);
            }
            else{
                cout << "Invalid item" << endl;
            }
            if(player.pokemon.at(player_pokemon).getStat(0) > player.pokemon.at(player_pokemon).getMaxStat(0)){
                player.pokemon.at(player_pokemon).setStat(0, player.pokemon.at(player_pokemon).getMaxStat(0));
                cout << endl << "Used the potion" << endl;
            }
        }
        //Run
        else if(reply == "4"){
            cout << "You have successfully escaped!" << endl;
            return 2;
        }
        else{
            cout << "Invalid response" << endl;
            return -1;
        }
    }
    return 0;
}

int enemyTurn(Pokemon &your_pokemon, Pokemon &p, int i){
    //srand((int)(i + your_pokemon.getIv(0) + p.getIv(0) + your_pokemon.getStat(0) + p.getStat(0)));
    cout << "Enemy's turn" << endl;
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
    attack(p, your_pokemon, moveNum);
    if(your_pokemon.getStat(0) <= 0){
        your_pokemon.setStat(0,0);
        cout << your_pokemon.getName() << " fainted!" << endl;
        return 2;
    }
    return 0;
}

//ENCOUNTER
int encounter(Trainer &player, Pokemon &p, int i){
    //srand(i+player.getSteps());
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
        int outcome = -1;
        while(outcome < 0){
            outcome = yourTurn(player, p, curr_pokemon);
        }
        if(outcome == 2 || outcome == 3){
            resolved = true;
        }
        else{
            int outcome;
            outcome = enemyTurn(player.pokemon.at(curr_pokemon), p, i);
            if(outcome == 2){
                int outcome2 = -1;
                outcome2 = chooseActive(player, curr_pokemon);
                if(outcome2 == -3){
                    cout << "All of your pokemon have fainted. You lose. Thanks for playing!" << endl;
                    return -3;
                }
                else if(outcome2 >= 0){
                    curr_pokemon = outcome2;
                }
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
    return 0;
}

int encounter(Trainer &player, Trainer &t, Tile &tile, int i){
    cout << "You have been challenged by " << t.getName() << "!" << endl;
    cout << "Number of pokemon: " << t.pokemon.size() << endl;
    //srand(i+player.getSteps());
    bool resolved = false;
    int player_pokemon;
    int trainer_pokemon = 0;
    cout << endl << t.getName() << " sent out " << t.pokemon.at(trainer_pokemon).getName() << "!" << endl;
    for(int ii = 0; ii < 6; ii++){
        if(player.getPokemonAt(ii).getStat(0) > 0){
            player_pokemon = ii;
            break;
        }
    }
    bool caused_faint = false;;
    while(!resolved){
        //cout << player.pokemon.at(player_pokemon).getStat(5) << " " << t.pokemon.at(trainer_pokemon).getStat(5) << endl;
        if(player.pokemon.at(player_pokemon).getStat(5) >= t.pokemon.at(trainer_pokemon).getStat(5)){
            int outcome = 1;
            caused_faint = false;
            outcome = yourTurn(player, t.pokemon.at(trainer_pokemon), player_pokemon);
            if(outcome == 2){
                caused_faint = true;
                int search = 0;
                for(Pokemon poke : t.pokemon){
                    if(poke.getStat(0) > 0){
                        trainer_pokemon = search;
                        cout << endl << t.getName() << " sent out " << t.pokemon.at(trainer_pokemon).getName() << "!" << endl;
                    }
                    search ++;
                }
                if(t.pokemon.at(trainer_pokemon).getStat(0) <= 0){
                    cout << "You have defeated " << t.getName() << "!" << endl;
                    int money = (600 + (1000*(double)rand())/RAND_MAX);
                    player.modMoney(money);
                    cout << "You gained " << money << " from winning!" << endl;
                    tile.setTerrain('.');
                    return 0;
                }
            }
            if(!caused_faint){
                outcome = enemyTurn(player.pokemon.at(player_pokemon), t.pokemon.at(trainer_pokemon), i);
                if(outcome == 2){
                    int temp;
                    temp = chooseActive(player, player_pokemon);
                    if(temp == -3){
                        cout << "All of your pokemon have fainted. You lose. Thanks for playing!" << endl;
                        return -3;
                    }
                    player_pokemon = temp;
                }
            }
        }
        else{
            int outcome;
            outcome = enemyTurn(player.pokemon.at(player_pokemon), t.pokemon.at(trainer_pokemon), i);
            if(outcome == 2){
                caused_faint = true;
                int temp;
                temp = chooseActive(player, player_pokemon);
                if(temp == -3){
                    cout << "All of your pokemon have fainted. You lose. Thanks for playing!" << endl;
                    return -3;
                }
                player_pokemon = temp;
            }
            if(!caused_faint){
                outcome = yourTurn(player, t.pokemon.at(trainer_pokemon), player_pokemon);
                if(outcome == 2){
                    int search = 0;
                    for(Pokemon poke : t.pokemon){
                        if(poke.getStat(0) > 0){
                            trainer_pokemon = search;
                            cout << endl << t.getName() << " sent out " << t.pokemon.at(trainer_pokemon).getName() << "!" << endl;
                        }
                        search ++;
                    }
                    if(t.pokemon.at(trainer_pokemon).getStat(0) <= 0){
                        cout << "You have defeated " << t.getName() << "!" << endl;
                        int money = (600 + (1000*(double)rand())/RAND_MAX);
                        player.modMoney(money);
                        cout << "You gained " << money << " from winning!" << endl;
                        tile.setTerrain('.');
                        return 2;
                    }
                }
            }
        }
    }
    return 0;
}

void bag(Trainer &player){
    string s2;
    string s1;
    int choice;
    int heal = 0;
    int ii = 1;
    for(Item i : player.items){
        cout << ii << ". " << i.getItemName() << ": " << i.getNumber() << endl;
        ii++;
    }
    cout << endl << "Type the number of an item to use it." << endl;
    cin >> s1;
    if(s1 == "1" || s1 == "2" || s1 == "3" || s1 == "4" || s1 == "5" || s1 == "6"){
        if((stoi(s1)-1) >= 0 && stoi(s1)-1 < player.items.size()){
            choice = stoi(s1)-1;
            if(player.items.at(choice).getItemName() == "Potion"){
                heal = 20;
            }
            else if(player.items.at(choice).getItemName() == "Super Potion"){
                heal = 50;
            }
            else if(player.items.at(choice).getItemName() == "Hyper Potion"){
                heal = 200;
            }

            if(heal > 0){
                cout << "Choose a pokemon to heal:" << endl;
                if(player.pokemon.size() < 6){
                    int jj = 1;
                    for(Pokemon p1 : player.pokemon){
                        cout << jj << ". " << p1.getName() << "  HP: " << p1.getStat(0) << "/" << p1.getMaxStat(0) << endl;
                        player.items.at(choice).decrement();
                        jj++;
                    }
                }
                else{
                    for(int jj = 1; jj < 7; jj++){
                        cout << jj << ". " << player.pokemon.at(jj).getName() << "  HP: " << player.pokemon.at(jj).getStat(0) << "/" << player.pokemon.at(jj).getMaxStat(0) << endl;
                    }
                }
                cin >> s2;
                if(s2 == "1" || s2 == "2" || s2 == "3" || s2 == "4" || s2 == "5" || s2 == "6"){
                    player.pokemon.at(stoi(s2)-1).modStat(0, heal);
                    if(player.pokemon.at(stoi(s2)-1).getStat(0) > player.pokemon.at(stoi(s2)-1).getMaxStat(0)){
                        player.pokemon.at(stoi(s2)-1).setStat(0 , player.pokemon.at(stoi(s2)-1).getMaxStat(0));
                    }
                }
                else{
                    cout << "Invalid pokemon" << endl;
                }
            }
        }
        else{
            cout << "Invalid item" << endl;
        }
    }
    else{
        cout << "Invalid response" << endl;
    }
    cout << endl;
}

void pokemanip(Trainer &player, bool atMart){
    cout << endl;
    if(atMart || player.pokemon.size() < 6){
        for(Pokemon p : player.pokemon){
            cout << "Name: " << p.getName() << endl;
            for(int ii = 0; ii < 2; ii++){
                cout << p.type[ii] << " ";
            }
            cout << endl;
            cout << "Level: " << p.getLevel() << endl;
            cout << "XP: " << p.getXp() << endl;
            cout << endl;
            cout << "HP, Attack, Defense, Special Attack, Special Defense, Speed" << endl;
            for(int ii = 0; ii < 6; ii++){
                cout << p.getStat(ii) << "/" << p.getMaxStat(ii) << endl;
            }
            cout << endl;
            cout << "IVs" <<endl;
            for(int jj = 0; jj < 6; jj++){
                cout << p.getIv(jj) << endl;
            }
            cout << endl;
            cout << "Moves" << endl;
            for(int kk = 0; kk < p.getNumMoves(); kk++){
                cout << p.getMove(kk).getMoveName() << "  Power: " << p.getMove(kk).getDamage() << endl;
            }
        }
    }
    else{
        for(int ii = 0; ii < 6; ii++){
            cout << "Name: " << player.pokemon.at(ii).getName() << endl;
            for(int ii = 0; ii < 2; ii++){
                cout << player.pokemon.at(ii).type[ii] << " ";
            }
            cout << endl;
            cout << "Level: " << player.pokemon.at(ii).getLevel() << endl;
            cout << "XP: " << player.pokemon.at(ii).getXp() << endl;
            cout << endl;
            cout << "HP, Attack, Defense, Special Attack, Special Defense, Speed" << endl;
            for(int ii = 0; ii < 6; ii++){
                cout << player.pokemon.at(ii).getStat(ii) << "/" << player.pokemon.at(ii).getMaxStat(ii) << endl;
            }
            cout << endl;
            cout << "IVs" <<endl;
            for(int jj = 0; jj < 6; jj++){
                cout << player.pokemon.at(ii).getIv(jj) << endl;
            }
            cout << endl;
            cout << "Moves" << endl;
            for(int kk = 0; kk < player.pokemon.at(ii).getNumMoves(); kk++){
                cout << player.pokemon.at(ii).getMove(kk).getMoveName() << "  Power: " << player.pokemon.at(ii).getMove(kk).getDamage() << endl;
            }
        }
    }
    cout << endl;
    cout << "Select a pokemon to move to the front of your party. Enter any invalid command to cancel." << endl;
    if(!atMart){
        if(player.pokemon.size() < 6){
            int jj = 0;
            for(Pokemon p : player.pokemon){
                cout << jj << ": " << p.getName() << "   " << p.getStat(0) << "/" << p.getMaxStat(0) << endl;
                jj++;
            }
        }
        else{
            for(int jj = 0; jj < 6; jj++){
                cout << jj << ": " << player.pokemon.at(jj).getName() << "   " << player.pokemon.at(jj).getStat(0) << "/" << player.pokemon.at(jj).getMaxStat(0) << endl;
            }
        }
        string swap;
        cin >> swap;
        if(swap == "1" || swap == "2" || swap == "3" || swap == "4" || swap == "5" || swap == "6"){
            if(stoi(swap)-1 < player.pokemon.size()){
                Pokemon placeholder = player.pokemon.at(stoi(swap)-1);
                player.pokemon.at(stoi(swap)-1) = player.pokemon.at(0);
                player.pokemon.at(0) = placeholder;
            }
        }
        cout << endl;
    }
    else{
        cout << "Type exit to quit" << endl;
        bool quit = false;
        while(!quit){
            int jj = 1;
            for(Pokemon p : player.pokemon){
                cout << jj << ": " << p.getName() << "   " << p.getStat(0) << "/" << p.getMaxStat(0) << endl;
                jj++;
            }
            string swap;
            cin >> swap;

            bool numExists = false;
            string c = "";
            for(int ii = 0; ii < swap.length(); ii++){
                if(swap[ii] == '0' || swap[ii] == '1' || swap[ii] == '2' || swap[ii] == '3' || swap[ii] == '4' || 
                swap[ii] == '5' || swap[ii] == '6' || swap[ii] == '7' || swap[ii] == '8' ||swap[ii] == '9' ){
                    numExists = true;
                    c += swap[ii];
                }
            }
            if(swap == "quit" || swap == "exit" || swap == "Quit" || swap =="Exit"){
                quit = true;
            }
            else if(numExists){
                int b = stoi(c);
                cout << b << endl;
                Pokemon placeholder = player.pokemon.at(b-1);
                player.pokemon.at(b-1) = player.pokemon.at(0);
                player.pokemon.at(0) = placeholder;
            }
            else{
                cout << "Invalid Response" << endl;
            }
            cout << endl;
        }
    }
}

//i just for passing into generate pokemon
/**
 * The loop which runs the player move cycle
 * Gets input from user
 * Checks to make sure the movement does not go off the map, if it doesn't calls the appropriate move player function
 * The move player function then returns if the movement is valid, along with the occurance of the tile
 * Resolve occurances
 */
int step(Trainer &player, vector<Trainer> &trainers, Map &map, int i){
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
        else if(s == "help" || s == "?"){
            cout << "use w/a/s/d to move. bag to look in bag. pokemon to see stats of your pokemon." << endl;
        }
        else if(s == "bag"){
            bag(player);
        }
        else if(s == "pokemon"){
            pokemanip(player, false);
            map.printMapAroundPlayer(player.getXPos(), player.getYPos(), trainers);
        }

        if(result == 1){
            map.printMapAroundPlayer(player.getXPos(), player.getYPos(), trainers);
        }
        else if(result == 2){
            Pokemon p = generatePokemon(player, player.getSteps()+player.pokemon.at(0).getXp());
            //encounter
            if(encounter(player, p, rand()) == -3){
                return -3;
            }
            map.printMapAroundPlayer(player.getXPos(), player.getYPos(), trainers);
        }
        else if(result == 3){
            cout << endl << "Your pokemon have been healed!" << endl;
            int kk = 0;
            for(Pokemon p : player.pokemon){
                for(int ii = 0; ii < 6; ii++){
                    if(p.getStat(ii) < p.getMaxStat(ii)){
                        p.setStat(ii, p.getMaxStat(ii));
                    }
                }
                player.pokemon.at(kk) = p;
                kk++;
            }

            pokemanip(player, true);
            cout << endl;
            map.printMapAroundPlayer(player.getXPos(), player.getYPos(), trainers);
        }
        else if(result == 4){
            int numBadges = player.getNumBadges();
            int gym_count;
            for(int ii = 0; ii < map.getMaxY(); ii++){
                for(int jj = 0; jj < map.getMaxX(); jj++){
                    if(map.tiles[ii][jj].getTerrain() == 'G'){
                        gym_count++;
                    }
                }
            }
            if(numBadges < 8 && numBadges < gym_count){
                vector<Trainer> gymTrainers;
                for(int ii = 0; ii < 3; ii++){
                    gymTrainers.push_back(Trainer());
                    gymTrainers.at(ii).setName("Gym assistant");
                    int numPokemon;
                    if(numBadges < 4){
                        numPokemon = 3;
                    }
                    else if(numBadges < 6){
                        numPokemon = 4;
                    }
                    else{
                        numPokemon = 5;
                    }
                    for(int jj = 0; jj < numPokemon; jj++){
                        gymTrainers.at(ii).addPokemon(generatePokemon(player, 0));
                    }
                }
                gymTrainers.push_back(Trainer());
                string name;
                string badge;
                switch(numBadges){
                    case 0:
                        gymTrainers.at(3).setName("Brock");
                        gymTrainers.at(3).addPokemon(Pokemon(95,12));
                        gymTrainers.at(3).addPokemon(Pokemon(75,14));
                        gymTrainers.at(3).addPokemon(Pokemon(111,14));
                        badge = "Boulder badge";
                        break;
                    case 1:
                        gymTrainers.at(3).setName("Misty");
                        gymTrainers.at(3).addPokemon(Pokemon(61,17));
                        gymTrainers.at(3).addPokemon(Pokemon(120,19));
                        gymTrainers.at(3).addPokemon(Pokemon(73,21));
                        gymTrainers.at(3).addPokemon(Pokemon(86,19));
                        badge = "Cascade badge";
                        break;
                    case 2:
                        gymTrainers.at(3).setName("Lt. Surge");
                        gymTrainers.at(3).addPokemon(Pokemon(26,24));
                        gymTrainers.at(3).addPokemon(Pokemon(25,20));
                        gymTrainers.at(3).addPokemon(Pokemon(82,25));
                        gymTrainers.at(3).addPokemon(Pokemon(101,24));
                        badge = "Thunder badge";
                        break;
                    case 3:
                        gymTrainers.at(3).setName("Erika");
                        gymTrainers.at(3).addPokemon(Pokemon(44, 28));
                        gymTrainers.at(3).addPokemon(Pokemon(46,28));
                        gymTrainers.at(3).addPokemon(Pokemon(2,30));
                        gymTrainers.at(3).addPokemon(Pokemon(71,30));
                        gymTrainers.at(3).addPokemon(Pokemon(103,28));
                        badge = "Rainbow badge";
                        break;
                    case 4:
                        gymTrainers.at(3).setName("Koga");
                        gymTrainers.at(3).addPokemon(Pokemon(89,32));
                        gymTrainers.at(3).addPokemon(Pokemon(94,36));
                        gymTrainers.at(3).addPokemon(Pokemon(42,33));
                        gymTrainers.at(3).addPokemon(Pokemon(49,34));
                        gymTrainers.at(3).addPokemon(Pokemon(24,35));
                        badge = "Soul badge";
                        break;
                    case 5:
                        gymTrainers.at(3).setName("Sabrina");
                        gymTrainers.at(3).addPokemon(Pokemon(65, 39));
                        gymTrainers.at(3).addPokemon(Pokemon(80, 36));
                        gymTrainers.at(3).addPokemon(Pokemon(97,37));
                        gymTrainers.at(3).addPokemon(Pokemon(103,38));
                        gymTrainers.at(3).addPokemon(Pokemon(124,37));
                        badge = "Marsh badge";
                        break;
                    case 6:
                        gymTrainers.at(3).setName("Blaine");
                        gymTrainers.at(3).addPokemon(Pokemon(78, 40));
                        gymTrainers.at(3).addPokemon(Pokemon(38,42));
                        gymTrainers.at(3).addPokemon(Pokemon(59,42));
                        gymTrainers.at(3).addPokemon(Pokemon(6, 43));
                        gymTrainers.at(3).addPokemon(Pokemon(126, 40));
                        gymTrainers.at(3).addPokemon(Pokemon(136,41));
                        badge = "Volcano badge";
                        break;
                    case 7:
                        gymTrainers.at(3).setName("Giovanni");
                        gymTrainers.at(3).addPokemon(Pokemon(28,45));
                        gymTrainers.at(3).addPokemon(Pokemon(51,45));
                        gymTrainers.at(3).addPokemon(Pokemon(76,47));
                        gymTrainers.at(3).addPokemon(Pokemon(105,46));
                        gymTrainers.at(3).addPokemon(Pokemon(112,48));
                        gymTrainers.at(3).addPokemon(Pokemon(34,49));
                        badge = "Earth badge";
                        break;
                    default:
                        cout << "???" << endl;
                }
                int outcome;
                Tile tile = Tile();
                for(int jj = 0; jj < 4; jj++){
                    outcome = encounter(player, gymTrainers.at(jj), tile, 0);
                    if(outcome == -3){
                        return outcome;
                    }
                    bag(player);
                    pokemanip(player, false);
                }
                player.addBadge(badge);
                cout << player.getName() << " recieved the " << badge << " from " << gymTrainers.at(3).getName() << "!" << endl;
                map.tiles[player.getYPos()][player.getXPos()].setCompleted();
                map.printMapAroundPlayer(player.getXPos(), player.getYPos(), trainers);
            }

            // else{
            //     cout << "You have beaten all the gyms. Now for your toughest challenge yet, the Elite Four!" << endl;
            //     vector<Trainer> elitefour;
            //     Trainer t1 = Trainer();
            //     t1.setName("Elite Four Lorelei");
            //     t1.addPokemon(Pokemon(87, 55));
            //     t1.addPokemon(Pokemon(91,55));
            //     t1.addPokemon(Pokemon(80,55));
            //     t1.addPokemon(Pokemon(124,55));
            //     t1.addPokemon(Pokemon(131,57));
            //     elitefour.push_back(t1);
            //     Trainer t2 = Trainer();
            //     t2.setName("Elite Four Bruno");
            //     t2.addPokemon(Pokemon(95, 55));
            //     t2.addPokemon(Pokemon(106,55));
            //     t2.addPokemon(Pokemon(107,55));
            //     t2.addPokemon(Pokemon(95,55));
            //     t2.addPokemon(Pokemon(68,57));
            //     elitefour.push_back(t2);
            //     Trainer t3 = Trainer();
            //     t3.setName("Elite Four Agatha");
            //     t3.addPokemon(Pokemon(94, 57));
            //     t3.addPokemon(Pokemon(42,57));
            //     t3.addPokemon(Pokemon(24,57));
            //     t3.addPokemon(Pokemon(93,57));
            //     t3.addPokemon(Pokemon(94,59));
            //     elitefour.push_back(t3);
            //     Trainer t4 = Trainer();
            //     t4.setName("Elite Four Lance");
            //     t4.addPokemon(Pokemon(130, 58));
            //     t4.addPokemon(Pokemon(148,58));
            //     t4.addPokemon(Pokemon(142,58));
            //     t4.addPokemon(Pokemon(148,58));
            //     t4.addPokemon(Pokemon(149,60));
            //     elitefour.push_back(t4);
            //     Trainer theChamp = Trainer();
            //     theChamp.setName("Champion Blue");
            //     theChamp.addPokemon(Pokemon(18,61));
            //     theChamp.addPokemon(Pokemon(65,61));
            //     theChamp.addPokemon(Pokemon(112,61));
            //     theChamp.addPokemon(Pokemon(103,61));
            //     theChamp.addPokemon(Pokemon(130,63));
            //     theChamp.addPokemon(Pokemon(6,65));
            //     elitefour.push_back(theChamp);

            //     int outcome;
            //     Tile tile = Tile();
            //     for(int jj = 0; jj<5; jj++){
            //         outcome = encounter(player, elitefour.at(jj), tile, 0);
            //         if(outcome == -3){
            //             return -3;
            //         }
            //         bag(player);
            //         pokemanip(player, false);
            //     }
            //     cout << "Congratulations! You have emerged victorious and became the Indigo League Champion!" << endl;
            //     cout << "You win!" << endl;
            //     return 9001;
            // }
        }
        else if(result == 5){
            //mart things
        }
        else if(result == 6){
            for(Trainer t : trainers){
                if(t.getXPos() - player.getXPos() >= -1 && t.getXPos() - player.getXPos() <= 1 && t.getYPos() - player.getYPos() >= -1 && t.getYPos() - player.getYPos() <= 1){
                    int outcome;
                    outcome = encounter(player, t, map.tiles[t.getYPos()][t.getXPos()],0);
                    if(outcome == -3){
                        return -3;
                    }
                    break;
                }
            }
        }
    }
    return 0;
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

    for(int ii = 0; ii < size*10; ii++){
        //Number of pokemon between 1 and 4
        int numPokemon = (int)(3*((double)rand())/RAND_MAX) + 1;
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
            int random = rand();
            cout << random << endl;
            trainers.at(ii).addPokemon(generatePokemon(player, random));
        }
    }

    map.printMapAroundPlayer(player.getXPos(), player.getYPos(), trainers);

    bool quit = false;
    int outcome;
    while(!quit){
        outcome = step(player, trainers, map, rand());
        if(outcome == -3){
            quit = true;
        }
        else if(outcome == 9001){
            cout << endl;
            cout << "Game written by Nick Lumiere for his computer science project :P" << endl;
            cout << "Pokemon by Game Freak" << endl;
            string hi;
            cin >> hi;
            cout << "Thanks for spending way too much time on this game, you flatter me." << endl;
            quit = true;
        }
    }

    return 0;
}

/**
 * Marts
 * Supereffective
 * Evolution
 * Fix bug where game ends when only 1 pokemon faints
 */