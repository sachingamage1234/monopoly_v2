#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "types.h"

//Initialize players 
player players[4] = {
    {"Aggresive Invester", 1000, 0, 0, 4},
    {"Conservative Banker", 1000, 0, 0, 6},
    {"Risk Taker", 1000, 0, 0, 12},
    {"Opportunistic Trader", 1000, 0, 0, 8}
};

int aggresive_trader_decision(player *player, cell *cell){

    printf("Aggresive Trader decision!\n");

    //Fiest Priority to property buying
    //Have to implement more
    if(strcmp(cell->type, "Property") == 0){
        if(!(cell->ptr.property->owned)){
            if(player->vault > cell->ptr.property->purchace_price){
                player->vault -= cell->ptr.property->purchace_price;
                cell->ptr.property->owner.player = player;
                cell->ptr.property->owned = 1;
                printf("Purchased a property\n");
                return 1;
            }
            else
            {
                start_auction(&cell->ptr.property, players);
                return 0;
            }
            printf("Aithikarayek innawalu\n");
        }
    }
    else{
         printf("Property ekk nemei kiyala kiyanawa\n");
    }
}


int conservative_banker_decision(player *player, cell *cell){
    printf("Conservative Banker decision!\n");

    if(strcmp(cell->type, "Property") == 0){
        if(!(cell->ptr.property->owned)){
            if(player->vault - cell->ptr.property->purchace_price >= player->vault / 2){
                player->vault -= cell->ptr.property->purchace_price;
                cell->ptr.property->owner.player = player;
                cell->ptr.property->owned = 1;
                printf("Purchased a property\n");
            }
            else
            {
                printf("SalliMadi\n");
            }
        }
        printf("Aithikarayek innawalu\n");
    }
    else{
         printf("Property ekk nemei kiyala kiyanawa\n");
    }
}

int risk_taker_decision(player *player, cell *cell){
    printf("Risk Taker decision!\n");

    if(strcmp(cell->type, "Property") == 0){
        if(!(cell->ptr.property->owned)){
            return buy_property(player, cell->ptr.property, 0);
        }
    }
    else{
         printf("Property ekk nemei kiyala kiyanawa\n");
    }
}

int opportunistic_trader_decision(){
    printf("Opportunistic Trader decision!\n");

    printf("Muu thama implement keranna amarui\n");
}
