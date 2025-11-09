/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_unbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgumienn <mgumienn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 17:02:58 by mgumienn          #+#    #+#             */
/*   Updated: 2025/10/15 19:03:28 by mgumienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	count_udigits(unsigned int n)
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

int	print_unbr(unsigned int n)
{
	unsigned int	len;
	char			*itoa;

	len = (unsigned int)count_udigits(n);
	itoa = (char *)malloc(sizeof(char) * (len + 1));
	if (!itoa)
		return (0);
	itoa[len] = '\0';
	if (n == 0)
		itoa[0] = '0';
	while (n != 0)
	{
		itoa[len - 1] = (n % 10) + '0';
		n = n / 10;
		len--;
	}
	return (free_str(itoa));
}
