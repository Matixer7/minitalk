/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_adr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgumienn <mgumienn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 18:53:47 by mgumienn          #+#    #+#             */
/*   Updated: 2025/10/15 18:50:31 by mgumienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_adr(unsigned long p)
{
	int		len;
	int		i;
	char	buffer[17];
	char	*hex;

	len = 0;
	i = 16;
	hex = "0123456789abcdef";
	if (p == 0)
		return (write(1, "(nil)", 5));
	len += write(1, "0x", 2);
	buffer[16] = '\0';
	while (p)
	{
		i--;
		buffer[i] = hex[p % 16];
		p = p / 16;
	}
	len += write(1, &buffer[i], 16 - i);
	return (len);
}
