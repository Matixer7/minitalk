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

int main(int argc, char **argv)
{
	pid_t server_pid;
	
	if (!argv[1] || !ft_atoi(argv[1]))
		return (ft_printf("Wrong PID format or no PID given"));
		
	int i = 0;
	while(i <= 20)
	{
		server_pid = ft_atoi(argv[1]);
		kill(server_pid, SIGUSR2);
		usleep(100);
		kill(server_pid, SIGUSR1);
		usleep(100);
		kill(server_pid, SIGUSR2);
		usleep(100);
		kill(server_pid, SIGUSR2);
		usleep(100);
		kill(server_pid, SIGUSR2);
		usleep(100);
		kill(server_pid, SIGUSR2);
		usleep(100);
		kill(server_pid, SIGUSR2);
		usleep(100);
		kill(server_pid, SIGUSR1);
		usleep(100);
		i++;
	}
	return 0;
}
