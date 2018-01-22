#include "player.h"

void add_tail_child(Player *player){
	int score = (*player).coin_score;
	Point *p_last, p_before;
	p_last = &((*player).tail[score]);
	p_before = (*player).tail[score - 1];

	(*p_last).x = p_before.x;
	(*p_last).y = p_before.y;
}

void move_tail(Player *player){
	int i = (*player).coin_score;
	for(; i > 0; i--){
		(*player).tail[i].x = (*player).tail[i-1].x;
		(*player).tail[i].y = (*player).tail[i-1].y;
	}
	(*player).tail[0].x += (*player).move_x;
	(*player).tail[0].y += (*player).move_y;
}

void move_player(Player *player, int x, int y){
	if(x != 0 && (*player).move_x == -x){
		return;
	} else if(y != 0 && (*player).move_y == -y){
		return;
	}
	(*player).move_x = x;
	(*player).move_y = y;
}

void move_player_up(Player *player){
    move_player(player, 0, -1);
}

void move_player_bottom(Player *player){
    move_player(player, 0, 1);
}

void move_player_right(Player *player){
    move_player(player, 1, 0);
}

void move_player_left(Player *player){
    move_player(player, -1, 0);
}

void reset_player(Player *player, Point position, Point move_to){
	(*player).tail = malloc(TAIL_SIZE * sizeof(Point));
	(*player).tail[0].x = position.x;
	(*player).tail[0].y = position.y;
	(*player).move_x = move_to.x;
	(*player).move_y = move_to.y;
	(*player).coin_score = 0;
}

void reset_players(){
	Point position, move_to;

	position.x = 1;
	position.y = 1;

	move_to.x = 1;
	move_to.y = 0;

	reset_player(&player1, position, move_to);

	position.x = MAX_COLUMN - 2;
	position.y = MAX_ROW - 2;

	move_to.x = -1;
	move_to.y = 0;

	reset_player(&player2, position, move_to);
}

void initialize_players(){
	reset_players();

	player1.mark = 'A';
	player1.max_coin_score = 0;
	player1.life_score = 0;

	enter_player_name(&player1, "Player 1");

	player2.mark = 'B';
	player1.max_coin_score = 0;
	player1.life_score = 0;

	enter_player_name(&player2, "Player 2");
}

