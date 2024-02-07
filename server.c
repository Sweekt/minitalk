/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beroy <beroy@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 15:53:30 by beroy             #+#    #+#             */
/*   Updated: 2024/02/07 18:22:40 by beroy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	g_bit = 0;

void	sighandler(int sig, siginfo_t *info, void *ucontext)
{
	(void) ucontext;
	int client_pid;

	client_pid = info->si_pid;
	if
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
