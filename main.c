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

        for(int i = 0; i < 10; i++){

            for(int j = 0; j < 4; j++){

            //roll the dice and move the player
            players[j].dice_value = dice_roll();

            printf("%s rolled %d \n", players[j].name, players[j].dice_value);

            int old_position = players[j].position;
            move_player(&players[j], players[j].dice_value);
            printf("%s moves from Square %d to Square %d \n", players[j].name, old_position, players[j].position);

            if(strcmp(players[j].name, "Aggresive Invester") == 0){
                aggresive_trader_decision(&players[j], &(board[players[j].position]));
                printf("\n\n");
            }
            else if(strcmp(players[j].name, "Conservative Banker") == 0){
                conservative_banker_decision(&players[j], &(board[players[j].position]));
                printf("\n\n");
            }
            else if(strcmp(players[j].name, "Risk Taker") == 0){
                risk_taker_decision(&players[j], &(board[players[j].position]));
                printf("\n\n");
            }
            else{
                opportunistic_trader_decision(&players[j], &(board[players[j].position]));
                printf("\n\n");
            }

            }
        }
     
    

    return 0;                            
}

