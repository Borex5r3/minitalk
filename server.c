/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbaich <adbaich@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 15:31:17 by adbaich           #+#    #+#             */
/*   Updated: 2022/02/11 22:17:58 by adbaich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>
#include<signal.h>
#include<stdio.h>
#include "minitalk.h"

t_vars	g_word;

void	fill_bits(int *i, int n)
{
	if (*i == 0)
		g_word.bit1 = n;
	else if (*i == 1)
		g_word.bit2 = n;
	else if (*i == 2)
		g_word.bit3 = n;
	else if (*i == 3)
		g_word.bit4 = n;
	else if (*i == 4)
		g_word.bit5 = n;
	else if (*i == 5)
		g_word.bit6 = n;
	else if (*i == 6)
		g_word.bit7 = n;
	else if (*i == 7)
		g_word.bit8 = n;
}

void	hander(int num)
{
	static int	i;

	if (num == SIGUSR1)
	{
		fill_bits(&i, 0);
	}
	else if (num == SIGUSR2)
		fill_bits(&i, 1);
	i++;
	if (i == 8)
	{
		i = 0;
		write(1, &g_word, 1);
	}
}

int	main(void)
{
	ft_putnbr_fd(getpid());
	ft_putstr_fd(" <== That's Process ID\n");
	signal(SIGUSR1, hander);
	signal(SIGUSR2, hander);
	while (1)
		pause();
}
