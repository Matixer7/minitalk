/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_nbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgumienn <mgumienn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 18:26:56 by mgumienn          #+#    #+#             */
/*   Updated: 2025/10/15 19:02:44 by mgumienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	count_digits(int n)
{
	int	i;

	i = 0;
	if (n <= 0)
		i++;
	while (n != 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

int	print_nbr(int n)
{
	unsigned int	len;
	unsigned int	nb;
	char			*itoa;

	len = (unsigned int)count_digits(n);
	itoa = (char *)malloc(sizeof(char) * (len + 1));
	if (!itoa)
		return (0);
	itoa[len] = '\0';
	if (n < 0)
	{
		itoa[0] = '-';
		nb = (unsigned int)(-n);
	}
	else
		nb = (unsigned int)n;
	if (nb == 0)
		itoa[0] = '0';
	while (nb != 0)
	{
		itoa[len - 1] = (nb % 10) + '0';
		nb = nb / 10;
		len--;
	}
	return (free_str(itoa));
}
