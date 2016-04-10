/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sraccah <sraccah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/09 14:52:31 by tgauvrit          #+#    #+#             */
/*   Updated: 2016/04/10 14:15:44 by sraccah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Enemy.hpp"

int g_score = 0;

Enemy::Enemy( void ) : Entity(), _hp(0), _dmg(0), _ff(false), _points(0) {}

Enemy::Enemy( char symbol, int row, int col, int hp = 1, int dmg = 1, bool ff = false , int points = 0) : Entity(symbol, row, col), _hp(hp), _dmg(dmg), _ff(ff), _points(points) {}

Enemy::Enemy( Enemy const & obj ) : Entity() { *this = obj; }

Enemy::~Enemy( void ) {}

Enemy & Enemy::operator=( Enemy const & rhs ) {
	this->_hp = rhs._hp;
	this->_dmg = rhs._dmg;
	this->_ff = rhs._ff;
	this->_points = rhs._points;
	this->Entity::operator=(rhs);
	return *this;
}

void	Enemy::take_damage(int dmg) {
	this->_hp -= dmg;
	if (this->_hp < 1) {
		this->_hp = 0;
		g_score += this->_points;
	}
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
}

void	Enemy::handle_oob( void ) {
	if (this->_col < 0 || this->_col > COLS-1 || this->_row < 0 || this->_row > LINES-3) {
		this->_hp = 0;
	}
}

void	Enemy::spawn( int frame, Character * rhs, Squad * squad ) { (void)frame; (void)rhs; (void)squad; }

int		Enemy::getHP( void ) const  { return this->_hp; }
int		Enemy::getDmg( void ) const { return this->_dmg; }
bool	Enemy::getFF( void ) const  { return this->_ff; }
int		Enemy::getPoints( void ) const { return this->_points; }
