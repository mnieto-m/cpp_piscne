/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnieto-m <mnieto-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 23:48:46 by mnieto-m          #+#    #+#             */
/*   Updated: 2026/06/12 00:03:11 by mnieto-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cctype>  
#include <cstring>

static void megaphone(int argc, char **argv)
{
	int i = 1;
	int j = 0;
	
}

int main(int argc, char **argv)
{
	if(argc > 1)
		megaphone(argc, argv);
	else
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n" << std::;
	return(0);
}