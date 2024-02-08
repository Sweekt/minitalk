/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beroy <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 15:53:45 by beroy             #+#    #+#             */
/*   Updated: 2024/02/02 15:57:12 by beroy            ###   ########.fr       */
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

// ft_printf

int		ft_printf(const char *str, ...);
void	*ft_calloc(size_t nmemb, size_t size);

// ft_printf Utils

ssize_t	ft_putchar(int c);
ssize_t	ft_putstr(char *str);
void	ft_putnbr_base(ssize_t nbr, char *str, ssize_t *length);
void	ft_putnbr_ul(size_t nbr, char *str, ssize_t *length);

#endif