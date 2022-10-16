#include "Battleship.h"

void welcome_screen()
{
	printf("*****WELCOME TO BATTLESHIP*****\n");
	printf("Rules of Battleship:\n");
	printf("1. This is a two player game.\n2. You are player1 and the computer is player2.\n3. Both players will place 5 ships on the gameboard: 1 carrier (5 spaces), 1 battleship (4 spaces), 1 cruiser (3 spaces), 1 submarine (3 spaces), and 1 destroyer (2 spaces)\n4. Ships cannot be placed diagonally\n5. Ships cannot overlap\n6. You and the computer will take turns guessing where the other players ship is\n7. When a ship is sunk, it will be announced\n8. The first player to sink all of their opponents ships is declared the winner\n");
	printf("Hit enter to start the game");
	char enter = '\0';
	do
	{
		enter = getchar();
	} while (enter != '\n');
	system("cls");
}

void initialize_game_board(char board[MAX_ROWS][MAX_COLS])
{
	for (int row_index = 0; row_index < MAX_ROWS; row_index++) //rows
	{
		for (int col_index = 0; col_index < MAX_COLS; col_index++) //cols
		{
			board[row_index][col_index] = '-';
		}
	}
}

int select_who_starts_first()
{
	return rand() % 2; //0 for player 1, 1 for player 2
}

void manually_place_ships_on_board(char board[MAX_ROWS][MAX_COLS])
{
	int row1 = 0, row2 = 0, row3 = 0, row4 = 0, row5 = 0,
		col1 = 0, col2 = 0, col3 = 0, col4 = 0, col5 = 0;

	//carrier placement
	printf("Please enter the five cells to place the Carrier across\n");
	do
	{
		scanf(" %d%d%d%d%d%d%d%d%d%d", &row1, &col1, &row2, &col2, &row3, &col3, &row4, &col4, &row5, &col5);
		
		if ( !(((row1 == row2 && row1 == row3 && row1 == row4 && row1 == row5) || (col1 == col2 && col1 == col3 && col1 == col4 && col1 == col5)) && (row1 >= 0 || row1 <= 9 || col1 >= 0 || col1 <= 9)) && !(check_occupied(board, row1,col1) && check_occupied(board, row2, col2) && check_occupied(board, row3, col3) && check_occupied(board, row4, col4) && check_occupied(board, row5, col5)))
		{
			printf("Invalid placement, Enter five new cells\n");
		}

	} while ( !(((row1 == row2 && row1 == row3 && row1 == row4 && row1 == row5) || (col1 == col2 && col1 == col3 && col1 == col4 && col1 == col5)) && (row1 >= 0 || row1 <= 9 || col1 >= 0 || col1 <= 9)) && !(check_occupied(board, row1, col1) && check_occupied(board, row2, col2) && check_occupied(board, row3, col3) && check_occupied(board, row4, col4) && check_occupied(board, row5, col5)));

	//CHANGE GAME BOARD HERE
	board[row1][col1] = 'c';
	board[row2][col2] = 'c';
	board[row3][col3] = 'c';
	board[row4][col4] = 'c';
	board[row5][col5] = 'c';
	

	//battleship placement
	printf("Please enter the four cells to place the Battleship across\n");
	do
	{
		scanf(" %d%d%d%d%d%d%d%d", &row1, &col1, &row2, &col2, &row3, &col3, &row4, &col4);
		if (!(((row1 == row2 && row1 == row3 && row1 == row4) || (col1 == col2 && col1 == col3 && col1 == col4)) && (row1 >= 0 || row1 <= 9 || col1 >= 0 || col1 <= 9)) && !(check_occupied(board, row1, col1) && check_occupied(board, row2, col2) && check_occupied(board, row3, col3) && check_occupied(board, row4, col4)))
		{
			printf("Invalid placement, Enter four new cells\n");
		}

	} while (!(((row1 == row2 && row1 == row3 && row1 == row4) || (col1 == col2 && col1 == col3 && col1 == col4)) && (row1 >= 0 || row1 <= 9 || col1 >= 0 || col1 <= 9)) && !(check_occupied(board, row1, col1) && check_occupied(board, row2, col2) && check_occupied(board, row3, col3) && check_occupied(board, row4, col4)));

	//CHANGE GAME BOARD HERE
	board[row1][col1] = 'b';
	board[row2][col2] = 'b';
	board[row3][col3] = 'b';
	board[row4][col4] = 'b';
	
	//cruiser placement
	printf("Please enter the three cells to place the Cruiser across\n");
	do
	{
		scanf(" %d%d%d%d%d%d", &row1, &col1, &row2, &col2, &row3, &col3);
		if (!(((row1 == row2 && row1 == row3) || (col1 == col2 && col1 == col3)) && (row1 >= 0 || row1 <= 9 || col1 >= 0 || col1 <= 9)) && !(check_occupied(board, row1, col1) && !(check_occupied(board, row2, col2) && check_occupied(board, row3, col3))))
		{
			printf("Invalid placement, Enter three new cells\n");
		}

	} while (!(((row1 == row2 && row1 == row3) || (col1 == col2 && col1 == col3)) && (row1 >= 0 || row1 <= 9 || col1 >= 0 || col1 <= 9)) && !(check_occupied(board, row1, col1) && !(check_occupied(board, row2, col2) && check_occupied(board, row3, col3))));

	//CHANGE GAME BOARD HERE
	board[row1][col1] = 'r';
	board[row2][col2] = 'r';
	board[row3][col3] = 'r';

	//submarine placement
	printf("Please enter the three cells to place the Submarine across\n");
	do
	{
		scanf(" %d%d%d%d%d%d", &row1, &col1, &row2, &col2, &row3, &col3);
		if (!(((row1 == row2 && row1 == row3) || (col1 == col2 && col1 == col3)) && (row1 >= 0 || row1 <= 9 || col1 >= 0 || col1 <= 9)) && !(check_occupied(board, row1, col1) && !(check_occupied(board, row2, col2) && check_occupied(board, row3, col3))))
		{
			printf("Invalid placement, Enter three new cells\n");
		}

	} while (!(((row1 == row2 && row1 == row3) || (col1 == col2 && col1 == col3)) && (row1 >= 0 || row1 <= 9 || col1 >= 0 || col1 <= 9)) && !(check_occupied(board, row1, col1) && !(check_occupied(board, row2, col2) && check_occupied(board, row3, col3))));

	//CHANGE GAME BOARD HERE
	board[row1][col1] = 's';
	board[row2][col2] = 's';
	board[row3][col3] = 's';

	//destroyer placement
	printf("Please enter the three cells to place the Destroyer across\n");
	do
	{
		scanf(" %d%d%d%d", &row1, &col1, &row2, &col2);
		if (!(((row1 == row2) || (col1 == col2)) && (row1 >= 0 || row1 <= 9 || col1 >= 0 || col1 <= 9)) && !(check_occupied(board, row1, col1) && !(check_occupied(board, row2, col2))))
		{
			printf("Invalid placement, Enter two new cells\n");
		}

	} while (!(((row1 == row2) || (col1 == col2)) && (row1 >= 0 || row1 <= 9 || col1 >= 0 || col1 <= 9)) && !(check_occupied(board, row1, col1) && !(check_occupied(board, row2, col2))));

	//CHANGE GAME BOARD HERE
	board[row1][col1] = 'd';
	board[row2][col2] = 'd';
} 

void randomly_place_ships_on_board(char board[MAX_ROWS][MAX_COLS])
{
	int horizontal = rand() % 2,       // 1 for horizontal and 0 for vertical
		start_row = 0, start_col = 0, occupied = 0;

	//carrier placement
	if (horizontal == 0) //vertical
	{
		do
		{
			start_row = rand() % 6; 
			start_col = rand() % 10;
			occupied = 0;
			for (int i = 0; i < 5; i++)
			{
				if (check_occupied(board, start_row + i, start_col))
				{
					occupied = 1;
				}
			}
		} while (occupied);

		//CHANGE GAME BOARD HERE
		for (int i = 0; i < 5; i++)
		{
			board[start_row+i][start_col] = 'c';
		}
	}
	else if (horizontal == 1) //horizontal
	{
		
		do 
		{
			start_row = rand() % 10;
			start_col = rand() % 6;
			occupied = 0;
			for (int i = 0; i < 5; i++)
			{
				if (check_occupied(board, start_row, start_col + i))
				{
					occupied = 1;
				}
			}
		} while (occupied);

		//CHANGE GAME BOARD HERE
		for (int i = 0; i < 5; i++)
		{
			board[start_row][start_col + i] = 'c';
		}
	}

	//battleship placement
	horizontal = rand() % 2;
	if (horizontal == 0) //vertical
	{
		
		do
		{
			start_row = rand() % 7;
			start_col = rand() % 10;
			occupied = 0;
			for (int i = 0; i < 4; i++)
			{
				if (check_occupied(board, start_row + i, start_col))
				{
					occupied = 1;
				}
			}
		} while (occupied);

		//CHANGE GAME BOARD HERE
		for (int i = 0; i < 4; i++)
		{
			board[start_row+i][start_col] = 'b';
		}
	}
	else if (horizontal == 1) //horizontal
	{
		do
		{
			start_row = rand() % 10;
			start_col = rand() % 7;
			occupied = 0;
			for (int i = 0; i < 4; i++)
			{
				if (check_occupied(board, start_row, start_col + i))
				{
					occupied = 1;
				}
			}
		} while (occupied);
		
		//CHANGE GAME BOARD HERE
		for (int i = 0; i < 4; i++)
		{
			board[start_row][start_col + i] = 'b';
		}
	}

	//cruiser placement
	horizontal = rand() % 2;
	if (horizontal == 0) //vertical
	{
		
		do
		{
			start_row = rand() % 8;
			start_col = rand() % 10;
			occupied = 0;
			for (int i = 0; i < 3; i++)
			{
				if (check_occupied(board, start_row + i, start_col))
				{
					occupied = 1;
				}
			}
		} while (occupied);

		//CHANGE GAME BOARD HERE
		for (int i = 0; i < 3; i++)
		{
			board[start_row+i][start_col] = 'r';
		}
	}
	else if (horizontal == 1) //horizontal
	{

		do
		{
			start_row = rand() % 10;
			start_col = rand() % 8;
			occupied = 0;
			for (int i = 0; i < 3; i++)
			{
				if (check_occupied(board, start_row, start_col + i))
				{
					occupied = 1;
				}
			}
		} while (occupied);
		//CHANGE GAME BOARD HERE
		for (int i = 0; i < 3; i++)
		{
			board[start_row][start_col + i] = 'r';
		}
	}

	//submarine placement
	horizontal = rand() % 2;
	if (horizontal == 0) //vertical
	{

		do
		{
			start_row = rand() % 8;
			start_col = rand() % 10;
			occupied = 0;
			for (int i = 0; i < 3; i++)
			{
				if (check_occupied(board, start_row + i, start_col))
				{
					occupied = 1;
				}
			}
		} while (occupied);

		//CHANGE GAME BOARD HERE
		for (int i = 0; i < 3; i++)
		{
			board[start_row + i][start_col] = 's';
		}
	}
	else if (horizontal == 1) //horizontal
	{

		do
		{
			start_row = rand() % 10;
			start_col = rand() % 8;
			occupied = 0;
			for (int i = 0; i < 3; i++)
			{
				if (check_occupied(board, start_row, start_col + i))
				{
					occupied = 1;
				}
			}
		} while (occupied);
		
		//CHANGE GAME BOARD HERE
		for (int i = 0; i < 3; i++)
		{
			board[start_row][start_col + i] = 's';
		}
	}

	//destroyer placement
	horizontal = rand() % 2;
	if (horizontal == 0) //vertical
	{
		do
		{
			start_row = rand() % 9;
			start_col = rand() % 10;
			occupied = 0;
			for (int i = 0; i < 2; i++)
			{
				if (check_occupied(board, start_row + i, start_col))
				{
					occupied = 1;
				}
			}
		} while (occupied);

		//CHANGE GAME BOARD HERE
		for (int i = 0; i < 2; i++)
		{
			board[start_row + i][start_col] = 'd';
		}
	}
	else if (horizontal == 1) //horizontal
	{
		do
		{
			start_row = rand() % 10;
			start_col = rand() % 9;
			occupied = 0;
			for (int i = 0; i < 2; i++)
			{
				if (check_occupied(board, start_row, start_col + i))
				{
					occupied = 1;
				}
			}
		} while (occupied);

		//CHANGE GAME BOARD HERE
		for (int i = 0; i < 2; i++)
		{
			board[start_row][start_col + i] = 'd';
		}
	}
}

int check_shot(char board[MAX_ROWS][MAX_COLS], int row, int col)
{
	int hit = 0;
	if (board[row][col] != '-')
	{
		hit = 1;
	}
	return hit;
}

int is_winner(char board[MAX_ROWS][MAX_COLS])
{
	int win = 1;
	for (int row = 0; row < MAX_ROWS; row++)
	{
		for (int col = 0; col < MAX_COLS; col++)
		{
			if ((board[row][col] != '*') && (board[row][col] != 'm') && (board[row][col] != '-')) //if each place on the board is not hit, miss or empty, there is no winner(ships are still present)
			{
				win = 0;
				row = MAX_ROWS;
				col = MAX_COLS;
			}
		}
	}

	return win;
}

void update_board(char board[MAX_ROWS][MAX_COLS], int change_row, int change_col, int hit)
{
	if (hit)
	{
		board[change_row][change_col] = '*';
	}
	else
	{
		board[change_row][change_col] = 'm';
	}
}

void display_board(char board[MAX_ROWS][MAX_COLS])
{
	printf("    0   1   2   3   4   5   6   7   8   9\n");
	for (int row_index = 0; row_index < MAX_ROWS; row_index++) //rows
	{
		printf("%d ", row_index);
		for (int col_index = 0; col_index < MAX_COLS; col_index++) //columns
		{
			printf("| %c ", board[row_index][col_index]);
		}
		printf("|\n");
	}
}

void output_current_move(FILE *output, int row, int col, int hit, int sunk)
{
	fprintf(output, "(%d,%d) , ", row, col);
	if (hit == 0)
	{
		fprintf(output, "miss, ");
	}
	else if (hit == 1)
	{
		fprintf(output, "hit, ");
	}

	if (sunk = 0)
	{
		fprintf(output, "not sunk\n");
	}
	else if (sunk == 1)
	{
		fprintf(output, "sunk\n");
	}
}

void check_if_sunk_ship(Ships *s, char c)
{
	if (s->carrier == 0 && c == 'c')
	{
		printf("Carrier has been sunk!");
	}
	else if (s->battleship == 0 && c == 'b')
	{
		printf("Battleship has been sunk!");
	}
	else if (s->cruiser == 0 && c == 'r')
	{
		printf("Cruiser has been sunk!");
	}
	else if (s->submarine == 0 && c == 's')
	{
		printf("Submarine has been sunk!");
	}
	else if (s->destroyer == 0 && c == 'd')
	{
		printf("Destroyer has been sunk!");
	}
}

void output_stats(FILE *output, int winner)
{
	fprintf(output, "Player %d wins", winner);
}

int check_occupied(char board[MAX_ROWS][MAX_COLS], int row, int col)
{
	int occupied = 0;
		if (board[row][col] != '-')
		{
			occupied = 1;
		}
	
	return occupied; //returns 0(false) if not occupied and 1(true) if occupied
}

void initalize_ships(Ships* s)
{
	s->carrier = 5;
	s->battleship = 4;
	s->cruiser = 3;
	s->submarine = 3;
	s->destroyer = 2;
}

void update_ships(Ships* s, char c)
{
	if (c == 'c')
	{
		(s->carrier)--;
	}
	else if (c == 'b')
	{
		(s->battleship)--;
	}
	else if (c == 'r')
	{
		(s->cruiser)--;
	}
	else if (c == 's')
	{
		(s->submarine)--;
	}
	else if (c == 'd')
	{
		(s->destroyer)--;
	}
}