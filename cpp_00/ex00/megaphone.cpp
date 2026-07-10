/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mario <mario@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 23:48:46 by mnieto-m          #+#    #+#             */
/*   Updated: 2026/07/07 19:20:53 by mario            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cctype>  
#include <cstring>

static void megaphone(int argc, char **argv)
{
	for(int i = 1; i < argc; i++)
	{
		for(int j = 0; j < (int)std::strlen(argv[i]);j++)
		{
			std::cout << (char)std::toupper(argv[i][j]);
		}
	}
	std::cout << std::endl;
}

int main(int argc, char **argv)
{
	if(argc > 1)
		megaphone(argc, argv);
	else
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n";
	return(0);
}