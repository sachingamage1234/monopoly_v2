#ifndef BOARD_H
#define BOARD_H

#include "types.h"

extern cell board[40];
int move_player(player* player, int steps);
extern float income_tax_rate;
extern color_groups color_list[8];

#endif