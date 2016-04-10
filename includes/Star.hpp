/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Star.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgauvrit <tgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/09 14:52:31 by tgauvrit          #+#    #+#             */
/*   Updated: 2016/04/10 15:50:01 by tgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STAR_H
# define STAR_H

# include "Enemy.hpp"
# include "Character.hpp"

class Star : public Enemy {

public:

	Star( int row, int col );
	Star( Star const & obj );

	virtual ~Star( void );

	Star & operator=( Star const & rhs );

	Star * clone(void) const;

	void	draw(void) const;
	void	move( int frame, Character * rhs );

	static char const Symbol = '|';
	static int  const HP = 1;
	static int  const Dmg = 1;
	static bool const FF = true;
	static int  const Points = 0;

private:
	Star( void );

};

#endif
