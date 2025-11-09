/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgumienn <mgumienn@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 17:03:11 by mgumienn          #+#    #+#             */
/*   Updated: 2025/11/06 18:56:100 by mgumienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf/ft_printf.h"
#include "Libft/libft.h"
#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>

void	send_signal (char *binary, pid_t server_pid )
{
	int i;
	int len;

	i = 0;
	len = ft_strlen(binary);
	while (i < 8)
	{
		if (binary[i] == '1')
			kill(server_pid, SIGUSR1);
		if (binary[i] == '0')
			kill(server_pid, SIGUSR2);
		usleep(50);
		i++;
	}
}

void	ascii_to_binary (int c, pid_t server_pid)
{
	char binary[9];
	int i;
	
	i = 0;
	while (i < 8)
	{
		binary[7 - i] = c % 2 + '0';
		c = c / 2;
		i++;
	}
	binary[8] = '\0';
	send_signal(binary, server_pid);
}

int main(int argc, char **argv)
{
	pid_t server_pid;
	int i;
	int j;
	
	if (!argv[1] || !ft_atoi(argv[1]))
		return (ft_printf("Wrong PID format or no PID given\n"));
	server_pid = ft_atoi(argv[1]);
	if (!argv[2])
		return (ft_printf("Nothing to send :c\n"));
	i = 0;
	j = 2;
	while(argv[j])
	{
		while (argv[j][i])
		{
			if (ft_isascii(argv[j][i]))
				ascii_to_binary(argv[j][i], server_pid);
			else
			{
				ascii_to_binary('?', server_pid);
				ft_printf("Error: found something not from ASCII, replaced with question mark\n");
			}
			i++;
		}
		j++;
		ascii_to_binary(' ', server_pid);
		i = 0;
	}
	ascii_to_binary('\n', server_pid);
	return (0);
}
