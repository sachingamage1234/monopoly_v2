#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

int add_property_to_list(player* player, property *property){
    if(player->no_of_properties > 10){
        printf("Trying to buy an invalid property\n");
        return 0;
    }

    player->properties[player->no_of_properties] = property;

    printf("Added the property to the list successfully\n");
    return 1;
}

void add_color_group(player *player, property *property){
    for(int i=0; i < 8; i++){
        if(strcmp(property->color, player->player_color_list[i].color) == 0){
            player->player_color_list[i].no_of_properties += 1;
        }
    }
}

int buy_property(player *player, property *property, int auction_price){
    if(auction_price == 0){
        if(player->vault > property->purchace_price){
            player->vault -= property->purchace_price;
            property->owner.player = player;
            property->owned = 1;

            add_property_to_list(player, property);
            add_color_group(player, property);

            printf("Purchased a property\n");
            return 1;
        }
        else
        {
            printf("SalliMadi\n");
            return 0;
        }
    }
    else{
        if(player->vault > auction_price + 250){
            return 1;
        }
        else{
            return 0;
        }
    }
}

int pay_rent(player *player, property *property){
    if(!(property->mortaged)){
        int rent = property->base_rental;
        player->vault -= rent;
        property->owner.player->vault += rent;
        printf("Rent ekk gewwa\n");
        return 0;
    }
    else{
        printf("No need to pay the rent because the property is mortaged\n");
        return 1;
    }
    
}

int pay_income_tax(player *player){
    int total_property_value = 0;

    for(int i = 0; i < player->no_of_properties; i++){
        total_property_value += player->properties[i]->purchace_price;
    }

    //Since the data type of the players vault is int the final answer will also be int
    player->vault -= total_property_value * income_tax_rate;
    printf("Payed income tax of %f\n", total_property_value);

}
int check_monopoly(player *player){
    for(int i = 0; i < 8 ; i++){
        if(player->player_color_list[i].no_of_properties == color_list[i].no_of_properties){
            printf("Player %s has a monopoly in the color of %s\n", player->name, color_list[i].color);
        }
    }
}


int build_houses(player *player, property *property){
    player->vault -= property->house_construction_cost;
    property -> no_of_buildings += 1;
    printf("Built a house");
}

int bid(property *property){
    int bid_finished = 0;

    printf("Bidding Started fo the property %s\n", property->name);

    player top_bidder;

    while(!bid_finished){

        int bid_refusals = 0;
        int current_top_bid = 0;

        for(int i=0; i < sizeof(players)/sizeof(players[0]); i++){

            if(strcmp(players[i].name,"Aggresive Invester") == 0){
                if(buy_property(&players[i], property, current_top_bid) == 1){
                    bid_finished=1;
                    printf("Aggresive Invester has won the auction\n");
                }
                else{
                    bid_refusals++;
                }
            }

            else if(strcmp(players[i].name,"Conservative Banker") == 0){
                if(players[i].vault - property->purchace_price >= players[i].vault / 2){
                    if(buy_property(&players[i], property, current_top_bid)){
                        bid_finished = 1;
                        printf("Conservative Banker has won the auction\n");
                    }
                    else{
                        bid_refusals++;
                    }
            }
            }
            else if(strcmp(players[i].name,"Risk Taker") == 0){
                if(buy_property(&players[i], property, current_top_bid) == 1){
                    bid_finished = 1;
                    printf("Risk Taker has won the auction\n");
                }
                else{
                    bid_refusals++;
                }
            }
            else{
                if(buy_property(&players[i], property, current_top_bid) == 1){
                    bid_finished = 1;
                    printf("Opportunistic Trader has won the auction\n");
                }
                else{
                    bid_refusals++;
                }
            }
        }

        if(bid_refusals == 4){
            bid_finished = 1;
            printf("No one got the property\n");
        }
    }
}
