/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   LightScout.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgauvrit <tgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/09 14:52:31 by tgauvrit          #+#    #+#             */
/*   Updated: 2016/04/10 10:26:10 by tgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "LightScout.hpp"

LightScout::LightScout( void ) : Enemy(LightScout::Symbol, 0, 0, LightScout::HP, LightScout::Dmg, LightScout::FF) {}

LightScout::LightScout( int row, int col ) : Enemy( LightScout::Symbol, row, col, LightScout::HP, LightScout::Dmg, LightScout::FF ) {}

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
	if (frame % 2 == 0) { this->_row++; }
}
