/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Screen.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgauvrit <tgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/08 17:50:04 by sraccah           #+#    #+#             */
/*   Updated: 2016/04/09 15:41:05 by tgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Screen.hpp"

Screen::Screen(void)
{
	// Initialisation
	initscr();
	// Clear screen
  	clear();
  	// User input not displayed
  	noecho();
  	// User input does not require newline
  	cbreak();
  	// Special user input does not generate a signal and is passed to program instead
  	raw();
  	// getch does not wait for user input
  	nodelay(stdscr, TRUE);
  	// Preparing the keypad and cursor
  	keypad(stdscr, TRUE);
  	curs_set(0);
  	// Initialising colors we will use
	start_color();
	init_pair(1, COLOR_RED, COLOR_BLACK);
	init_pair(2, COLOR_GREEN, COLOR_BLACK);
	init_pair(3, COLOR_BLUE, COLOR_BLACK);
	init_pair(4, COLOR_YELLOW, COLOR_BLACK);
	attron(COLOR_PAIR(3));
	attron(A_BOLD);
	printw("Screen created...\n");
	attroff(A_BOLD);
	attroff(COLOR_PAIR(3));
	return ;
}

Screen::Screen(Screen const & src)
{
	*this = src;
	return ;
}

Screen& Screen::operator=(Screen const & rhs)
{
	(void)rhs;
	return *this;
}

Screen::~Screen(void)
{
	attron(COLOR_PAIR(3));
	printw("Screen deleted...\n");
	endwin();
	return ;
}

void		Screen::hello()
{
	// Playing a sound at start
	std::cout << '\a';
	// Display menu
	move(10, 44);
	attron(COLOR_PAIR(1));
	attron(A_BOLD);
	attron(A_BLINK);
	printw("=> Hello World <=");
	attroff(A_BLINK);
	move(11, 38);
	attron(COLOR_PAIR(2));
	attron(A_BOLD);
	printw("Welcome to our ft_retro game !");
	attroff(A_BOLD);
	move(15, 30);
	attron(COLOR_PAIR(4));
	printw("Press any key to start or 'q' to quit the game");
	attroff(COLOR_PAIR(4));
	move(0, 0);
	refresh();
}

void		Screen::badSize()
{
	// Display Info
	clear();
	move(0, 0);
	printw("Please resize your terminal and then relaunch. Thank you!\n");
	printw("Current Size: %dx%d\n", LINES, COLS);
	printw("Please resize to: %dx%d", Screen::Height, Screen::Width);
	move(0, 0);
	refresh();
}
