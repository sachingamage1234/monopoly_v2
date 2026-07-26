#ifndef GAME_H
#define GAME_H

#include "types.h"

void sort_players(player players[], int size);
int dice_roll(void);
void initial_dice_roll();
int buy_property(player *player, property *property, int auction_price);
int pay_rent(player *player, property *property);

#endif