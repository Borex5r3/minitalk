/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbaich <adbaich@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 19:32:17 by adbaich           #+#    #+#             */
/*   Updated: 2022/08/03 12:53:44 by adbaich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	ft_bzero(void *s, size_t n)
{
	char		*p;
	size_t		i;

	i = 0;
	p = (char *) s;
	if (n == 0)
		return ;
	while (i < n)
	{
		p[i] = '\0';
		i++;
	}
}
