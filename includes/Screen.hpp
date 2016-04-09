/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Screen.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sraccah <sraccah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/08 17:49:12 by sraccah           #+#    #+#             */
/*   Updated: 2016/01/09 17:18:54 by sraccah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCREEN_HPP
# define SCREEN_HPP

# include "main.hpp"

class Screen
{
 	public:
		Screen(void);
		Screen(Screen const & src);
		Screen& operator=(Screen const & rhs);
		~Screen(void);
		void	hello();
		void	print(const char *msg);
		int		getHeight();
		void	setHeight(int height);
		int		getWidth();
		void	setWidth(int width);
	private:
		int 	_height;
		int 	_width;
};

#endif
