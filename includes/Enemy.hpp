/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sraccah <sraccah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/09 14:52:31 by tgauvrit          #+#    #+#             */
/*   Updated: 2016/04/10 14:08:01 by sraccah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENEMY_H
# define ENEMY_H

# include "Entity.hpp"
# include "Character.hpp"
# include "Squad.hpp"

class Squad;

class Enemy : public Entity {

public:

	Enemy( char symbol, int row, int col, int hp, int dmg, bool ff, int points );
	Enemy( Enemy const & obj );

	virtual ~Enemy( void );

	Enemy & operator=( Enemy const & rhs );

	virtual Enemy * clone(void) const = 0;

	virtual void	take_damage(int dmg);
	virtual void	collide( Enemy * rhs );
	virtual void	hit_player( Character * rhs );
	virtual void	handle_oob( void );
	virtual void	spawn( int frame, Character * rhs, Squad * squad );
	virtual void	move( int frame, Character * rhs ) = 0;
	int				getHP( void ) const;
	int				getDmg( void ) const;
	bool			getFF( void ) const;
	int 			getPoints( void ) const;

protected:
	int		_hp;
	int		_dmg;
	bool	_ff;
	int 	_points;

	Enemy( void );

};

#endif
