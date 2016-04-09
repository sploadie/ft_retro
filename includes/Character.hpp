/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgauvrit <tgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/09 13:11:03 by sraccah           #+#    #+#             */
/*   Updated: 2016/04/09 17:40:42 by tgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include "Entity.hpp"

class Character : public Entity {

public:
	Character(int row, int col);
	Character(Character const & src);
	Character& operator=(Character const & rhs);
	~Character(void);

	bool	take_damage(int damage);
	int		getHP( void );

	static int const	MaxHP = 50;

private:
	Character(void);

	int		_hp;

};

#endif