/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgumienn <mgumienn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 19:04:27 by mgumienn          #+#    #+#             */
/*   Updated: 2025/10/15 19:05:14 by mgumienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

int	ft_printf(const char *params, ...);
int	print_str(char *str);
int	print_adr(unsigned long p);
int	print_chr(char c);
int	print_upperhex(int n);
int	print_lowerhex(int n);
int	print_nbr(int n);
int	print_unbr(unsigned int n);
int	free_str(char *str);

#endif
