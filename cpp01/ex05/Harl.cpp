/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byoshimo <byoshimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 18:58:49 by byoshimo          #+#    #+#             */
/*   Updated: 2023/11/25 19:05:44 by byoshimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl(void)
{
	this->levels[0] = std::make_pair("DEBUG", &Harl::debug);
	this->levels[1] = std::make_pair("INFO", &Harl::info);
	this->levels[2] = std::make_pair("WARNING", &Harl::warning);
	this->levels[3] = std::make_pair("ERROR", &Harl::error);
	return ;
}

Harl::~Harl(void)
{
	return ;
}

void	print_complain(std::string level, std::string complain)
{
	std::cout << "[ " << level << " ]" << std::endl << complain << std::endl << std::endl;
}

void	Harl::debug( void )
{
	print_complain("DEBUG", "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!");
}

void	Harl::info( void )
{
	print_complain("INFO", "I cannot believe adding extra bacon costs more money. You didn't put enough bacon in my burger! If you did, I wouldn't be asking for more!");
}

void	Harl::warning( void )
{
	print_complain("WARNING", "I think I deserve to have some extra bacon for free. I've been coming for years whereas you started working here since last month.");
}

void	Harl::error( void )
{
	print_complain("ERROR", "This is unacceptable! I want to speak to the manager now.");
}

void	Harl::complain( std::string level )
{
	for (int i = 0; i < 4; i++)
	{
		if (level == this->levels[i].first)
		{
			(this->*levels[i].second)();
			return ;
		}
	}
}
