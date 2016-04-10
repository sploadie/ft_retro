/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Entity.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgauvrit <tgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/09 15:17:26 by tgauvrit          #+#    #+#             */
/*   Updated: 2016/04/10 15:08:12 by tgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Entity.hpp"

Entity::Entity( void ) : _symbol('!'), _row(0), _col(0) {}

Entity::Entity(char symbol, int row, int col) : _symbol(symbol), _row(row), _col(col) {}

Entity::Entity(Entity const & src) { *this = src; }

Entity& Entity::operator=(Entity const & rhs) {
	this->_symbol = rhs._symbol;
	this->_row = rhs._row;
	this->_col = rhs._col;
	return *this;
}

Entity::~Entity(void) {}

void		Entity::draw(void) const {
	mvaddch(this->_row, this->_col, this->_symbol);
}

char 		Entity::getSymbol(void) const {
	return this->_symbol;
}

int &		Entity::refRow(void) {
	return this->_row;
}

int &		Entity::refCol(void) {
	return this->_col;
}
