/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Runner.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgauvrit <tgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/10 11:02:23 by asmets            #+#    #+#             */
/*   Updated: 2016/04/10 17:57:27 by tgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Runner.hpp"

Runner::Runner(void): Enemy(Runner::Symbol, 0, 0, Runner::HP, Runner::Dmg, Runner::FF, Runner::Points ) {
	Runner::_Count++;
	this->_direction = rand() % 2 ? 1 : -1;
}

Runner::Runner( int row, int col ) : Enemy( Runner::Symbol, row, col, Runner::HP, Runner::Dmg, Runner::FF, Runner::Points ) {
	Runner::_Count++;
	this->_direction = rand() % 2 ? 1 : -1;
}

Runner::Runner( Runner const & obj ) : Enemy() { *this = obj; Runner::_Count++; }

Runner::~Runner( void ) {
}

Runner & Runner::operator=( Runner const & rhs ) {
	this->_direction = rhs._direction;
	this->Enemy::operator=(rhs);
	return *this;
}

Runner * Runner::clone(void) const {
	return new Runner(*this);
}

void		Runner::move( int frame, Character * rhs ) {
	(void)rhs;
	if (frame % 4 == 0) {
		if ((COLS-3 < this->_col) || (2 > this->_col))
			this->_direction = -(this->_direction);
		this->_row++;
		this->_col += this->_direction * 2;
	}
}

int	Runner::getCount( void ) { return Runner::_Count; };

int	Runner::_Count = 0;
