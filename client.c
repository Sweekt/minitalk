/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beroy <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 13:50:00 by beroy             #+#    #+#             */
/*   Updated: 2024/02/19 17:25:35 by beroy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_received(int sig)
{
	if (sig == SIGUSR2)
		ft_printf("Message received by server!\n");
}

void	ft_send_null(int pid)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		usleep(SLEEP_TIME);
		kill(pid, SIGUSR2);
		pause();
		i++;
	}
}

void	ft_send_len(unsigned int len, int pid)
{
	int	i;

	i = 0;
	while (i < 32)
	{
		usleep(SLEEP_TIME);
		if (!(len & (1 << i)))
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		if (i != 31)
			pause();
		i++;
	}
}

void	ft_send_char(char *str, int pid)
{
	int	i;
	int	bit;

	i = 0;
	bit = 0;
	while (str[i])
	{
		usleep(SLEEP_TIME);
		if (!(str[i] & (1 << bit)))
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		bit++;
		if (bit == 8)
		{
			bit = 0;
			i++;
		}
		pause();
	}
}

int	main(int ac, char **av)
{
	int	pid;

	if (ac != 3)
		return (0);
	pid = ft_atoi(av[1]);
	signal(SIGUSR1, ft_received);
	signal(SIGUSR2, ft_received);
	ft_send_len(ft_strlen(av[2]), pid);
	ft_send_char(av[2], pid);
	ft_send_null(pid);
	return (0);
}
