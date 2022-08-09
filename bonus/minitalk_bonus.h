/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbaich <adbaich@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 12:18:57 by adbaich           #+#    #+#             */
/*   Updated: 2022/08/03 12:51:01 by adbaich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_BONUS_H
# define MINITALK_BONUS_H
# include <signal.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_vars
{
	int	bit1: 1;
	int	bit2: 1;
	int	bit3: 1;
	int	bit4: 1;
	int	bit5: 1;
	int	bit6: 1;
	int	bit7: 1;
	int	bit8: 1;
}	t_vars;

typedef struct s_varsc
{
	char	*text;
	int		pid;
	int		k;
	int		j;
}	t_varsc;

int		ft_atoi(const char *str);
void	ft_bzero(void *s, size_t n);
int		ft_putstr_fd(char *p);
int		ft_putnbr_fd(int n);

#endif