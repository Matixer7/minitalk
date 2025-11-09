/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgumienn <mgumienn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 18:24:39 by mgumienn          #+#    #+#             */
/*   Updated: 2025/10/09 18:21:56 by mgumienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(const char *s1, const char *set)
{
	size_t	i;
	size_t	j;
	char	*trim;

	if (!s1 || !set)
		return (NULL);
	i = 0;
	trim = 0;
	j = ft_strlen(s1);
	if (s1 != 0 && set != 0)
	{
		while (s1[i] && ft_strchr(set, s1[i]))
			i++;
		while (s1[j - 1] && ft_strrchr(set, s1[j - 1]) && j > i)
			j--;
		trim = (char *)malloc(sizeof(char) * (j - i + 1));
		if (!trim)
			return (NULL);
		if (trim)
			ft_strlcpy(trim, &s1[i], j - i + 1);
	}
	return (trim);
}
