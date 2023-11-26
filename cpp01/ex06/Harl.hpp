/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byoshimo <byoshimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 18:59:01 by byoshimo          #+#    #+#             */
/*   Updated: 2023/11/25 19:06:15 by byoshimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP

#include <iostream>

enum	OPTIONS { DEBUG, INFO, WARNING, ERROR};

class Harl
{
	private:
		OPTIONS complain_level;
		std::pair<const char *, void (Harl::*)(void)> levels[4];
		void	debug(void);
		void	info(void);
		void	warning(void);
		void	error(void);
		void	set_level(char *parameter);

	public:
		Harl(char *parameter);
		~Harl(void);

		void	complain(void);
};

#endif