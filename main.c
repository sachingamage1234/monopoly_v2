#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#include "types.h"
#include "game.h"
#include "players.h"
#include "board.h"


int main(){ 

    printf("%d\n\n\n\n", strcmp(board[1].type, "Property"));
    srand(time(NULL));

    printf("MONOPOLY-LK\n\n");

    for(int i = 0; i<4; i++){
        printf("Player %d : %s\n", i+1, players[i].name);
    }

    printf("\n");
    printf("Each player starts with Rs.30000\n\n");

    initial_dice_roll();
    
    sort_players(players, 4);

    int no_of_rounds = 0;

        printf("\n");

        for(int i = 0; i < 4; i++){

            //roll the dice and move the player
            players[i].dice_value = dice_roll();

            printf("%s rolled %d \n", players[i].name, players[i].dice_value);

            int old_position = players[i].position;
            move_player(&players[i], players[i].dice_value);
            printf("%s moves from Square %d to Square %d \n", players[i].name, old_position, players[i].position);

            if(strcmp(players[i].name, "Aggresive Invester") == 0){
                aggresive_trader_decision(&players[i], &(board[players[i].position]));
                printf("\n\n");
            }
            else if(strcmp(players[i].name, "Conservative Banker") == 0){
                conservative_banker_decision(&players[i], &(board[players[i].position]));
                printf("\n\n");
            }
            else if(strcmp(players[i].name, "Risk Taker") == 0){
                risk_taker_decision(&players[i], &(board[players[i].position]));
                printf("\n\n");
            }
            else{
                opportunistic_trader_decision(&players[i], &(board[players[i].position]));
                printf("\n\n");
            }
        }
     
    

    return 0;                            
}

