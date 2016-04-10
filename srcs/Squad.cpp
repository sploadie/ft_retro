/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Squad.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgauvrit <tgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/08 18:13:21 by tgauvrit          #+#    #+#             */
/*   Updated: 2016/04/10 15:05:02 by tgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Squad.hpp"

Squad::Squad( void ) : _count(0), _array_size(Squad::_AllocSize) {
	this->_enemies = new Enemy * [this->_array_size];
	return;
}

Squad::Squad( Squad const & obj ) {
	*this = obj;
	return;
}

Squad::~Squad( void ) {
	for (int i=0;i<this->_count;i++) { delete this->_enemies[i]; }
	delete this->_enemies;
	return;
}

Squad & Squad::operator=( Squad const & rhs ) {
	int i;
	// Delete
	for (i=0;i<this->_count;i++) { delete this->_enemies[i]; }
	delete this->_enemies;
	// Copy
	this->_count = rhs._count;
	this->_array_size = rhs._array_size;
	this->_enemies = new Enemy * [this->_array_size];
	for (i=0;i<this->_count;i++) { this->_enemies[i] = rhs._enemies[i]->clone(); }
	return *this;
}

int Squad::getCount( void ) const { return this->_count; }

Enemy * Squad::getUnit( int i ) const {
	if (i < 0 || i >= this->_count) { return NULL; }
	return this->_enemies[i];
}

void Squad::deleteUnit( int i ) {
	if (i < 0 || i >= this->_count) { return; }
	delete this->_enemies[i];
	this->_count--;
	this->_enemies[i] = this->_enemies[this->_count];
}

int Squad::push( Enemy * newbie ) {
	int i;
	if (newbie == NULL) { return this->_count; }
	for (i=0;i<this->_count;i++) { if (this->_enemies[i] == newbie) { return this->_count; } }
	if (this->_count == this->_array_size) {
		this->_array_size += Squad::_AllocSize;
		Enemy ** tmp = new Enemy * [this->_array_size];
		for (i=0;i<this->_count;i++) { tmp[i] = this->_enemies[i]; }
		delete this->_enemies;
		this->_enemies = tmp;
	}
	this->_enemies[this->_count++] = newbie;
	return this->_count;
}

void Squad::draw( void ) const {
	for (int i=0;i<this->_count;i++) { this->_enemies[i]->draw(); }
}

void Squad::collisions( Character * player ) {
	int i, j;
	for (i=0;i<this->_count;i++) {
		this->_enemies[i]->hit_player(player);
		for (j=i+1;j<this->_count;j++) {
			this->_enemies[i]->collide( this->_enemies[j] );
		}
		this->_enemies[i]->handle_oob();
	}
	for (i=0;i<this->_count;i++) {
		while (i < this->_count && this->_enemies[i]->getHP() == 0) { this->deleteUnit(i); }
	}
}

void Squad::handle_oob( void ) {
	int i = 0;
	while(i<this->_count) {
		this->_enemies[i]->handle_oob();
		if (this->_enemies[i]->getHP() == 0) {
			this->deleteUnit(i);
			continue;
		}
		i++;
	}
}

void Squad::move( int frames, Character * player ) {
	for (int i=0;i<this->_count;i++) { this->_enemies[i]->move(frames, player); }
}

void Squad::spawn( int frames, Character * player ) {
	for (int i=0;i<this->_count;i++) { this->_enemies[i]->spawn(frames, player, this); }
}
