/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgauvrit <tgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/06 20:50:12 by sraccah           #+#    #+#             */
/*   Updated: 2016/04/10 09:38:46 by tgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <curses.h>
#include <unistd.h>
#include <cstdlib>
#include <ctime>
#include <signal.h>
#include "Screen.hpp"
#include "Character.hpp"
#include "SpaceRock.hpp"
#include "Bullet.hpp"
#include "Squad.hpp"

static void		print_data(int row, int col, int hp, int frame_count, int loop_remaining_time)
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
	printw("Health = %d", hp);
	move(LINES-1, COLS-10);
	attron(COLOR_PAIR(2));
	printw("Score = 0");
	attroff(A_BOLD);
	attroff(COLOR_PAIR(2));
	// Display frames
	move(0, 0);
	attron(COLOR_PAIR(4));
	printw("Frame %d", frame_count);
	attroff(COLOR_PAIR(4));
	// Display remaining milliseconds
	move(0, 20);
	attron(COLOR_PAIR(4));
	printw("Remaining Useconds: %d", loop_remaining_time);
	attroff(COLOR_PAIR(4));
}

static void		print_gameover()
{
	move((LINES/2) - 1, (COLS/2) - 5);
	attron(COLOR_PAIR(1));
	attron(A_BOLD);
	printw("GAME OVER");
	attroff(A_BOLD);
	attroff(COLOR_PAIR(1));

	move((LINES/2) + 1, (COLS/2) - 8);
	attron(COLOR_PAIR(1));
	attron(A_BOLD);
	printw("Press Q to Quit");
	attroff(A_BOLD);
	attroff(COLOR_PAIR(1));
}

int	 clockToMilliseconds(clock_t ticks){
    return (ticks * 1000)/CLOCKS_PER_SEC;
}

int	 clockToUseconds(clock_t ticks){
    return (ticks * 1000000)/CLOCKS_PER_SEC;
}

static void		game_loop(Character & player, int ch)
{
	// Setting the symbol and position of the character
	int & 		row = player.refRow();
	int & 		col = player.refCol();
	bool		alive = true;
	clock_t		loop_start_time = 0;
	int			loop_remaining_time = 0;
	int			frame_count = 0;
	int			i;
	// Check if player want to quit the game
	if (ch == 'q' || ch == 'Q')
		return ;
	// Show the main character on the screen
 	player.draw();
 	// Enemy Example
 	Squad squad;
 	srand(time(NULL));
 	
 	squad.draw();
 	// Main loop
 	while (42)
 	{
 		frame_count++;
 		loop_remaining_time = 40000 - clockToUseconds(clock() - loop_start_time);
 		if (loop_remaining_time > 0) { usleep(loop_remaining_time); }
 		loop_start_time = clock();
 		// Gen Enemies
 		if (42) {
 		// if (frame_count % 12 == 1) {
	 		for (i=0;i<COLS;i++) {
	 			if (rand() % (COLS/2) == 0) {
	 				squad.push(new SpaceRock(0, i));
	 			}
			}
		}
 		// Read Input
 		ch = getch();
 		clear();
 		print_data(row, col, player.getHP(), frame_count, loop_remaining_time);
 		if (alive) {
	 		if (ch == KEY_LEFT) {			// KEY_LEFT
	 			col = col - 1;
	 			// col = col - 2;
				if (col < 0)
					col = 0;
				if (col > COLS-1)
					col = COLS-1;
	 		} else if (ch == KEY_RIGHT) {	// KEY_RIGHT
	 			col = col + 1;
	 			// col = col + 2;
				if (col < 0)
					col = 0;
				if (col > COLS-1)
					col = COLS-1;
	 		} else if (ch == KEY_UP) {		// KEY_UP
	 			row = row - 1;
				if (row < 0)
					row = 0;
				if (row > LINES-3)
					row = LINES-3;
	 		} else if (ch == KEY_DOWN) {	// KEY_DOWN
	 			row = row + 1;
				if (row < 0)
					row = 0;
				if (row > LINES-3)
					row = LINES-3;
			} else if (ch == 'f') {	// F (SHOOT)
	 			squad.push(new Bullet(row, col));
			}
 		}
 		if (ch == 'q' || ch == 'Q') {
 			break;
 		}
 		squad.move(frame_count, &player);
 		squad.collisions(&player);
 		squad.draw();
 		if (player.getHP() > 0) {
 			player.draw();
 		} else {
 			alive = false;
 			row = -1;
 			col = -1;
 			print_gameover();
 		}
 	}
}

void resizeHandler(int sig)
{
	(void)sig;
	endwin();
	std::cerr << "Screen Size was changed..." << std::endl;
	exit(1);
}

int				main( void )
{
 	// Start ncurses
 	Screen 		scr;
 	// Handle Screen Size
 	if (LINES != Screen::Height || COLS != Screen::Width) {
		Screen::badSize();
		while (LINES != Screen::Height || COLS != Screen::Width) {
			Screen::badSize();
		}
	  	return (0);
	}
 	signal(SIGWINCH, &resizeHandler);
 	// Creating character
 	Character	car((LINES + 1)/2, (COLS + 1)/2);
 	// Display an intro message
	scr.hello();
 	// Wait until the user press a key
  	nodelay(stdscr, FALSE);
  	int ch = getch();
  	nodelay(stdscr, TRUE);
 	// Clear the screen before game loop
 	clear();

	// GAME LOOP
	game_loop(car, ch);
	
	return (0);
}