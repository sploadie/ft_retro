/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fighter.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgauvrit <tgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/09 14:52:31 by tgauvrit          #+#    #+#             */
/*   Updated: 2016/04/10 17:35:39 by tgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIGHTER_H
# define FIGHTER_H

# include "Enemy.hpp"
# include "Character.hpp"
# include "Laser.hpp"

class Fighter : public Enemy {

public:

	Fighter( int row, int col );
	Fighter( Fighter const & obj );

	virtual ~Fighter( void );

	Fighter & operator=( Fighter const & rhs );

	Fighter * clone( void ) const;

	void	spawn( int frame, Character * rhs, Squad * squad );
	void	move( int frame, Character * rhs );

	static int	getCount( void );

	static char const Symbol = 'w';
	static int  const HP = 2;
	static int  const Dmg = 2;
	static bool const FF = false;
	static int  const Points = 3;

private:
	Fighter( void );

	static int	_Count;
};

#endif
