/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbaich <adbaich@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 15:31:17 by adbaich           #+#    #+#             */
/*   Updated: 2022/02/09 22:42:21 by adbaich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>
#include<signal.h>
#include<stdio.h>
#include "minitalk.h"

t_vars	word;

void	fill_bits(int *i, int n)
{
	if (*i == 0)
		word.bit1 = n;
	else if (*i == 1)
		word.bit2 = n;
	else if (*i == 2)
		word.bit3 = n;
	else if (*i == 3)
		word.bit4 = n;
	else if (*i == 4)
		word.bit5 = n;
	else if (*i == 5)
		word.bit6 = n;
	else if (*i == 6)
		word.bit7 = n;
	else if (*i == 7)
		word.bit8 = n;
}

void	hander(int num)
{
	static int	i = 0;
	
	if (num == SIGUSR1)
		fill_bits(&i, 0);
	else if (num == SIGUSR2)
		fill_bits(&i, 1);
	i++;
	if (i == 8)
	{
		i = 0;
		write(1, &word, 1);
	}
}

int	main()
{
	printf("That's Process ID ==> %d\n", getpid());
	signal(SIGUSR1, hander);
	signal(SIGUSR2, hander);
	
	while(1)	
		pause();
	
}
