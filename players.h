#ifndef PLAYERS_H
#define PLAYERS_H

#include "types.h"

extern player players[4];
int aggresive_trader_decision();
int conservative_banker_decision();
int risk_taker_decision();
int opportunistic_trader_decision();

#endif