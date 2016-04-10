/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fighter.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgauvrit <tgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/09 14:52:31 by tgauvrit          #+#    #+#             */
/*   Updated: 2016/04/10 17:49:31 by tgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fighter.hpp"

Fighter::Fighter( void ) : Enemy(Fighter::Symbol, 0, 0, Fighter::HP, Fighter::Dmg, Fighter::FF, Fighter::Points ) { Fighter::_Count++; }

Fighter::Fighter( int row, int col ) : Enemy( Fighter::Symbol, row, col, Fighter::HP, Fighter::Dmg, Fighter::FF, Fighter::Points ) { Fighter::_Count++; }

Fighter::Fighter( Fighter const & obj ) : Enemy() { *this = obj; Fighter::_Count++; }

Fighter::~Fighter( void ) { Fighter::_Count--; }

Fighter & Fighter::operator=( Fighter const & rhs ) {
	this->Enemy::operator=(rhs);
	return *this;
}

Fighter * Fighter::clone( void ) const {
	return new Fighter(*this);
}

void	Fighter::spawn( int frame, Character * rhs, Squad * squad ) {
	(void)rhs;
	if (frame % 16 == 0 && rand() % 4 == 0) { squad->push(new Laser(this->_row+1, this->_col)); }
}

void		Fighter::move( int frame, Character * rhs ) {
	(void)rhs;
	if (frame % 8 == 0) {
		if (rand() % 2 == 0)
			this->_row++;
		if (rand() % 2 == 0) {
			if (this->_col < rhs->_col)
				this->_col++;
			else if (this->_col > rhs->_col)
				this->_col--;
		}
	}
}

int	Fighter::getCount( void ) { return Fighter::_Count; };

int	Fighter::_Count = 0;
