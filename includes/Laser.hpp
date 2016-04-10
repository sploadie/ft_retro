/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Laser.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgauvrit <tgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/09 14:52:31 by tgauvrit          #+#    #+#             */
/*   Updated: 2016/04/10 13:26:31 by tgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LASER_H
# define LASER_H

# include "Enemy.hpp"
# include "Character.hpp"

class Laser : public Enemy {

public:

	Laser( int row, int col );
	Laser( Laser const & obj );

	virtual ~Laser( void );

	Laser & operator=( Laser const & rhs );

	Laser * clone(void) const;

	void	move( int frame, Character * rhs );

	static char const Symbol = '.';
	static int  const HP = 1;
	static int  const Dmg = 1;
	static bool const FF = false;
	static int  const Points = 0;

private:
	Laser( void );

};

#endif
