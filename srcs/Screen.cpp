/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Screen.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sraccah <sraccah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/08 17:50:04 by sraccah           #+#    #+#             */
/*   Updated: 2016/01/09 17:40:44 by sraccah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/main.hpp"

Screen::Screen(void)
{
	// Initialisation
	initscr();
	// Clear screen
  	clear();
  	noecho();
  	cbreak();
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
	printw("=> Hello World <=\n");
	attroff(A_BLINK);
	move(11, 38);
	attron(COLOR_PAIR(2));
	attron(A_BOLD);
	printw("Welcome to our ft_retro game !\n");
	attroff(A_BOLD);
	move(15, 30);
	attron(COLOR_PAIR(4));
	printw("Press any key to start or 'q' to quit the game\n");
	attroff(COLOR_PAIR(4));
	move(0, 0);
}

void		Screen::print(const char *msg)
{
	printw(msg);
}

int			Screen::getHeight()
{
	return this->_height;
}

void		Screen::setHeight(int height)
{
	this->_height = height;
}

int			Screen::getWidth()
{
	return this->_width;
}

void		Screen::setWidth(int width)
{
	this->_width = width;
}
