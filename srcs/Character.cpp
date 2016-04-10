/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgauvrit <tgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/09 13:10:52 by sraccah           #+#    #+#             */
/*   Updated: 2016/04/10 15:40:27 by tgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character( void ) : Entity('^', 0, 0) {
	this->_hp = Character::MaxHP;
}

Character::Character(int row, int col) : Entity('^', row, col)
{
	this->_hp = Character::MaxHP;
	std::cout << "Character created..." << std::endl;
	attron(A_BOLD);
	attron(COLOR_PAIR(3));
	printw("Character created...");
	attroff(COLOR_PAIR(3));
	attroff(A_BOLD);
	return ;
}

Character::Character(Character const & src) : Entity('^', 0, 0) { *this = src; }

Character& Character::operator=(Character const & rhs)
{
	this->_hp = rhs._hp;
	this->Entity::operator=(rhs);
	return *this;
}

Character::~Character(void)
{
	std::cout << "Character deleted..." << std::endl;
	attron(COLOR_PAIR(3));
	printw("Character deleted...");
	attroff(COLOR_PAIR(3));
	return ;
}

void		Character::draw(void) const {
	// attron(COLOR_PAIR(4));
	this->Entity::draw();
	// attroff(COLOR_PAIR(4));
}

bool	Character::take_damage(int damage) {
	this->_hp -= damage;
	if (this->_hp < 1) { this->_hp = 0; return true; }
	if (this->_hp > Character::MaxHP) { this->_hp = Character::MaxHP; }
	return false;
}

int	Character::getHP( void ) { return this->_hp; }
