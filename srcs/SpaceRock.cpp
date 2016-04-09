/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SpaceRock.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgauvrit <tgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/09 14:52:31 by tgauvrit          #+#    #+#             */
/*   Updated: 2016/04/09 19:12:14 by tgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SpaceRock.hpp"

SpaceRock::SpaceRock( void ) : Enemy(SpaceRock::Symbol, 0, 0, SpaceRock::HP, SpaceRock::Dmg, SpaceRock::FF) {}

SpaceRock::SpaceRock( int row, int col ) : Enemy( SpaceRock::Symbol, row, col, SpaceRock::HP, SpaceRock::Dmg, SpaceRock::FF ) {}

SpaceRock::SpaceRock( SpaceRock const & obj ) : Enemy() { *this = obj; }

SpaceRock::~SpaceRock( void ) {}

SpaceRock & SpaceRock::operator=( SpaceRock const & rhs ) {
	this->Enemy::operator=(rhs);
	return *this;
}

SpaceRock * SpaceRock::clone(void) const {
	return new SpaceRock(*this);
}

void		SpaceRock::move( int frame, Character * rhs ) {
	(void)rhs;
	if (frame % 12 == 0) { this->_row++; }
}
