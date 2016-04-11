/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgauvrit <tgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/06 20:50:12 by sraccah           #+#    #+#             */
/*   Updated: 2016/04/10 21:17:06 by tgauvrit         ###   ########.fr       */
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
#include "LightScout.hpp"
#include "HeavyScout.hpp"
#include "Fighter.hpp"
#include "Runner.hpp"
#include "Star.hpp"
#include "Boss.hpp"
#include "Coffee.hpp"
#include "Squad.hpp"

extern int		g_score;

namespace 		Bosses {
	void		proto_boss(Squad & squad) {
		int 	i = COLS/2-2;
		squad.push(new Boss(0, i+2, '#', 1, 1, 2, 4));
		squad.push(new Boss(1, i+1, '#', 1, 1, 2, 4));
		squad.push(new Boss(1, i+2, '#', 1, 1, 2, 4));
		squad.push(new Boss(1, i+3, '#', 1, 1, 2, 4));
		squad.push(new Boss(2, i,   '#', 1, 1, 2, 4));
		squad.push(new Boss(2, i+1, '#', 1, 1, 2, 4));
		squad.push(new Boss(2, i+2, '#', 1, 1, 2, 4));
		squad.push(new Boss(2, i+3, '#', 1, 1, 2, 4));
		squad.push(new Boss(2, i+4, '#', 1, 1, 2, 4));
		squad.push(new Boss(3, i+1, '#', 1, 1, 2, 4));
		squad.push(new Boss(3, i+2, '#', 1, 1, 2, 4));
		squad.push(new Boss(3, i+3, '#', 1, 1, 2, 4));
		squad.push(new Boss(4, i+2, '#', 1, 1, 2, 4));
	}
	void		first_boss(Squad & squad) {
		int i, j, k, l;
		// 0
		i = 0;
		for (j=0;j<3;j++) {
			squad.push(new Boss(0, i++, 'X', 999, 5, 2, 60));
		}
		for (j=0;j<4;j++) {
			squad.push(new Boss(0, i++, 'O', 1, 2, 2, 60));
		}
		for (j=0;i<COLS;j++) {
			squad.push(new Boss(0, i++, 'X', 999, 5, 2, 60));
		}
		// 1 - 3
		for (l=1;l<4;l++) {
			i = 0;
			for (j=0;j<4;j++) {
				squad.push(new Boss(l, i++, 'X', 999, 5, 2, 60));
			}
			for (k=0;k<20;k++) {
				for (j=0;j<4;j++) {
					squad.push(new Boss(l, i++, 'O', 1, 2, 2, 60));
				}
				i+=2;
			}
			squad.push(new Boss(l, i++, 'O', 1, 2, 2, 60));
			for (j=0;i<COLS;j++) {
				squad.push(new Boss(l, i++, 'X', 999, 5, 2, 60));
			}
		}
		// 4 - 6
		for (l=4;l<8;l++) {
			i = 0;
			for (j=0;j<4;j++) {
				squad.push(new Boss(l, i++, 'X', 999, 5, 2, 60));
			}
			for (k=0;k<20;k++) {
				i+=5;
				squad.push(new Boss(l, i++, 'O', 1, 2, 2, 60));
			}
			i++;
			for (j=0;i<COLS;j++) {
				squad.push(new Boss(l, i++, 'X', 999, 5, 2, 60));
			}
		}
		// 8
		i = 0;
		for (j=0;j<124;j++) {
			squad.push(new Boss(8, i++, 'X', 999, 5, 2, 60));
		}
		i++;
		for (j=0;i<COLS;j++) {
			squad.push(new Boss(8, i++, 'X', 999, 5, 2, 60));
		}
	}
}

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
	move(LINES-1, COLS-12);
	attron(COLOR_PAIR(2));
	printw("Score = %d", g_score);
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
	// int			frame_count = 4999;
	int			i;
	// Check if player want to quit the game
	if (ch == 'q' || ch == 'Q')
		return ;
	// Show the main character on the screen
 	player.draw();
 	// Enemy Example
 	Squad squad;
 	Squad background;
 	srand(time(NULL));

 	bool	boss_waiting = false;
 	bool	boss_present = false;
 	int		boss_count = 0;

 	int		rock_count;
 	int		rock_row;
 	int		rock_col;

 	// Main loop
 	while (42)
 	{
 		frame_count++;
 		if (frame_count == 5000 || frame_count % 15000 == 0) {
 			boss_waiting = true;
 		}
 		// loop_remaining_time = 40000 - clockToUseconds(clock() - loop_start_time);
 		loop_remaining_time = 20000 - (clockToUseconds(clock()) - clockToUseconds(loop_start_time));
 		if (loop_remaining_time > 0) { usleep(loop_remaining_time); }
 		loop_start_time = clock();
 		// Gen Background
	 	for (i=0;i<COLS;i++) {
 			if (rand() % (COLS/2) == 0) {
				background.push(new Star(0, i));
 			}
 		}
 		// Gen Enemies
		if (frame_count % 12 == 1 && !boss_waiting && !boss_present) {
	 		for (i=0;i<COLS;i++) {
	 			if (rand() % (COLS/2) == 0 && SpaceRock::getCount() < 100 + (10 * frame_count/250)) {
	 				rock_row = 0;
	 				rock_col = i;
					squad.push(new SpaceRock(rock_row, rock_col));
					for (rock_count=0;rock_count<4;rock_count++) {
						if (rand() % 2)
							rock_row++;
						else
							rock_col++;
						squad.push(new SpaceRock(rock_row, rock_col));
					}
	 			}
	 			if (rand() % (COLS * 50) == 0 && Coffee::getCount() < 1) {
	 				squad.push(new Coffee(0, i));
	 			} else if (rand() % COLS == 0 && LightScout::getCount() < 2 + frame_count/500) {
	 				squad.push(new LightScout(0, i));
	 			} else if (rand() % COLS == 0 && Runner::getCount() < 2 + frame_count/500) {
	 				squad.push(new Runner(0, i));
	 			} else if (rand() % COLS == 0 && HeavyScout::getCount() < 2 + frame_count/700) {
	 				squad.push(new HeavyScout(0, i));
	 			} else if (rand() % (COLS * 4) == 0 && Fighter::getCount() < 1 + frame_count/1000) {
	 				squad.push(new Fighter(0, i));
	 			}
			}
		} else if (boss_waiting && squad.getCount() == 0) {
			boss_waiting = false;
			boss_present = true;
			// Spawn Boss
			if (boss_count == 0) {
				Bosses::first_boss(squad);
			} else {
				Bosses::first_boss(squad);
			}
		} else if (boss_present && squad.getCount() == 0) {
			boss_present = false;
			boss_count++;
			if (Character::MaxHP == 5) {
				player._symbol = 'A';
			}
			Character::MaxHP += 5;
			player.take_damage(-(Character::MaxHP));
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
 		background.move(frame_count, &player);
 		background.handle_oob();
		attron(COLOR_PAIR(3));
 		background.draw();
		attroff(COLOR_PAIR(3));
 		squad.spawn(frame_count, &player);
 		squad.move(frame_count, &player);
 		squad.collisions(&player);
		attron(COLOR_PAIR(4));
 		squad.draw();
		attroff(COLOR_PAIR(4));
 		if (player.getHP() > 0) {
 			player.draw();
 		} else {
 			alive = false;
 			row = -1;
 			col = COLS/2;
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
