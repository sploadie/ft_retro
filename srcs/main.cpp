/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sraccah <sraccah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/06 20:50:12 by sraccah           #+#    #+#             */
/*   Updated: 2015/11/06 23:18:04 by sraccah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/main.hpp"

static void		print_data(int row, int col)
{
	int 		i;

	i = 0;
	// Draw a limit for data display
	move(LINES-2, 0);
	while (i++ < COLS)
		printw("-");
	// Moving just above the end of the screen
	move(LINES-1, 0);
	attron(COLOR_PAIR(1));
	attron(A_BOLD);
	// Display player position just above the bottom of the screen
	printw("Player pos = ");
	attron(COLOR_PAIR(4));
	printw("%d", row);
	attron(COLOR_PAIR(1));
	printw(" - ");
	attron(COLOR_PAIR(4));
	printw("%d", col);
	// Display the score just above the end of the screen in the middle of COLS
	move(LINES-1, (COLS/2)-5);
	attron(COLOR_PAIR(3));
	printw("Health = 100");
	move(LINES-1, COLS-10);
	attron(COLOR_PAIR(2));
	printw("Score = 0");
	attroff(A_BOLD);
	attroff(COLOR_PAIR(2));
}

static void		game_loop(Character car, int ch)
{
	// Setting the symbol and position of the character
	char 		player = car.getSymbol();
	int 		row = car.getRow();
	int 		col = car.getCol();
	// Check if player want to quit the game
	if (ch == 'q' || ch == 'Q')
		return ;
	// Show the main character on the screen
 	mvaddch(row, col, player);
 	refresh();
 	// Main loop
 	while (42)
 	{
 		print_data(row, col);
 		ch = getch();
 		if (ch == KEY_LEFT)
 		{
 			erase();
 			col = col - 2;
			if (col < 0)
				col = 0;
			if (col > COLS-1)
				col = COLS-1;
 			mvaddch(row, col, player);
 			refresh();
 		}
 		else if (ch == KEY_RIGHT)
 		{
 			erase();
 			col = col + 2;
			if (col < 0)
				col = 0;
			if (col > COLS-1)
				col = COLS-1;
 			mvaddch(row, col, player);
 			refresh();
 		}
 		else if (ch == KEY_UP)
 		{
 			erase();
 			row = row - 1;
			if (row < 0)
				row = 0;
			if (row > LINES-3)
				row = LINES-3;
 			mvaddch(row, col, player);
 			refresh();
 		}
 		else if (ch == KEY_DOWN)
 		{
 			erase();
 			row = row + 1;
			if (row < 0)
				row = 0;
			if (row > LINES-3)
				row = LINES-3;
 			mvaddch(row, col, player);
 			refresh();
 		}
 		else if (ch == 'q' || ch == 'Q')
 			break ;
 	}
}

int				main()
{
 	// Start ncurses
 	Screen 		scr;
 	// Creating character
 	Character 	car = Character('@', LINES/2, COLS/2);
 	// Setting the screen dimensions
 	scr.setWidth(LINES);
 	scr.setHeight(COLS);
 	// Display an intro message
	scr.hello();
 	// Wait until the user press a key
 	int ch = getch();
 	// Clear the screen before game loop
 	clear();

	// GAME LOOP
	game_loop(car, ch);
	
	return (0);
}