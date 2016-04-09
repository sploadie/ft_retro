/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgauvrit <tgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/09 14:52:31 by tgauvrit          #+#    #+#             */
/*   Updated: 2016/04/09 17:46:29 by tgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENEMY_H
# define ENEMY_H

# include "Entity.hpp"
# include "Character.hpp"

class Enemy : public Entity {

public:

	Enemy( char symbol, int row, int col, int hp, int dmg );
	Enemy( Enemy const & obj );

	virtual ~Enemy( void );

	Enemy & operator=( Enemy const & rhs );

	Enemy * clone(void) const;

	void	take_damage(int dmg);
	void	collide( Enemy * rhs );
	void	hit_player( Character * rhs );
	int		getHP( void );

private:
	Enemy( void );

	int		_hp;
	int		_dmg;
	int		_ff;

};

#endif
