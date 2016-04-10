/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Runner.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgauvrit <tgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/10 13:13:27 by sraccah           #+#    #+#             */
/*   Updated: 2016/04/10 17:53:21 by tgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		RUNNER_HPP
# define	RUNNER_HPP

# include "Enemy.hpp"
# include "Character.hpp"

class Runner :  public Enemy{
public:

	Runner( int row, int col );
	Runner( Runner const & obj );

	 ~Runner( void );

	Runner & operator=( Runner const & rhs );

	Runner * clone(void) const;

	void	move( int frame, Character * rhs );

	static int	getCount( void );

	static char const Symbol = 'Y';
	static int  const HP = 1;
	static int  const Dmg = 1;
	static bool const FF = false;
	static int  const Points = 1;

private:
	Runner( void );
	int _direction;

	static int	_Count;
};
 #endif
