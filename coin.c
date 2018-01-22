#include "coin.h"

void generate_coin(){
	int add_to_score;
	static int coin_occurance = COIN_5_OCCURANCE;

	// Define type of coin
	srand((unsigned)time(NULL));
	add_to_score = rand() % COIN_5_LIMIT;
	coin.add_to_score = (add_to_score < coin_occurance) ? 5 : 1;
	if(coin.add_to_score == 1){
		coin_occurance += COIN_5_OCCURANCE / 2;
	} else {
		coin_occurance = COIN_5_OCCURANCE;
	}

	srand((unsigned)time(NULL));
	coin.point.x = 1 + rand() % (MAX_COLUMN - 3);
	srand((unsigned)time(NULL));
	coin.point.y = 1 + rand() % (MAX_ROW - 3);
}

void add_coin_tail_score(Player *player){
    (*player).coin_score += coin.add_to_score;
    (*player).max_coin_score += coin.add_to_score;
    add_tail_child(player);
}

void collect_coin(){
    short collected = 0;

    // First player
    if(coin_collider(&player1) == 1){
        add_coin_tail_score(&player1);		
        collected = 1;
    }

    // Second player
    if(coin_collider(&player2) == 1){
        add_coin_tail_score(&player2);		
        collected = 1;
    }
	
    // Generate new coin if coin was collected
	if(collected > 0){
		generate_coin();
	}
}
