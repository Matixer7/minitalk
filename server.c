/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgumienn <mgumienn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 17:03:13 by mgumienn          #+#    #+#             */
/*   Updated: 2025/11/09 14:38:48 by mgumienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf/ft_printf.h"
#include "Libft/libft.h"
#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>

char	g_bin[9];

int	convert_binary_to_ascii(char *binary)
{
	int	i;
	int	ascii;

	i = 0;
	ascii = 0;
	while (i < 8)
	{
		ascii = ascii * 2 + (binary[i] - '0');
		i++;
	}
	return (ascii);
}

void	print_ascii(void)
{
	char	c;

	c = (char)convert_binary_to_ascii(g_bin);
	ft_printf("%c", c);
	g_bin[0] = '\0';
}

void	signal_handler(int sig)
{
	char	c;
	int		len;

	len = ft_strlen(g_bin);
	if (sig == SIGUSR1)
		c = '1';
	if (sig == SIGUSR2)
		c = '0';
	g_bin[len] = c;
	g_bin[len + 1] = '\0';
	if (ft_strlen(g_bin) == 8)
		print_ascii();
}

int	main(void)
{
	pid_t	pid;

	pid = getpid();
	ft_printf("Server Process ID (PID): %d\n", pid);
	signal(SIGUSR1, signal_handler);
	signal(SIGUSR2, signal_handler);
	while (1)
		;
	return (0);
}
