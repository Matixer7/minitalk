/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgumienn <mgumienn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 17:03:11 by mgumienn          #+#    #+#             */
/*   Updated: 2025/11/09 14:53:08 by mgumienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf/ft_printf.h"
#include "Libft/libft.h"
#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>

int	send_signal(char *binary, pid_t server_pid )
{
	int	i;

	i = 0;
	while (i < 8)
	{
		if (binary[i] == '1')
		{
			if (kill(server_pid, SIGUSR1) == -1)
				return (-1);
		}
		if (binary[i] == '0')
		{
			if (kill(server_pid, SIGUSR2) == -1)
				return (-1);
		}
		i++;
	}
	return (0);
}

int	ascii_to_binary(int c, pid_t server_pid)
{
	char	binary[9];
	int		i;

	i = 0;
	while (i < 8)
	{
		binary[7 - i] = c % 2 + '0';
		c = c / 2;
		i++;
	}
	binary[8] = '\0';
	if (send_signal(binary, server_pid) == -1)
		return (-1);
	return (0);
}

int	validate_and_send_msg(char *argv, pid_t server_pid)
{
	ssize_t	i;

	i = 0;
	while (argv[i])
	{
		if (ft_isascii(argv[i]))
		{
			if (ascii_to_binary(argv[i], server_pid) == -1)
				return (-1);
		}
		else
		{
			if (ascii_to_binary('?', server_pid) == -1)
				return (-1);
			ft_printf("Not ASCII symbol found, replaced with '?'\n");
			i++;
		}
		i++;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	pid_t	server_pid;
	int		j;

	if (!argv[1] || !ft_atoi(argv[1]) || ft_atoi(argv[1]) <= 0)
		return (ft_printf("Wrong PID format or no PID given\n"));
	server_pid = ft_atoi(argv[1]);
	if (argc <= 2)
		return (ft_printf("Nothing to send :c\n"));
	j = 2;
	while (argv[j])
	{
		if (validate_and_send_msg(argv[j], server_pid) == -1)
			return (ft_printf("Error has occured while sending\n"));
		j++;
		if (ascii_to_binary(' ', server_pid) == -1)
			return (-1);
	}
	if (ascii_to_binary('\n', server_pid) == -1)
		return (ft_printf("Error has occured while sending\n"));
	return (0);
}
