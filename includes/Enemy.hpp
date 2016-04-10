/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgauvrit <tgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/09 14:52:31 by tgauvrit          #+#    #+#             */
/*   Updated: 2016/04/10 09:37:47 by tgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENEMY_H
# define ENEMY_H

# include "Entity.hpp"
# include "Character.hpp"

class Enemy : public Entity {

public:

	Enemy( char symbol, int row, int col, int hp, int dmg, bool _ff );
	Enemy( Enemy const & obj );

	virtual ~Enemy( void );

	Enemy & operator=( Enemy const & rhs );

	virtual Enemy * clone(void) const = 0;

	virtual void	take_damage(int dmg);
	virtual void	collide( Enemy * rhs );
	virtual void	hit_player( Character * rhs );
	virtual void	handle_oob( void );
	virtual void	move( int frame, Character * rhs ) = 0;
	int		getHP( void );
	int		getDmg( void );
	bool	getFF( void );

protected:
	int		_hp;
	int		_dmg;
	bool	_ff;

	Enemy( void );

};

#endif
