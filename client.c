/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbaich <adbaich@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 15:31:36 by adbaich           #+#    #+#             */
/*   Updated: 2022/02/09 22:42:54 by adbaich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>
#include<signal.h>
#include<stdio.h>
#include "minitalk.h"

int	main(int ac, char **av)
{
    int pid;
    int rem;
    char    asciiInput;
    int     k;
    int     j;

    
    j = 0;
	if (ac == 3)
    {
        
        pid = ft_atoi(av[1]);
        while(av[2][j])
        {
            asciiInput = av[2][j];
            k = 0;
	        while (k <= 7)
	        {    
                rem = asciiInput % 2;
                if (rem == 0)
                    kill(pid, SIGUSR1);
                else if (rem == 1)
                    kill(pid, SIGUSR2);
                usleep(100);
	            asciiInput = asciiInput / 2;
                k++;
            }
            j++;
        }
    }
    return (0);
}
