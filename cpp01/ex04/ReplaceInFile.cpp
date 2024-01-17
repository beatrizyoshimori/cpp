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
	this->infile_name = argv[1];
	this->infile.open(this->infile_name, std::ifstream::in);
	if (infile.rdstate())
	{
		std::cout << "Could not open file!" << std::endl;
		this->infile.close();
		exit(1);
	}
	std::string	filename(argv[1]);
	filename += ".replace";
	this->outfile_name = &filename[0];
	this->outfile.open(this->outfile_name, std::ofstream::out);
}

ReplaceInFile::~ReplaceInFile()
{
	this->infile.close();
	this->outfile.close();
	return ;
}


void	ReplaceInFile::replace_string(char **argv)
{
	std::string	line;
	size_t		position;

	while (std::getline(this->infile, line))
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
		this->outfile << line;
		this->outfile << std::endl;
	}
}
