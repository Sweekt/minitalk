/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beroy <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 15:53:30 by beroy             #+#    #+#             */
/*   Updated: 2024/02/19 17:50:11 by beroy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	g_end = 0;

void	ft_reset(int *received, int *bit, unsigned int *len, unsigned char *str)
{
	ft_printf("%s\n", str);
	g_end = 0;
	*received = 0;
	*bit = 0;
	*len = 0;
	free(str);
	str = NULL;
}

void	ft_strcat(unsigned char *str, unsigned char c)
{
	int	i;

	if (c == '\0')
		return (g_end = 1, (void) 0);
	i = 0;
	while (str[i])
		i++;
	str[i] = c;
}

void	fill_string(int sig, int *bit, unsigned char *str)
{
	static unsigned char	c = 0;

	if (sig == SIGUSR1)
		c |= 1 << *bit;
	*bit += 1;
	if (*bit == 8)
	{
		ft_strcat(str, c);
		*bit = 0;
		c = 0;
	}
}

void	sighandler(int sig, siginfo_t *info, void *ucontext)
{
	static int				received = 0;
	static int				bit = 0;
	static unsigned int		len = 0;
	static unsigned char	*str = NULL;

	(void) ucontext;
	if (received == 0)
	{
		get_len(sig, &bit, &len, &received);
		if (received == 1)
			str = ft_calloc(len + 1, sizeof(char));
	}
	else
	{
		fill_string(sig, &bit, str);
		if (g_end == 1)
		{
			ft_reset(&received, &bit, &len, str);
			kill(info->si_pid, SIGUSR2);
		}
	}
	usleep(SLEEP_TIME);
	kill(info->si_pid, SIGUSR1);
}

int	main(void)
{
	int					pid;
	struct sigaction	action;

	pid = getpid();
	action.sa_sigaction = &sighandler;
	action.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &action, NULL);
	sigaction(SIGUSR2, &action, NULL);
	ft_printf("%d\n", pid);
	while (1)
	{
		pause();
	}
}
