/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sraccah <sraccah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/09 13:11:03 by sraccah           #+#    #+#             */
/*   Updated: 2016/01/09 17:19:02 by sraccah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include "main.hpp"

class Character
{
 	public:
		Character(char symbol, int row, int col);
		Character(Character const & src, char symbol, int row, int col);
		Character& operator=(Character const & rhs);
		~Character(void);
		void		print(const char *msg, int nbr);
		char 		getSymbol();
		int 		getRow();
		int 		getCol();
	private:
		char 		_symbol;
		int			_row;
		int			_col;
};

#endif
