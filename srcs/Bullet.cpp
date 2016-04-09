/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bullet.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgauvrit <tgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/09 14:52:31 by tgauvrit          #+#    #+#             */
/*   Updated: 2016/04/09 19:23:12 by tgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bullet.hpp"

Bullet::Bullet( void ) : Enemy(Bullet::Symbol, 0, 0, Bullet::HP, Bullet::Dmg, Bullet::FF) {}

Bullet::Bullet( int row, int col ) : Enemy( Bullet::Symbol, row, col, Bullet::HP, Bullet::Dmg, Bullet::FF ) {}

Bullet::Bullet( Bullet const & obj ) : Enemy() { *this = obj; }

Bullet::~Bullet( void ) {}

Bullet & Bullet::operator=( Bullet const & rhs ) {
	this->Enemy::operator=(rhs);
	return *this;
}

Bullet * Bullet::clone(void) const {
	return new Bullet(*this);
}

void	Bullet::hit_player( Character * rhs ) { (void)rhs; }


void		Bullet::move( int frame, Character * rhs ) {
	(void)rhs;
	if (frame % 2 == 0) { this->_row--; }
}
