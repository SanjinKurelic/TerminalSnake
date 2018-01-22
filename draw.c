#include "draw.h"

void draw_player_statistics(Player player, int life_lost){
	printf("\nPlayer: %s\n", player.name);
	printf("Life lost: %d\n", life_lost);
	printf("Coins collected: %d\n", player.max_coin_score);
}

void draw_statistics()
{
	printf("\n");
	if(player1.life_score > player2.life_score){
		printf("Player '%s' wins!", player1.name);
	} else if(player1.life_score < player2.life_score){
		printf("Player '%s' wins!", player2.name);
	} else{
		printf("Both players have same result");
	}
	printf("\nStatistics:\n");
	draw_player_statistics(player1, player2.life_score);
	draw_player_statistics(player2, player1.life_score);
	printf("\n");
}

void draw_result(Result result)
{
	int input = 0;
	switch(result){
		case DRAW:
			puts("It is draw");
			break;
		case PLAYER1_WINS:
			puts("Player 1 wins");
			break;
		case PLAYER2_WINS:
			puts("Player 2 wins");
			break;
	}

	puts("Press 'c' to continue..");
	while(input != 'c'){
		input = get_key();
	}
}

short draw_player(Player player, int column, int row){
	int i;
	for(i = 0; i <= player.coin_score; i++){
		if(player.tail[i].x == column && player.tail[i].y == row){
			return 1;
		}
	}
	return 0;
}

void draw_field(int column, int row)
{
	/* Draw wall */
	short column_end = (column == 0) || (column == (MAX_COLUMN - 1));
	if(row == 0 || (row == (MAX_ROW - 1) && !column_end)){
		printf("_");
	}
	else if(column_end){
		printf("|");
	}

	/* Draw players */
	else if(draw_player(player1, column, row)){
		printf(RED_COLOR "x" END_COLOR);
	} else if(draw_player(player2, column, row)){
		printf(BLUE_COLOR "x" END_COLOR);
	}

	/* Draw elements */
	else if((coin.point.x == column) && (coin.point.y == row)){
		if(coin.add_to_score == 5){
			printf(MAGENTA_COLOR);
		} else{
			printf(YELLOW_COLOR);
		}
		printf("*" END_COLOR);
	}

	/* Draw empty field */
	else {
		printf(" ");
	}
}

void draw_result_bar(){
	int index = 0;
	int start = (MAX_COLUMN / 3 - MAX_GAMES) / 2;
	int end = start + MAX_GAMES;
	int player1_score_end = player1.life_score + start;
	int player2_score_start = MAX_GAMES - player2.life_score + start;

	// center bar
	for(; index < start - 1; index++){
		printf("   ");
	}

	// better aligment
	index += 2; // aligment
	if(player1.max_coin_score < 10){
		printf(" ");
	}
	// draw coins left player
	printf(YELLOW_COLOR " *" END_COLOR "%d ", player1.max_coin_score);

	// draw bar
	for(;index <= end; index++){
		if(index <= player1_score_end){
			printf(RED_BACK "  ");
		}
		else if(index <= player2_score_start){
			printf(WHITE_BACK "  ");
		}
		else{
			printf(BLUE_BACK "  ");
		}
		printf(END_BACK " ");
	}

	// draw coins right player
	printf("%d" YELLOW_COLOR "*" END_COLOR, player2.max_coin_score);

	// Add new line
	printf("\n");
}

void draw_menu()
{
	printf(RED_COLOR "%s (W,A,S,D)" END_COLOR,
		player1.name);
	printf(" vs ");
	printf(BLUE_COLOR "%s (I,J,K,L)" END_COLOR,
		player2.name);

	printf("\n\n");
	draw_result_bar();
}

void draw_board()
{
	int row, column;
	for(row = 0; row < MAX_ROW; row++)
	{
		for(column = 0; column < MAX_COLUMN; column++)
		{
			draw_field(column, row);
		}
		printf("\n");
	}
	printf("\n");
}

void draw(){
	system("clear");
	draw_menu();
	draw_board();
}
