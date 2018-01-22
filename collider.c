#include "collider.h"

short calculate_wall_hit(Player player){
	if(player.tail[0].x >= MAX_COLUMN - 1
	|| player.tail[0].x <= 0
	|| player.tail[0].y >= MAX_ROW - 1
	|| player.tail[0].y <= 0){
		return 1;
	}
	return 0;
}

short calculate_tail_hit(Player p1, Player p2){
	int i = 0;
	int head_x = p1.tail[0].x;
	int head_y = p1.tail[0].y;

	if(p1.mark == p2.mark){
		i = 1;
	}

	for(; i <= p2.coin_score; i++){
		if(p2.tail[i].x == head_x && p2.tail[i].y == head_y){
			return 1;
		}
	}
	return 0;
}

short player_collide(Player player, Player toPlayer){
    return calculate_wall_hit(player)
			|| calculate_tail_hit(player, toPlayer)
			|| calculate_tail_hit(player, player);
}

Result calculate_collider(){
	Result result = NONE;
	short player1_lose = player_collide(player1, player2);
	short player2_lose = player_collide(player2, player1);


	// Check if it is draw
	if(player1_lose && player2_lose){
		player1.life_score += 1;
		player2.life_score += 1;
		result = DRAW;
	}
	// Calculate wall and tail hit for both player
	else if(player2_lose){
		player1.life_score += 1;
		result = PLAYER1_WINS;
	}
	else if(player1_lose){
		result = PLAYER2_WINS;
		player2.life_score += 1;
	}

    return result;
}

short coin_collider(Player *player){
	short flag = 0;
	int i, j = (*player).coin_score;
	for(i = 0; i <= j; i++){
		if((*player).tail[i].x == coin.point.x
		&& (*player).tail[i].y == coin.point.y){			
			return 1;
		}
	}
	return 0;
}
