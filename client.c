/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbaich <adbaich@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 15:31:36 by adbaich           #+#    #+#             */
/*   Updated: 2022/08/02 22:07:02 by adbaich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_sig(char ascii, int pid)
{
	int	k;

	k = 0;
	while (k <= 7)
	{
		if (((ascii >> k) & 1) == 0)
			kill(pid, SIGUSR1);
		else if (((ascii >> k) & 1) == 1)
			kill(pid, SIGUSR2);
		usleep(100);
		k++;
	}
}

int	main(int ac, char **av)
{
	int		pid;
	char	ascii;
	int		j;

	j = 0;
	if (ac == 3)
	{
		pid = ft_atoi(av[1]);
		if (pid <= 0)
			return (0);
		while (av[2][j])
		{
			ascii = av[2][j];
			send_sig(ascii, pid);
			j++;
		}
	}
	return (0);
}
