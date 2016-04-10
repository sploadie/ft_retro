/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   LightScout.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sraccah <sraccah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/09 14:52:31 by tgauvrit          #+#    #+#             */
/*   Updated: 2016/04/10 14:30:09 by sraccah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "LightScout.hpp"

LightScout::LightScout( void ) : Enemy(LightScout::Symbol, 0, 0, LightScout::HP, LightScout::Dmg, LightScout::FF, LightScout::Points) {}

LightScout::LightScout( int row, int col ) : Enemy( LightScout::Symbol, row, col, LightScout::HP, LightScout::Dmg, LightScout::FF, LightScout::Points ) {}

LightScout::LightScout( LightScout const & obj ) : Enemy() { *this = obj; }

LightScout::~LightScout( void ) {}

LightScout & LightScout::operator=( LightScout const & rhs ) {
	this->Enemy::operator=(rhs);
	return *this;
}

LightScout * LightScout::clone(void) const {
	return new LightScout(*this);
}

void		LightScout::move( int frame, Character * rhs ) {
	(void)rhs;
	if (frame % 3 == 0) { this->_row++; }
}
