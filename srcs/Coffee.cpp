/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Coffee.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgauvrit <tgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/09 14:52:31 by tgauvrit          #+#    #+#             */
/*   Updated: 2016/04/10 21:06:19 by tgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Coffee.hpp"

Coffee::Coffee( void ) : Enemy(Coffee::Symbol, 0, 0, Coffee::HP, Coffee::Dmg, Coffee::FF, Coffee::Points) { Coffee::_Count++; }

Coffee::Coffee( int row, int col ) : Enemy( Coffee::Symbol, row, col, Coffee::HP, Coffee::Dmg, Coffee::FF, Coffee::Points ) { Coffee::_Count++; }

Coffee::Coffee( Coffee const & obj ) : Enemy() { *this = obj; Coffee::_Count++; }

Coffee::~Coffee( void ) { Coffee::_Count--; }

Coffee & Coffee::operator=( Coffee const & rhs ) {
	this->Enemy::operator=(rhs);
	return *this;
}

Coffee * Coffee::clone(void) const {
	return new Coffee(*this);
}

void	Coffee::draw( void ) const {
	attron(COLOR_PAIR(2));
	mvaddstr(this->_row, this->_col, "♥");
	attron(COLOR_PAIR(4));
}

void	Coffee::move( int frame, Character * rhs ) {
	(void)rhs;
	if (frame % 5 == 0) {
		this->_row++;
	}
}

int	Coffee::getCount( void ) { return Coffee::_Count; };

int	Coffee::_Count = 0;
