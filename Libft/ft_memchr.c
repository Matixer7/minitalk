/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgumienn <mgumienn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 12:36:30 by marvin            #+#    #+#             */
/*   Updated: 2025/09/28 14:41:18 by mgumienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *src, int search, size_t n)
{
	unsigned char	*ptr;

	ptr = (unsigned char *) src;
	while (n--)
	{
		if (*ptr == (unsigned char) search)
			return (ptr);
		ptr++;
	}
	return (0);
}
