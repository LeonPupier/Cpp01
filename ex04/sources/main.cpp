/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpupier <lpupier@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 14:50:51 by lpupier           #+#    #+#             */
/*   Updated: 2023/05/16 08:30:37 by lpupier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>

int	main(int argc, char **argv)
{
	std::ifstream	ifs;
	std::ofstream	ofs;
	std::string		content;
	size_t			ptr;

	if (argc != 4)
	{
		std::cout << "[WARNING] Please give the correct number of arguments..." << std::endl;
		return (1);
	}

	ifs.open(argv[1], std::ifstream::in);
	ofs.open((std::string(argv[1]) += ".replace").c_str(), std::ifstream::out);
	if (ifs.fail() || ofs.fail())
	{
		std::cout << "[ERROR] The specified file could not be opened..." << std::endl;
		return (1);
	}

	while (true)
	{
		std::getline(ifs, content);
		while (true)
		{
			ptr = content.find(argv[2]);
			if (ptr != std::string::npos)
			{
				ofs << content.substr(0, ptr) << argv[3];
				content = content.substr(ptr + std::string(argv[3]).size());
			}
			else
			{
				ofs << content;
				break ;
			}
		}

		if (ifs.eof())
				break ;
		ofs << std::endl;
	}

	ifs.close();
	return (0);
}
