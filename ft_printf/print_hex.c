/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgumienn <mgumienn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 17:04:06 by mgumienn          #+#    #+#             */
/*   Updated: 2025/10/15 19:02:22 by mgumienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_lowerhex(int n)
{
	int				i;
	char			buffer[17];
	char			*hex;
	unsigned int	un;

	if (n == 0)
		return (write(1, "0", 1));
	i = 16;
	un = (unsigned int)n;
	hex = "0123456789abcdef";
	buffer[16] = '\0';
	while (un > 0)
	{
		i--;
		buffer[i] = hex[un % 16];
		un = un / 16;
	}
	return (write(1, &buffer[i], 16 - i));
}

int	print_upperhex(int n)
{
	int				i;
	char			buffer[17];
	char			*hex;
	unsigned int	un;

	if (n == 0)
		return (write(1, "0", 1));
	i = 16;
	un = (unsigned int)n;
	hex = "0123456789ABCDEF";
	buffer[16] = '\0';
	while (un > 0)
	{
		i--;
		buffer[i] = hex[un % 16];
		un = un / 16;
	}
	return (write(1, &buffer[i], 16 - i));
}
