/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bullet.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgauvrit <tgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/09 14:52:31 by tgauvrit          #+#    #+#             */
/*   Updated: 2016/04/10 16:52:20 by tgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BULLET_H
# define BULLET_H

# include "Enemy.hpp"
# include "Character.hpp"

class Bullet : public Enemy {

public:

	Bullet( int row, int col );
	Bullet( Bullet const & obj );

	virtual ~Bullet( void );

	Bullet & operator=( Bullet const & rhs );

	Bullet * clone(void) const;

	void	draw(void) const;
	void	take_damage(int dmg);
	void	collide( Enemy * rhs );
	void	hit_player( Character * rhs );
	void	move( int frame, Character * rhs );

	static char const Symbol = '\'';
	static int  const HP = 1;
	static int  const Dmg = 1;
	static bool const FF = true;
	static int  const Points = 0;

private:
	Bullet( void );

};

#endif
