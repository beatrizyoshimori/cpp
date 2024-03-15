/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byoshimo <byoshimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 17:50:10 by byoshimo          #+#    #+#             */
/*   Updated: 2024/03/15 17:50:13 by byoshimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

#include <iostream>
#include <stack>

# define RESET			"\033[0m"
# define RED			"\033[31m"
# define GREEN			"\033[32m"
# define YELLOW			"\033[33m"
# define BLUE			"\033[34m"
# define MAGENTA		"\033[35m"
# define CYAN			"\033[36m"

class RPN
{
	private:
		std::stack<int>	_numbers;

	public:
		RPN(void);
		RPN(const RPN &obj);
		RPN& operator=(const RPN &obj);
		~RPN(void);

		void	rpn(std::string str);
		void	validateParameter(std::string str);
		void	addNumber(char p);
		void	calculate(char p);

		const std::stack<int>	&getNumbers(void) const;
};

#endif