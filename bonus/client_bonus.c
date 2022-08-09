/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbaich <adbaich@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 12:18:11 by adbaich           #+#    #+#             */
/*   Updated: 2022/08/04 14:26:11 by adbaich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

t_varsc	g_word;

void	send_sig(char ascii, int pid)
{
	static int	k;

	if (k <= 7)
	{
		if (((ascii >> k) & 1) == 0)
			kill(pid, SIGUSR1);
		else if (((ascii >> k) & 1) == 1)
			kill(pid, SIGUSR2);
		usleep(100);
		k++;
		g_word.k = k;
		if (k == 8)
			k = 0;
	}
}

void	handler(int num)
{
	char		ascii;
	static int	j;

	if (g_word.text[j] && num == SIGUSR1)
	{
		ascii = g_word.text[j];
		send_sig(ascii, g_word.pid);
		if (g_word.k == 8)
			j++;
		g_word.j = j;
	}
	else
		exit(0);
}

int	main(int ac, char **av)
{
	int		pid;
	int		j;

	j = 0;
	signal(SIGUSR1, handler);
	if (ac == 3)
	{
		pid = ft_atoi(av[1]);
		if (pid <= 0)
			return (0);
		g_word.text = av[2];
		g_word.pid = pid;
		kill(getpid(), SIGUSR1);
		while (1)
			pause();
	}
	return (0);
}
