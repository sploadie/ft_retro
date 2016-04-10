/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Runner.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asmets <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/10 11:02:23 by asmets            #+#    #+#             */
/*   Updated: 2016/04/10 12:57:25 by asmets           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Runner.hpp"

Runner::Runner(void): Enemy(Runner::Symbol, 0, 0, Runner::HP, Runner::Dmg, Runner::FF) {
	this->_direction = rand() % 2 ? 1 : -1;
}

Runner::Runner( int row, int col ) : Enemy( Runner::Symbol, row, col, Runner::HP, Runner::Dmg, Runner::FF ) {
	this->_direction = rand() % 2 ? 1 : -1;
}

Runner::Runner( Runner const & obj ) : Enemy() { *this = obj;}

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
