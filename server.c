/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgumienn <mgumienn@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 17:03:13 by mgumienn          #+#    #+#             */
/*   Updated: 2025/11/08 12:04:55 by mgumienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf/ft_printf.h"
#include "Libft/libft.h"
#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>

char bin[9];

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

void	print_ascii()
{
	char c;

	c = (char)convert_binary_to_ascii(bin);
	ft_printf("%c", c);
	bin[0] = '\0';
}

void	signal_handler(int sig)
{
	char	c;
	int		len;
	
	len = ft_strlen(bin);
	if (sig == SIGUSR1)
		c = '1';
	if (sig == SIGUSR2)
		c = '0';
	bin[len] = c;
	bin[len + 1] = '\0';
	if(ft_strlen(bin) == 8)
		print_ascii();
}

int main(int argc, char const **argv)
{
	pid_t	pid;

	pid = getpid();
	ft_printf("Server Process ID (PID): %d\n", pid);
	
	signal(SIGUSR1, signal_handler);
	signal(SIGUSR2, signal_handler);

	while (1)
	{
		pause();
	}
	
	return (0);
}
