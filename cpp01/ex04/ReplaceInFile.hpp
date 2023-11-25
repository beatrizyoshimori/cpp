/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ReplaceInFile.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byoshimo <byoshimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 17:54:32 by byoshimo          #+#    #+#             */
/*   Updated: 2023/11/25 18:41:49 by byoshimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REPLACE_IN_FILE_HPP
# define REPLACE_IN_FILE_HPP

#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <cstdlib>

class ReplaceInFile
{
	private:
		std::ifstream	infile;
		std::ofstream	outfile;
		char			*infile_name;
		char			*outfile_name;

	public:
		ReplaceInFile(char **argv);
		~ReplaceInFile(void);

		void	replace_string(char **argv);
};


#endif