/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sraccah <sraccah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/09 13:10:52 by sraccah           #+#    #+#             */
/*   Updated: 2016/01/09 17:19:43 by sraccah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/main.hpp"

Character::Character(char symbol, int row, int col): _symbol(symbol), _row(row), _col(col)
{
	attron(A_BOLD);
	print("Character created...\n", 3);
	attroff(A_BOLD);
	return ;
}

Character::Character(Character const & src, char symbol, int row, int col): _symbol(symbol), _row(row), _col(col)
{
	*this = src;
	return ;
}

Character& Character::operator=(Character const & rhs)
{
	(void)rhs;
	return *this;
}

Character::~Character(void)
{
	print("Character deleted...\n", 3);
	return ;
}

void		Character::print(const char *msg, int nbr)
{
	attron(COLOR_PAIR(nbr));
	printw(msg);
	attroff(COLOR_PAIR(nbr));
}

char 		Character::getSymbol(void)
{
	return this->_symbol;
}

int 		Character::getRow(void)
{
	return this->_row;
}

int 		Character::getCol(void)
{
	return this->_col;
}
