/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SpaceRock.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sraccah <sraccah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/09 14:52:31 by tgauvrit          #+#    #+#             */
/*   Updated: 2016/04/10 14:09:23 by sraccah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPACEROCK_H
# define SPACEROCK_H

# include "Enemy.hpp"
# include "Character.hpp"

class SpaceRock : public Enemy {

public:

	SpaceRock( int row, int col );
	SpaceRock( SpaceRock const & obj );

	virtual ~SpaceRock( void );

	SpaceRock & operator=( SpaceRock const & rhs );

	SpaceRock * clone(void) const;

	void	move( int frame, Character * rhs );
	void	collide( Enemy * rhs );
	void	hit_player( Character * rhs );

	static char const Symbol = '@';
	static int  const HP = 1;
	static int  const Dmg = 0;
	static bool const FF = true;
	static int  const Points = 1;

private:
	SpaceRock( void );

};

#endif
