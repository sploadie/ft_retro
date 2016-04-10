/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Coffee.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgauvrit <tgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/09 14:52:31 by tgauvrit          #+#    #+#             */
/*   Updated: 2016/04/10 20:59:33 by tgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COFFEE_H
# define COFFEE_H

# include "Enemy.hpp"
# include "Character.hpp"

class Coffee : public Enemy {

public:

	Coffee( int row, int col );
	Coffee( Coffee const & obj );

	virtual ~Coffee( void );

	Coffee & operator=( Coffee const & rhs );

	Coffee * clone(void) const;

	void	draw( void ) const;

	void	move( int frame, Character * rhs );

	static int	getCount( void );

	static char const Symbol = '+';
	static int  const HP = 3;
	static int  const Dmg = -1;
	static bool const FF = false;
	static int  const Points = 5;

private:
	Coffee( void );

	static int	_Count;
};

#endif
