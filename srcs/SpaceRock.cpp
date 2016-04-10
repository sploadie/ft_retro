/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SpaceRock.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sraccah <sraccah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/09 14:52:31 by tgauvrit          #+#    #+#             */
/*   Updated: 2016/04/10 14:09:54 by sraccah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SpaceRock.hpp"

SpaceRock::SpaceRock( void ) : Enemy(SpaceRock::Symbol, 0, 0, SpaceRock::HP, SpaceRock::Dmg, SpaceRock::FF, SpaceRock::Points) {}

SpaceRock::SpaceRock( int row, int col ) : Enemy( SpaceRock::Symbol, row, col, SpaceRock::HP, SpaceRock::Dmg, SpaceRock::FF, SpaceRock::Points ) {}

SpaceRock::SpaceRock( SpaceRock const & obj ) : Enemy() { *this = obj; }

SpaceRock::~SpaceRock( void ) {}

SpaceRock & SpaceRock::operator=( SpaceRock const & rhs ) {
	this->Enemy::operator=(rhs);
	return *this;
}

SpaceRock * SpaceRock::clone(void) const {
	return new SpaceRock(*this);
}

void	SpaceRock::collide( Enemy * rhs ) {
	if (this->_col == rhs->_col && this->_row == rhs->_row) {
		if (rhs->getHP() != 0) {
			rhs->take_damage(0);
			this->_hp = 0;
		}
	}
}

void	SpaceRock::hit_player( Character * rhs ) {
	if (this->_col == rhs->_col && this->_row == rhs->_row) {
		this->_hp = 0;
		rhs->take_damage(1);
	}
}


void		SpaceRock::move( int frame, Character * rhs ) {
	(void)rhs;
	if (frame % 12 == 0) { this->_row++; }
}
