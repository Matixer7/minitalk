/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgumienn <mgumienn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 16:54:36 by mgumienn          #+#    #+#             */
/*   Updated: 2025/10/15 19:03:47 by mgumienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	check_params(va_list args, const char *params, int i)
{
	if (params[i] == 'c')
		return (print_chr(va_arg(args, int)));
	if (params[i] == 's')
		return (print_str(va_arg(args, char *)));
	if (params[i] == 'p')
		return (print_adr((unsigned long)va_arg(args, void *)));
	if (params[i] == 'd')
		return (print_nbr(va_arg(args, int)));
	if (params[i] == 'i')
		return (print_nbr(va_arg(args, int)));
	if (params[i] == 'u')
		return (print_unbr(va_arg(args, unsigned int)));
	if (params[i] == 'x')
		return (print_lowerhex(va_arg(args, int)));
	if (params[i] == 'X')
		return (print_upperhex(va_arg(args, int)));
	if (params[i] == '%')
		return (write(1, "%%", 1));
	return (0);
}

int	ft_printf(const char *params, ...)
{
	va_list	args;
	int		i;
	int		count;

	va_start(args, params);
	i = 0;
	count = 0;
	while (params[i])
	{
		if (params[i] == '%')
		{
			i++;
			count += check_params(args, params, i);
		}
		else
		{
			write(1, &params[i], 1);
			count++;
		}
		i++;
	}
	va_end(args);
	return (count);
}

// #include <stdio.h>

// int main(int argc, char const *argv[])
// {
// 	int f;
// 	int ft;

// 	f = printf("- %x ", 0);
// 	printf("\n");
// 	ft = ft_printf("= %x ", 0);
// 	ft_printf("\n");

// 	ft_printf("======\nPrintf: %d\nft_printf: %d\n======\n", f, ft);
// 	return 0;
// }
