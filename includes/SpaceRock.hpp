/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SpaceRock.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgauvrit <tgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/09 14:52:31 by tgauvrit          #+#    #+#             */
/*   Updated: 2016/04/10 17:53:20 by tgauvrit         ###   ########.fr       */
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

	static int	getCount( void );

	static char const Symbol = '@';
	static int  const HP = 1;
	static int  const Dmg = 0;
	static bool const FF = true;
	static int  const Points = 0;

private:
	SpaceRock( void );

	static int	_Count;
};

#endif
