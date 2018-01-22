#include "keyboard.h"

void parse_key(int input)
{
	switch(input)
	{
		case 'w':
            move_player_up(&player1);
			break;
		case 'a':
            move_player_left(&player1);
			break;
		case 's':
            move_player_bottom(&player1);
			break;
		case 'd':
            move_player_right(&player1);
			break;
		case 'i':
            move_player_up(&player2);
			break;
		case 'j':
            move_player_left(&player2);
			break;
		case 'k':
            move_player_bottom(&player2);
			break;
		case 'l':
            move_player_right(&player2);
			break;
	}
}

void enter_player_name(Player *player, char *default_name){
	printf("Enter player name [%s] (8 character max): ", default_name);

	// Get input from user
	fgets((*player).name, 10, stdin);

	// Clear stdin
	if(!strchr((*player).name, '\n')){
		char c;
		while((c = getchar()) != '\n' && c != EOF);
	}

	(*player).name[strlen((*player).name) - 1] = '\0';
	if(strlen((*player).name) == 0){
		strcpy((*player).name, default_name);
	}
}

int get_key(){
	int key;
	struct termios orig_term_attr;
	struct termios new_term_attr;

	tcgetattr(fileno(stdin), &orig_term_attr);
	memcpy(&new_term_attr, &orig_term_attr, sizeof(struct termios));
	new_term_attr.c_lflag &= ~(ECHO|ICANON);
	new_term_attr.c_cc[VTIME] = 0;
	new_term_attr.c_cc[VMIN] = 0;
	tcsetattr(fileno(stdin), TCSANOW, &new_term_attr);

	key = fgetc(stdin);

	tcsetattr(fileno(stdin), TCSANOW, &orig_term_attr);
	return key;
}

