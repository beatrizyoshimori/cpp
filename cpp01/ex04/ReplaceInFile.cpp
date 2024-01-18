/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ReplaceInFile.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byoshimo <byoshimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 17:56:03 by byoshimo          #+#    #+#             */
/*   Updated: 2024/01/17 17:32:21 by byoshimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ReplaceInFile.hpp"

ReplaceInFile::ReplaceInFile(char **argv)
{
	this->_infile_name = argv[1];
	this->_infile.open(this->_infile_name, std::ifstream::in);
	if (_infile.rdstate())
	{
		std::cout << "Could not open file!" << std::endl;
		exit(1);
	}
	std::string	filename(argv[1]);
	filename += ".replace";
	this->_outfile_name = &filename[0];
	this->_outfile.open(this->_outfile_name, std::ofstream::out);
}

ReplaceInFile::~ReplaceInFile()
{
	this->_infile.close();
	this->_outfile.close();
	return ;
}

void	ReplaceInFile::replace_string(char **argv)
{
	std::string	line;
	size_t		position;

	while (std::getline(this->_infile, line))
	{
		if (strcmp(argv[2], argv[3]) != 0)
		{
			position = line.find(argv[2]);
			while (position != std::string::npos)
			{
				line.insert(position, argv[3]);
				line.erase(position + std::strlen(argv[3]), std::strlen(argv[2]));
				position = line.find(argv[2]);
			}
		}
		this->_outfile << line;
		this->_outfile << std::endl;
	}
}
