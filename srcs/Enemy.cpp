/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgauvrit <tgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/09 14:52:31 by tgauvrit          #+#    #+#             */
/*   Updated: 2016/04/09 19:01:07 by tgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Enemy.hpp"

Enemy::Enemy( void ) : Entity(), _hp(0), _dmg(0), _ff(false) {}

Enemy::Enemy( char symbol, int row, int col, int hp = 1, int dmg = 1, bool ff = false ) : Entity(symbol, row, col), _hp(hp), _dmg(dmg), _ff(ff) {}

Enemy::Enemy( Enemy const & obj ) : Entity() { *this = obj; }

Enemy::~Enemy( void ) {}

Enemy & Enemy::operator=( Enemy const & rhs ) {
	this->_hp = rhs._hp;
	this->_dmg = rhs._dmg;
	this->_ff = rhs._ff;
	this->Entity::operator=(rhs);
	return *this;
}

void	Enemy::take_damage(int dmg) {
	this->_hp -= dmg;
	if (this->_hp < 1) { this->_hp = 0; }
}

void	Enemy::collide( Enemy * rhs ) {
	if (this->_col == rhs->_col && this->_row == rhs->_row) {
		if (this->_ff || rhs->_ff) {
			this->take_damage(rhs->_dmg);
			rhs->take_damage(this->_dmg);
		}
	}
}

void	Enemy::hit_player( Character * rhs ) {
	if (this->_col == rhs->_col && this->_row == rhs->_row) {
		this->_hp = 0;
		rhs->take_damage(this->_dmg);
	}
	// Handle Out of Bounds
	if (this->_col < 0 || this->_col > COLS-1 || this->_row < 0 || this->_row > LINES-3) { this->_hp = 0; }
}

int	Enemy::getHP( void ) { return this->_hp; }
