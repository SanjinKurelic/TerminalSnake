#ifndef COIN_H_
#define COIN_H_

#include "main.h"

typedef struct Coin{
	Point point;
	short add_to_score;
} Coin;

// Init
Coin coin;

void generate_coin();
void add_coin_score(Player *player);
void collect_coin();

#endif //COIN_H_
