/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbaich <adbaich@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 12:20:52 by adbaich           #+#    #+#             */
/*   Updated: 2022/08/04 12:49:42 by adbaich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

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

void	handler(int num, siginfo_t *info, void *context)
{
	static int	i;
	static int	pid;
	static int	lock;

	context = NULL;
	if (!lock)
	{
		pid = info->si_pid;
		lock = 1;
	}
	if (num == SIGUSR1)
		fill_bits(&i, 0);
	else if (num == SIGUSR2)
		fill_bits(&i, 1);
	i++;
	if (i == 8)
	{
		i = 0;
		write(1, &g_word, 1);
	}
	kill(pid, SIGUSR1);
	usleep(100);
}

int	main(void)
{
	struct sigaction	act;

	act.__sigaction_u.__sa_sigaction = handler;
	act.sa_flags = SA_SIGINFO;
	ft_putnbr_fd(getpid());
	ft_putstr_fd(" <== That's Process ID\n");
	sigaction(SIGUSR1, &act, NULL);
	sigaction(SIGUSR2, &act, NULL);
	while (1)
		pause();
	return (0);
}
