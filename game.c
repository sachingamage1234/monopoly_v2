#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

#include "game.h"
#include "types.h"
#include "players.h"
#include "board.h"

//Get the sum of the 2 dice values
int dice_roll(void){
    int dice1 = (rand() % 6) + 1;
    int dice2 = (rand() % 6 ) + 1;
    return dice1 + dice2;
}

void initial_dice_roll(){
    for(int i = 0; i < 4; i++){
        int initial_dice_value = dice_roll();
        printf("%s rolls %d\n", players[i].name, initial_dice_value);
        players[i].dice_value = initial_dice_value;
        players[i].vault = 30000;
        players[i].position = 0;
    }
}

//Sort players starting from the maximum dice value player
void sort_players(player players[], int size){

    //sort the array of players according to their dice value
    //for(int i = 1; i <= (size-1); i++){
      //  for(int j = 0; j < (size-i); j++){
        //    if(players[j].dice_value < players[j+1].dice_value){
          //  player temp = players[j];
            //players[j] = players[j+1];
    //        players[j+1] = temp;
      //      }
        //}
   // }


    //Finds the index of the maximum dice value
    int max = 0;
    int max_index = 0;
    int max_counts = 0;

    for(int i = 0; i < size; i++){
        if(players[i].dice_value > max){
            max = players[i].dice_value;
            max_index = i;
        }
    }


    //creae a new array of players and arrange it in the correct order
    player ordered_players[size];
    for(int i = 0; i < size; i++){
        if(i==0){
            ordered_players[i] = players[max_index];
        }
        
        if(max_index + i > size -1){
            ordered_players[i] = players[(max_index + i) - size];
        }
        else{
            ordered_players[i] = players[max_index + i];
        }
        
    }

    for(int i = 0; i < size-1; i++){
        if(ordered_players[i].dice_value == max){
            max_counts++;
        }
    }

    printf("\n %s will start the game \n\n", players[0]);

    //get the players with the same max
    //COMPLETE THIS SHIT
    player temp_maxes[max_counts];
    if(max_counts > 1){
        printf("\nThere is a tie between %d players with the same dice value of %d\n\n", max_counts+1, max);
        for(int i = 0; i < size; i++){
            if(ordered_players[i].dice_value == max){
                temp_maxes[i] = ordered_players[i];
            }
        }
    }

    

    //copy the order from the second array to the original array
    for(int i = 0; i < size; i++){
        players[i] = ordered_players[i];
    }

    printf("Turn Order:\n");

    for(int i = 0; i < size; i++){
        printf("%s \n", players[i].name);
        players[i].position = 0;
    }

}

int buy_property(player *player, property *property, int auction_price){
    if(auction_price == 0){
            if(player->vault > property->purchace_price){
                player->vault -= property->purchace_price;
                property->owner.player = player;
                property->owned = 1;
                printf("Purchased a property\n");
                return 1;
            }
            else
            {
                printf("SalliMadi\n");
                return 0;
            }
        }
}


int start_auction(property *property, player players[]){
    int starting_bidding_value = property->purchace_price;

    while(1){
        int bid_refusal_times;

        for(int i = 0; i<4; i++){
            if(strcmp(players[i].name, "Aggresive Invester") == 0){
                //Check if the player buys the property
                if(aggresive_trader_decision(&players[i], &(board[players[i].position])) == 1){
                    return 0;
                }
                else{
                    bid_refusal_times++;
                }
                
            }
            else if(strcmp(players[i].name, "Conservative Banker") == 0){
                if(conservative_banker_decision(&players[i], &(board[players[i].position])) == 1){
                    return 0;
                }
                else{
                    bid_refusal_times++;
                }
            }
            else if(strcmp(players[i].name, "Risk Taker") == 0){
                if(risk_taker_decision(&players[i], &(board[players[i].position])) == 1){
                    return 0;
                }
                else{
                    bid_refusal_times++;
                }
            }
            else{
                if(opportunistic_trader_decision(&players[i], &(board[players[i].position])) == 1){
                    return 0;
                }
                else{
                    bid_refusal_times++;
                }
            }

            if(bid_refusal_times == 4){
                printf("No one bought the property\n");
                return 0;
            }
        }
    }
}