/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Screen.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgauvrit <tgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/08 17:49:12 by sraccah           #+#    #+#             */
/*   Updated: 2016/04/09 16:07:07 by tgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCREEN_HPP
# define SCREEN_HPP

# include <iostream>
# include <curses.h>

class Screen
{
 	public:
		Screen(void);
		Screen(Screen const & src);
		Screen& operator=(Screen const & rhs);
		~Screen(void);
		void		hello();
		static void	badSize();
		// void	print(const char *msg);
		int		getHeight();
		void	setHeight(int height);
		// int		getWidth();
		// void	setWidth(int width);

		static int const	Width  = 135;
		static int const	Height = 75;

	private:
		// int 	_height;
		// int 	_width;

};

#endif
