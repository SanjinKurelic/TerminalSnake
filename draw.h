#ifndef DRAW_H_
#define DRAW_H_

#include "main.h"

void draw();
void draw_menu_player(Player player);
void draw_menu();
void draw_board();
void draw_field(int column, int row);
short draw_player(Player player, int column, int row);
void draw_result_bar();
void draw_result(Result result);
void draw_statistics();
void draw_player_statistics(Player player, int life_lost);

#endif // DRAW_H_
