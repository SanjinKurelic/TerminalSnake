#ifndef PLAYER_H_
#define PLAYER_H_

#include "main.h"

Player player1, player2;

void add_tail_child(Player *player);
void move_tail(Player *player);
void move_player(Player *player, int x, int y);
void move_player_up(Player *player);
void move_player_bottom(Player *player);
void move_player_right(Player *player);
void move_player_left(Player *player);
void enter_player_name(Player *player, char *default_name);
void reset_player(Player *player, Point position, Point move_to);
void reset_players();
void initialize_players();

#endif
