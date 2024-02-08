/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beroy <beroy@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 15:53:30 by beroy             #+#    #+#             */
/*   Updated: 2024/02/08 13:34:16 by beroy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int g_end = 0;

void	ft_strcat(char *str, char c)
{
	int i;

	if (c == 0)
		return (g_end = 1, (void) 0);
	i = 0;
	while (str[i])
		i++;
	str[i] = c;
}

void fill_string(int sig, int *bit, char *str)
{
	static char	c = 0;

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

char	*str_malloc(int sig, int *bit, int *len)
{
	char	*str;

	if (sig == SIGUSR1)
		*len |= 1 << *bit;
	*bit += 1;
	if (*bit == 32)
	{
		str = ft_calloc(sizeof(char), *len + 1);
		return (*bit = 0, *len = 0,str);
	}
	return (NULL);
}

void	sighandler(int sig, siginfo_t *info, void *ucontext)
{
	static int	received = 0;
	static int	bit = 0;
	static int	len = 0;
	static char	*str = NULL;

	(void) ucontext;
	ft_printf("a\n");
	if (received == 0)
	{
		str = str_malloc(sig, &bit, &len);
		if (str != NULL)
			received = 1;
	}
	else
	{
		fill_string(sig, &bit, str);
		if (g_end == 1)
		{
			ft_printf("%s\n", str);
			g_end = 0;
			received = 0;
		}
	}
	kill(info->si_pid, SIGUSR1);
	ft_printf("b\n");
}

int	main(void)
{
	int	pid;
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
