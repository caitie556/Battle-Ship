#include "Battleship.h"

int main(void)
{
	srand(time(0));
	int choice = 0, turn = -1, target_row = 0, target_col = 0, winner = -1;
	char c = '\0', current_space = '\0';
	char player1_board[MAX_ROWS][MAX_COLS] = { {'\0'} };
	char player2_board[MAX_ROWS][MAX_COLS] = { {'\0'} };
	char player2_known[MAX_ROWS][MAX_COLS] = { {'\0'} };
	Ships p1, p2;
	FILE *outfile = fopen("battleship.log", "w");
	initialize_game_board(player1_board);
	initialize_game_board(player2_board);
	initialize_game_board(player2_known);
	initalize_ships(&p1);
	initalize_ships(&p2);


	welcome_screen();
	printf("Select from the menu:\n1. Enter positions manually.\n2. Allow the program to randomly select positions of ships\n");
	do
	{
		scanf("%d", &choice);
	} while (choice < 1 || choice > 2);
	
	if (choice == 1)
	{
		manually_place_ships_on_board(player1_board);
	}
	else if (choice == 2)
	{
		randomly_place_ships_on_board(player1_board);
	}

	randomly_place_ships_on_board(player2_board);
	printf("Player2's (Computer's) board has been generated.\n");
	turn = select_who_starts_first();
	if (turn == 0)
	{
		printf("Player 1 has been randomly selected to go first.\n");
	}
	else if (turn == 1)
	{
		printf("Player 2 has been randomly selected to go first.\n");
	}
	
	while (turn != -1)
	{
		printf("Player 1's board:\n");
		display_board(player1_board);
		printf("Player 2's board:\n");
		display_board(player2_known);

		if (turn == 0) //player 1
		{
			do
			{
				printf("Enter a target: ");
				scanf("%d%d", &target_row, &target_col);
				if (target_row > 9 || target_col > 9 || target_row < 0 || target_col < 0)
				{
					printf("Invalid target\n");
				}
			} while (target_row > 9 || target_col > 9 || target_row < 0 || target_col < 0);

			system("cls");
			if (check_shot(player2_board, target_row, target_col))
			{
				printf("%d,%d is a hit!\n", target_row, target_col);
				current_space = player2_board[target_row][target_col];
				update_ships(&p2, current_space);
				check_if_sunk_ship(&p2, current_space);
				update_board(player2_known, target_row, target_col, 1);
				update_board(player2_board, target_row, target_col, 1);
			}
			else
			{
				printf("%d, %d is a miss!\n", target_row, target_col);
				update_board(player2_known, target_row, target_col, 0);
				update_board(player2_board, target_row, target_col, 0);
			}

			printf("Hit enter to continue");
			do
			{
				c = getchar();
			} while (c != '\n');

			if (is_winner(player2_board)) //checks to determine if there is a winner
			{
				printf("PLAYER 1 HAS WON THE GAME!");
				winner = 1;
				turn = -1;
			}
			else //changes to player 2's turn
			{
				turn = 1;
			}

			system("cls");

		}
		else if (turn == 1) //player 2(computer)
		{
			target_row = rand() % 10;
			target_col = rand() % 10;
			printf("Player selects: %d, %d\n", target_row, target_col);

			if (check_shot(player1_board, target_row, target_col))
			{
				printf("%d,%d is a hit!\n", target_row, target_col);
				current_space = player1_board[target_row][target_col];
				check_if_sunk_ship(&p1, current_space);
				update_ships(&p1, current_space);
				update_board(player1_board, target_row, target_col, 1);
			}
			else
			{
				printf("%d,%d is a miss!\n", target_row, target_col);
				update_board(player1_board, target_row, target_col, 0);
			}

			printf("Hit enter to continue");
			do
			{
				c = getchar();
			} while (c != '\n');

			if (is_winner(player1_board)) //checks to determine if there is a winner
			{
				printf("PLAYER 2 HAS WON THE GAME!");
				winner = 2;
				turn = -1;
			}
			else //changes to player 1's turn
			{
				turn = 0;
			}

			system("cls");
		}
		c = '\0';
	}

	output_stats(outfile, winner);
	fclose(outfile);
	return 0;
}