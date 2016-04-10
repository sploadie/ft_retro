/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Star.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgauvrit <tgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/09 14:52:31 by tgauvrit          #+#    #+#             */
/*   Updated: 2016/04/10 16:49:46 by tgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Star.hpp"

Star::Star( void ) : Enemy(Star::Symbol, 0, 0, Star::HP, Star::Dmg, Star::FF, Star::Points) {}

Star::Star( int row, int col ) : Enemy( Star::Symbol, row, col, Star::HP, Star::Dmg, Star::FF, Star::Points ) {}

Star::Star( Star const & obj ) : Enemy() { *this = obj; }

Star::~Star( void ) {}

Star & Star::operator=( Star const & rhs ) {
	this->Enemy::operator=(rhs);
	return *this;
}

Star * Star::clone(void) const {
	return new Star(*this);
}

void		Star::draw(void) const {
	this->Entity::draw();
	// mvaddstr(this->_row, this->_col, "\xE2\x98\x86");
	// mvaddstr(this->_row, this->_col, "\xE2\x94\x83");
}

void		Star::move( int frame, Character * rhs ) {
	(void)frame; (void)rhs;
	this->_row++;
}
