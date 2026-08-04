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


   int max = 0;
int max_index = 0;
int max_count = 0;
int max_value_positions[size]; // Use variable size to avoid out-of-bounds

for(int i = 0; i < size; i++){
    max_value_positions[i] = i; // Initialize positions
    if(players[i].dice_value > max){
        max = players[i].dice_value;
    }
}

// Eliminate players who didn't reach the initial highest roll
for(int i = 0; i < size; i++){
    if(players[i].dice_value == max){
        max_count++;
    } else {
        max_value_positions[i] = -1;
    }
}

// If there was a tie, re-roll ONLY among tied candidates
while(max_count > 1){
    printf("\nTie detected! Re-rolling for tied players...\n");
    
    // Step 1: Re-roll for active candidates
    for(int i = 0; i < size; i++){
        if(max_value_positions[i] != -1){
            players[i].dice_value = dice_roll();
            printf("%s rerolled %d\n", players[i].name, players[i].dice_value);
        }
    }

    // Step 2: Find the new highest roll among active candidates
    int temp_max = -1;
    for(int i = 0; i < size; i++){
        if(max_value_positions[i] != -1 && players[i].dice_value > temp_max){
            temp_max = players[i].dice_value;
        }
    }

    // Step 3: Eliminate candidates below temp_max and count remaining ties
    max_count = 0;
    for(int i = 0; i < size; i++){
        if(max_value_positions[i] != -1){
            if(players[i].dice_value == temp_max){
                max_count++;
            } else {
                max_value_positions[i] = -1; // Eliminate
            }
        }
    }
}

// Find the single winning index
for(int i = 0; i < size; i++){
    if(max_value_positions[i] != -1){
        max_index = i;
        break;
    }
}

// Rotate players array so the winner goes first
player sorted_players[size];
for(int i = 0; i < size; i++){
    sorted_players[i] = players[(max_index + i) % size];
}    

for(int i = 0; i < size; i++){
    players[i] = sorted_players[i];
}

printf("\n\nThe order of the players is as follows:\n");
for(int i = 0; i < size; i++){
    printf("%d. %s\n", i+1, players[i].name);
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

int buy_property(player *player, property *property, int auction_price, int just_looking){
    if(auction_price == 0){
            player->vault -= property->purchace_price;
            property->owner.player = player;
            property->owned = 1;

            add_property_to_list(player, property);
            add_color_group(player, property);

            printf("%s purched %s for Rs.%d\n", player->name, property->name, property->purchace_price);
            printf("Remaining balance: %d\n", player->vault);
            return 1;
        
    }
    else{
        if(just_looking){
            if(player->vault >= auction_price + 250){
                return 1;
            }
            else{
                return 0;
            }
        }
        else{
            player->vault -= auction_price;
            property->owner.player = player;
            add_color_group(player, property);
            property->owned = 1;
            add_property_to_list(player, property);
            printf("%s purched %s for Rs.%d\n", player->name, property->name, property->purchace_price);
            printf("Remaining balance: %d\n", player->vault);
            }
        }
        
    }


int buy_utility(player *player, utility *utility){
    player->vault -= utility->purchace_price;
    utility->owner = player;
    utility->owned = 1;
    player->no_of_utilities++;
}

int buy_railway(player *player, railway *railway){
    player->vault -= railway->purchace_price;
    railway->owner = player;
    railway->owned = 1;
    player->no_of_railways++;
}

int pay_rent(player *player, property *property){
    if(!(property->mortaged)){
        int rent = property->base_rental;
        player->vault -= rent;
        property->owner.player->vault += rent;
        printf("Player %s landed on %s\n", player->name, property->name);
        printf("Rent payed: Rs.%d\n", rent);
        printf("Owner: %s\n", property->owner.player->name);
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
    printf("Player %s built a house on %s\n", player->name, property->name);
    printf("Construction cost: Rs.%d\n", property->house_construction_cost);
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
                if(buy_property(&players[i], property, current_top_bid, 1) == 1){
                    bid_finished=1;
                    buy_property(&players[i], property, current_top_bid, 0);
                    printf("Aggresive Invester has won the auction\n");
                }
                else{
                    bid_refusals++;
                }
            }

            else if(strcmp(players[i].name,"Conservative Banker") == 0){
                if(players[i].vault - property->purchace_price >= players[i].vault / 2){
                    if(buy_property(&players[i], property, current_top_bid, 1)){
                        buy_property(&players[i], property, current_top_bid, 0);
                        bid_finished = 1;
                        printf("Conservative Banker has won the auction\n");
                    }
                    else{
                        bid_refusals++;
                    }
            }
            }
            else if(strcmp(players[i].name,"Risk Taker") == 0){
                if(buy_property(&players[i], property, current_top_bid, 1) == 1){
                    buy_property(&players[i], property, current_top_bid, 0);
                    bid_finished = 1;
                    printf("Risk Taker has won the auction\n");
                }
                else{
                    bid_refusals++;
                }
            }
            else{
                if(buy_property(&players[i], property, current_top_bid, 1) == 1){
                    buy_property(&players[i], property, current_top_bid, 0);
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
