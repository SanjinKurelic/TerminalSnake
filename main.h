#ifndef INC_H_
#define INC_H_

#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<termios.h>
#include<time.h>
#include<string.h>

/**
* Game constants
*/

#define MAX_ROW 20
#define MAX_COLUMN 40
#define PLAYER_SPEED 400000
#define FPS 1000
#define TAIL_SIZE 10
#define MAX_GAMES 10
#define COIN_5_LIMIT 1000
#define COIN_5_OCCURANCE 10

#define END_COLOR "\x1B[0m"
#define RED_COLOR "\x1B[31m"
#define BLUE_COLOR "\x1B[34m"
#define YELLOW_COLOR "\x1B[33m"
#define MAGENTA_COLOR "\x1B[35m"

#define END_BACK "\x1B[0m"
#define RED_BACK "\x1B[41m"
#define BLUE_BACK "\x1B[44m"
#define WHITE_BACK "\x1B[47m"

/**
* Structures
*/

typedef struct Point{
	int x;
	int y;
} Point;

typedef struct Player{
	Point *tail;
	short move_x;
	short move_y;
	int coin_score;
	int max_coin_score;
	int life_score;
	char name[10];
	char mark;
} Player;

typedef enum Result { NONE, DRAW, PLAYER1_WINS, PLAYER2_WINS } Result;

// Includes
#include "player.h"
#include "coin.h"
#include "keyboard.h"
#include "draw.h"
#include "collider.h"

#endif //INC_H_
