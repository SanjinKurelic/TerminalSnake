#include "main.h"

int main(){
	int input;
	int end = MAX_GAMES / 2;
	short show_statistics = 1;
    Result result;

	// Initialization
	initialize_players();
	generate_coin();
	draw();
	// Game loop
	while((player1.life_score <= end) && (player2.life_score <= end))
	{
		input = get_key();
		// If key is ESC or CTRL^D
		if(input == 0x1B || input == 0x04){
			show_statistics = 0;
			break;
		}
		// If key is ASCII
		if(input > 0x20 && input < 0x7F){
			parse_key(input);
		}
		// Animate field and check coin collect
		usleep(PLAYER_SPEED);
		collect_coin();
		move_tail(&player1);
		move_tail(&player2);
		draw();
		if((result = calculate_collider()) != NONE){
            draw_result(result);
		    reset_players();
		    generate_coin();
        }
	}

	/* show statistics */
	if(show_statistics == 1){
		draw();
		draw_statistics();
	}
	return 0;
}
