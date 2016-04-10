/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   LightScout.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgauvrit <tgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/09 14:52:31 by tgauvrit          #+#    #+#             */
/*   Updated: 2016/04/10 17:59:30 by tgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "LightScout.hpp"

LightScout::LightScout( void ) : Enemy(LightScout::Symbol, 0, 0, LightScout::HP, LightScout::Dmg, LightScout::FF, LightScout::Points) { LightScout::_Count++; }

LightScout::LightScout( int row, int col ) : Enemy( LightScout::Symbol, row, col, LightScout::HP, LightScout::Dmg, LightScout::FF, LightScout::Points ) { LightScout::_Count++; }

LightScout::LightScout( LightScout const & obj ) : Enemy() { *this = obj; LightScout::_Count++; }

LightScout::~LightScout( void ) { LightScout::_Count--; }

LightScout & LightScout::operator=( LightScout const & rhs ) {
	this->Enemy::operator=(rhs);
	return *this;
}

LightScout * LightScout::clone(void) const {
	return new LightScout(*this);
}

void		LightScout::move( int frame, Character * rhs ) {
	(void)rhs;
	if (frame % 3 == 0) {
		if (rand() % 16 == 0) {
			if (this->_col < rhs->_col)
				this->_col++;
			else if (this->_col > rhs->_col)
				this->_col--;
		}
		this->_row++;
	}
}

int	LightScout::getCount( void ) { return LightScout::_Count; };

int	LightScout::_Count = 0;
