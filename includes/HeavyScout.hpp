/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HeavyScout.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sraccah <sraccah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/09 14:52:31 by tgauvrit          #+#    #+#             */
/*   Updated: 2016/04/10 14:09:28 by sraccah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEAVYSCOUT_H
# define HEAVYSCOUT_H

# include "Enemy.hpp"
# include "Character.hpp"

class HeavyScout : public Enemy {

public:

	HeavyScout( int row, int col );
	HeavyScout( HeavyScout const & obj );

	virtual ~HeavyScout( void );

	HeavyScout & operator=( HeavyScout const & rhs );

	HeavyScout * clone(void) const;

	void	move( int frame, Character * rhs );

	static char const Symbol = 'V';
	static int  const HP = 2;
	static int  const Dmg = 2;
	static bool const FF = false;
	static int  const Points = 2;

private:
	HeavyScout( void );

};

#endif
