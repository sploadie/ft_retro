/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Entity.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sraccah <sraccah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/09 15:13:59 by tgauvrit          #+#    #+#             */
/*   Updated: 2016/04/10 13:47:04 by sraccah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENTITY_H
# define ENTITY_H

# include <iostream>
# include <curses.h>

class Entity {

public:
	Entity(char symbol, int row, int col);

	Entity( Entity const & obj );

	~Entity( void );

	Entity & operator=( Entity const & rhs );

	virtual void	draw() const;
	char 			getSymbol() const;
	int &			refRow();
	int &			refCol();

	char 		_symbol;
	int			_row;
	int			_col;

protected:
	Entity( void );

private:

};

#endif
