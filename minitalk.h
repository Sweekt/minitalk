/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beroy <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 15:53:45 by beroy             #+#    #+#             */
/*   Updated: 2024/02/19 17:49:51 by beroy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <stdarg.h>
# include <unistd.h>
# include <limits.h>
# include <signal.h>
# include <stdlib.h>
# include <stdint.h>

# define SLEEP_TIME 100

// minitalk_utils

void	get_len(int sig, int *bit, unsigned int *len, int *received);
void	*ft_calloc(size_t nmemb, size_t size);
int		ft_isdigit(int c);
int		ft_atoi(const char *nptr);

// ft_printf

int		ft_printf(const char *str, ...);

// ft_printf_utils

ssize_t	ft_putchar(int c);
ssize_t	ft_putstr(char *str);
void	ft_putnbr_base(ssize_t nbr, char *str, ssize_t *length);
void	ft_putnbr_ul(size_t nbr, char *str, ssize_t *length);
size_t	ft_strlen(char *str);

#endif