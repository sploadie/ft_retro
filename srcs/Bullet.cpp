/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bullet.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgauvrit <tgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/09 14:52:31 by tgauvrit          #+#    #+#             */
/*   Updated: 2016/04/10 19:52:52 by tgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bullet.hpp"

Bullet::Bullet( void ) : Enemy(Bullet::Symbol, 0, 0, Bullet::HP, Bullet::Dmg, Bullet::FF, Bullet::Points) {}

Bullet::Bullet( int row, int col ) : Enemy( Bullet::Symbol, row, col, Bullet::HP, Bullet::Dmg, Bullet::FF, Bullet::Points ) {}

Bullet::Bullet( Bullet const & obj ) : Enemy() { *this = obj; }

Bullet::~Bullet( void ) {}

Bullet & Bullet::operator=( Bullet const & rhs ) {
	this->Enemy::operator=(rhs);
	return *this;
}

Bullet * Bullet::clone(void) const {
	return new Bullet(*this);
}

void	Bullet::draw(void) const {
	attron(COLOR_PAIR(2));
	this->Entity::draw();
	attron(COLOR_PAIR(4));
}

void	Bullet::take_damage(int dmg) {
	(void)dmg;
	this->_hp = 0;
}

void	Bullet::collide( Enemy * rhs ) {
	// if (this->_col == rhs->_col && (this->_row == rhs->_row || this->_row-1 == rhs->_row)) {
	if (this->_col == rhs->_col && (this->_row == rhs->_row)) {
		this->take_damage(0);
		rhs->take_damage(this->getDmg());
	}
}

void	Bullet::hit_player( Character * rhs ) { (void)rhs; }

void	Bullet::move( int frame, Character * rhs ) {
	(void)rhs;
	if (frame % 2 == 0) { this->_row--; }
}
