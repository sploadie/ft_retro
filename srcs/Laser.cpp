/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Laser.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgauvrit <tgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/09 14:52:31 by tgauvrit          #+#    #+#             */
/*   Updated: 2016/04/10 13:31:04 by tgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Laser.hpp"

Laser::Laser( void ) : Enemy(Laser::Symbol, 0, 0, Laser::HP, Laser::Dmg, Laser::FF) {}

Laser::Laser( int row, int col ) : Enemy( Laser::Symbol, row, col, Laser::HP, Laser::Dmg, Laser::FF ) {}

Laser::Laser( Laser const & obj ) : Enemy() { *this = obj; }

Laser::~Laser( void ) {}

Laser & Laser::operator=( Laser const & rhs ) {
	this->Enemy::operator=(rhs);
	return *this;
}

Laser * Laser::clone(void) const {
	return new Laser(*this);
}

void		Laser::move( int frame, Character * rhs ) {
	(void)rhs;
	if (frame % 2 == 0) { this->_row++; }
}
