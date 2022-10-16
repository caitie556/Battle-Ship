#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX_ROWS 10
#define MAX_COLS 10

typedef struct SHIPS
{
	int carrier, battleship, cruiser, submarine, destroyer;
}Ships;

void welcome_screen();
void initialize_game_board(char board[MAX_ROWS][MAX_COLS]);
int select_who_starts_first();
void manually_place_ships_on_board(char board[MAX_ROWS][MAX_COLS]);
void randomly_place_ships_on_board(char board[MAX_ROWS][MAX_COLS]);
int check_shot(char board[MAX_ROWS][MAX_COLS], int row, int col);
int is_winner(char board[MAX_ROWS][MAX_COLS]);
void update_board(char board[MAX_ROWS][MAX_COLS], int chang_row, int change_col, int hit);
void display_board(char board[MAX_ROWS][MAX_COLS]);
void output_current_move(FILE *output, int row, int col, int hit, int sunk);
void check_if_sunk_ship(Ships *s, char c);
void output_stats(FILE *output, int winner);
int check_occupied(char board[MAX_ROWS][MAX_COLS], int row, int col);
void initalize_ships(Ships *s);
void update_ships(Ships* s, char c);