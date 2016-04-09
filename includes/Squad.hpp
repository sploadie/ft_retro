/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Squad.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgauvrit <tgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/08 17:07:25 by tgauvrit          #+#    #+#             */
/*   Updated: 2016/04/09 17:46:32 by tgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SQUAD_H
# define SQUAD_H

# include <cstddef>
# include "Enemy.hpp"
# include "Character.hpp"

class Squad {

public:

	Squad( void );
	Squad( Squad const & obj );

	~Squad( void );

	Squad & operator=( Squad const & rhs );

	int getCount( void ) const;
	Enemy * getUnit( int ) const;
	void deleteUnit( int );
	int push( Enemy * );

	void draw( void ) const;
	void collisions( Character * player );

private:
	int					_count;
	int					_array_size;
	Enemy **			_enemies;

	static int const	_AllocSize = 32;

};

#endif
