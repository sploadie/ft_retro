/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HeavyScout.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgauvrit <tgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/09 14:52:31 by tgauvrit          #+#    #+#             */
/*   Updated: 2016/04/10 17:59:23 by tgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HeavyScout.hpp"

HeavyScout::HeavyScout( void ) : Enemy(HeavyScout::Symbol, 0, 0, HeavyScout::HP, HeavyScout::Dmg, HeavyScout::FF, HeavyScout::Points) { HeavyScout::_Count++; }

HeavyScout::HeavyScout( int row, int col ) : Enemy( HeavyScout::Symbol, row, col, HeavyScout::HP, HeavyScout::Dmg, HeavyScout::FF, HeavyScout::Points ) { HeavyScout::_Count++; }

HeavyScout::HeavyScout( HeavyScout const & obj ) : Enemy() { *this = obj; HeavyScout::_Count++; }

HeavyScout::~HeavyScout( void ) { HeavyScout::_Count--; }

HeavyScout & HeavyScout::operator=( HeavyScout const & rhs ) {
	this->Enemy::operator=(rhs);
	return *this;
}

HeavyScout * HeavyScout::clone(void) const {
	return new HeavyScout(*this);
}

void		HeavyScout::move( int frame, Character * rhs ) {
	(void)rhs;
	if (frame % 4 == 0) {
		if (rand() % 12 == 0) {
			if (this->_col < rhs->_col)
				this->_col++;
			else if (this->_col > rhs->_col)
				this->_col--;
		}
		this->_row++;
	}
}

int	HeavyScout::getCount( void ) { return HeavyScout::_Count; };

int	HeavyScout::_Count = 0;
