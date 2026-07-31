/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnieto-m <mnieto-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/18 12:14:49 by mnieto-m          #+#    #+#             */
/*   Updated: 2026/07/30 20:04:44 by mnieto-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Zombie.hpp"

int main()
{
	int N = 9;
	Zombie *horde = zombieHorde(N,  "clap");	
	for	(int i = 0; i < N; i++)
	{
	horde[i].announce();
	}
	delete [] horde;
}		