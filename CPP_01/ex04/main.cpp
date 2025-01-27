/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaintho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 15:44:30 by jsaintho          #+#    #+#             */
/*   Updated: 2024/09/12 17:01:33 by jsaintho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>

int	replace_all(std::string str, std::string file_name,
		std::string new_w, std::string old_w)
{
	std::ofstream	outfile;
	const int		old_w_len = (const int) old_w.size() - 1;

	outfile.open((std::string(file_name) + ".replace").c_str());
	if(outfile.fail())
		return (1);

	for(int i = 0; i < (int)str.size(); i++)
	{
		// std::cout << "--" << str[i] << "--" << std::endl;
		size_t pos = str.find(old_w, i);
		if((int)pos != -1 && (int)pos == i)
		{
			outfile << new_w;
			i += (int) old_w_len;
		}
		else
			outfile << str[i];
	}
	return (0);
}

int	main(int argc, char **av)
{
	std::ifstream	infile;
	std::string		file_content;
	char			c;

	if(argc != 4)
	{
		std::cout << "usage: replace <file> old_word new_word" << std::endl;
		return (1);
	}
	infile.open(av[1]);
	if(infile.fail())
	{
		std::cout << "Error :" << av[1] << " No such file or directory !" << std::endl;
		return (1);
	}
	while(!infile.eof() && infile >> std::noskipws >> c)
		file_content += c;

	infile.close();
	return( replace_all(file_content, av[1], std::string(av[3]), std::string(av[2])) );
}
