/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Boss.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgauvrit <tgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/10 17:21:48 by sraccah           #+#    #+#             */
/*   Updated: 2016/04/10 19:50:06 by tgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Boss.hpp"

Boss::Boss( void ) : Enemy('O', 0, 0, Boss::HP, Boss::Dmg, Boss::FF, Boss::Points) {}

Boss::Boss( int row, int col, char sym, int hp, int dmg, int points, int speed ) : Enemy( sym, row, col, hp, dmg, Boss::FF, points ) {
	// this->_symbol = symbol;
	this->_speed = speed;
}

Boss::Boss( Boss const & obj ) : Enemy() { *this = obj; }

Boss::~Boss( void ) {}

Boss & Boss::operator=( Boss const & rhs ) {
	// this->_symbol = rhs._symbol;
	this->_speed  = rhs._speed;
	this->Enemy::operator=(rhs);
	return *this;
}

Boss * Boss::clone(void) const {
	return new Boss(*this);
}

// void		Boss::draw(void) const {
// 	this->Entity::draw();
// 	// mvaddstr(this->_row, this->_col, this->_symbol.c_str());
// 	// mvaddstr(this->_row, this->_col, "\xE2\x94\x83");
// }

void		Boss::move( int frame, Character * rhs ) {
	(void)rhs;
	if (frame % this->_speed == 0) { this->_row++; }
}
