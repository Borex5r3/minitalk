/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbaich <adbaich@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 16:49:10 by adbaich           #+#    #+#             */
/*   Updated: 2022/08/03 12:54:01 by adbaich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

int	ft_putstr_fd(char *p)
{
	int	i;

	i = 0;
	if (!p)
		return (ft_putstr_fd("(null)"));
	while (p[i])
	{
		write(1, &p[i], 1);
		i++;
	}
	return (i);
}
