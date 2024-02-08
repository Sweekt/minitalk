/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beroy <beroy@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 13:50:00 by beroy             #+#    #+#             */
/*   Updated: 2024/02/08 13:37:10 by beroy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_isdigit(int c)
{
	if (c < 48 || c > 57)
		return (0);
	return (1);
}

int	ft_atoi(const char *nptr)
{
	int	i;
	int	res;
	int	sign;

	i = 0;
	res = 0;
	sign = 1;
	while ((nptr[i] > 8 && nptr[i] < 14) || nptr[i] == ' ')
		i++;
	if (nptr[i] == '+')
		i++;
	else if (nptr[i] == '-')
	{
		sign *= -1;
		i++;
	}
	while (ft_isdigit(nptr[i]) == 1)
	{
		res = res * 10 + (nptr[i] - 48);
		i++;
	}
	return (res * sign);
}

void	ft_received(int sig)
{
	if (sig == SIGUSR2)
		ft_printf("Message received by server!\n");
}

int	main(int ac, char **av)
{
	int	i;
	int bit;
	int pid;

	if (ac != 3)
		return (0);
	i = 0;
	bit = 0;
	pid = ft_atoi(av[1]);
	signal(SIGUSR1, ft_received);
	signal(SIGUSR2, ft_received);
	while (av[2][i])
	{
		if ((av[2][i] & 1 << bit) == 1 << bit)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		bit++;
		if (bit == 8)
		{
			bit = 0;
			i++;
		}
		ft_printf("a\n");
		//usleep(100);
		pause();
		ft_printf("b\n");
	}
	return (0);
}