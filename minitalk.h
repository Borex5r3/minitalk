/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbaich <adbaich@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 15:41:47 by adbaich           #+#    #+#             */
/*   Updated: 2022/02/10 01:29:38 by adbaich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H
# include<signal.h>
# include <stdio.h>
# include <stdio.h>
# include <stdlib.h>

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

int		ft_atoi(const char *str);
void	ft_bzero(void *s, size_t n);

#endif