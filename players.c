#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "types.h"
#include "game.h"
#include "board.h"

//Initialize players 
player players[4] = {
    {"Aggresive Invester", 1000, 0, 0, 4, 
    {{"Brown", 0},
    {"LightBlue", 0},
    {"Pink", 0},
    {"Orange", 0},
    {"Red", 0},
    {"Yellow", 0},
    {"Green", 0},
    {"DarkBlue", 0}}},

    {"Conservative Banker", 1000, 0, 0, 6,
    {{"Brown", 0},
    {"LightBlue", 0},
    {"Pink", 0},
    {"Orange", 0},
    {"Red", 0},
    {"Yellow", 0},
    {"Green", 0},
    {"DarkBlue", 0}}},

    {"Risk Taker", 1000, 0, 0, 12,
    {{"Brown", 0},
    {"LightBlue", 0},
    {"Pink", 0},
    {"Orange", 0},
    {"Red", 0},
    {"Yellow", 0},
    {"Green", 0},
    {"DarkBlue", 0}}},

    {"Opportunistic Trader", 1000, 0, 0, 8,
    {{"Brown", 0},
    {"LightBlue", 0},
    {"Pink", 0},
    {"Orange", 0},
    {"Red", 0},
    {"Yellow", 0},
    {"Green", 0},
    {"DarkBlue", 0}}}
};


//prioratize purchasing properties
int aggresive_trader_decision(player *player, cell *cell, int auction_price){

    printf("Aggresive Trader decision!\n");

    //First Priority to property buying
    //Have to implement more
    if(strcmp(cell->type, "Property") == 0){
        if(!(cell->ptr.property->owned)){
            buy_property(player, cell->ptr.property, 0, 1);
        }
        else{

             if(cell->ptr.property->owner.player == player){
                build_houses(player, cell->ptr.property);
                return 1;
            }

            pay_rent(player, cell->ptr.property);
        }

    }else if (strcmp(cell->type, "Insurance") == 0) {
    // Code for Insurance cell
    } 
    else if (strcmp(cell->type, "Tax") == 0) {
         pay_income_tax(player);
    } 
    else if (strcmp(cell->type, "Bank") == 0) {
    // Code for Insurance cell
    } 
    else if (strcmp(cell->type, "Event") == 0) {
        // Code for Tax cell
    } 
    else if (strcmp(cell->type, "Utility") == 0) {
        
    }
    else if (strcmp(cell->type, "Insurance") == 0) {
    // Code for Insurance cell
    } 
    else if (strcmp(cell->type, "Railway") == 0) {
        // Code for Tax cell
    } 
    else if (strcmp(cell->type, "Special") == 0) {
        if(strcmp(cell -> name,"Go To Jail") == 0){
            player->position = 10;
            player->jailed = 1;
            printf("PLayer conservative banker was jailed\n");
        }
    }
    
}



int conservative_banker_decision(player *player, cell *cell){
    printf("Conservative Banker decision!\n");

    if(strcmp(cell->type, "Property") == 0){
        if(!(cell->ptr.property->owned)){
            if(player->vault - cell->ptr.property->purchace_price >= player->vault / 2){
                buy_property(player, cell->ptr.property, 0, 1);
                printf("Property ekk gatta\n");
            }
            else
            {
                printf("SalliMadi\n");
            }
        }
        else{

            if(cell->ptr.property->owner.player == player){
                build_houses(player, cell->ptr.property);
                return 1;
            }

            pay_rent(player, cell->ptr.property);
        }
    }

    else if (strcmp(cell->type, "Insurance") == 0) {
    // Code for Insurance cell
    } 
    else if (strcmp(cell->type, "Tax") == 0) {
        pay_income_tax(player);
    } 
    else if (strcmp(cell->type, "Bank") == 0) {
    // Code for Insurance cell
    } 
    else if (strcmp(cell->type, "Event") == 0) {
        // Code for Tax cell
    } 
    else if (strcmp(cell->type, "Utility") == 0) {
        // Code for Jail cell
    }
    else if (strcmp(cell->type, "Insurance") == 0) {
    // Code for Insurance cell
    } 
    else if (strcmp(cell->type, "Railway") == 0) {
        // Code for Tax cell
    } 
    else if (strcmp(cell->type, "Special") == 0) {
        if(strcmp(cell -> name,"Go To Jail") == 0){
            player->position = 10;
            player->jailed = 1;
            printf("PLayer conservative banker was jailed\n");
        }
    }
}

int risk_taker_decision(player *player, cell *cell){
    printf("Risk Taker decision!\n");

    if(strcmp(cell->type, "Property") == 0){
        if(!(cell->ptr.property->owned)){
            return buy_property(player, cell->ptr.property, 0, 1);
        }
        else{

            if(cell->ptr.property->owner.player == player){
                build_houses(player, cell->ptr.property);
                return 1;
            }
            pay_rent(player, cell->ptr.property);
            return 0;
        }
    }

    else if (strcmp(cell->type, "Insurance") == 0) {
    // Code for Insurance cell
    } 
    else if (strcmp(cell->type, "Tax") == 0) {
         pay_income_tax(player);
    } 
    else if (strcmp(cell->type, "Bank") == 0) {
        printf("Prrioratize getting loan\n");
    } 
    else if (strcmp(cell->type, "Event") == 0) {
        // Code for Tax cell
    } 
    else if (strcmp(cell->type, "Utility") == 0) {
        // Code for Jail cell
    }
    else if (strcmp(cell->type, "Insurance") == 0) {
    // Code for Insurance cell
    } 
    else if (strcmp(cell->type, "Railway") == 0) {
        // Code for Tax cell
    } 
    else if (strcmp(cell->type, "Special") == 0) {
        if(strcmp(cell -> name,"Go To Jail") == 0){
            player->position = 10;
            player->jailed = 1;
            printf("PLayer risk taker was jailed\n");
        }
    }
}

int opportunistic_trader_decision(){
    printf("Opportunistic Trader decision!\n");

    printf("Muu thama implement keranna amarui\n");
}
