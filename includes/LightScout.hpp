/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   LightScout.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgauvrit <tgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/09 14:52:31 by tgauvrit          #+#    #+#             */
/*   Updated: 2016/04/10 10:02:44 by tgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIGHTSCOUT_H
# define LIGHTSCOUT_H

# include "Enemy.hpp"
# include "Character.hpp"

class LightScout : public Enemy {

public:

	LightScout( int row, int col );
	LightScout( LightScout const & obj );

	virtual ~LightScout( void );

	LightScout & operator=( LightScout const & rhs );

	LightScout * clone(void) const;

	void	move( int frame, Character * rhs );

	static char const Symbol = 'v';
	static int  const HP = 1;
	static int  const Dmg = 1;
	static bool const FF = false;

private:
	LightScout( void );

};

#endif
