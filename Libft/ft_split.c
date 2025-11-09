/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgumienn <mgumienn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 17:23:58 by mgumienn          #+#    #+#             */
/*   Updated: 2025/10/07 19:44:14 by mgumienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_words(const char *s, char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			count++;
			while (s[i] != c && s[i] != '\0')
				i++;
			if (s[i] == '\0')
				return (count);
		}
		i++;
	}
	return (count);
}

static void	free_all(char **result)
{
	int	i;

	i = 0;
	while (result[i])
	{
		free(result[i]);
		i++;
	}
	free(result);
}

static int	word_len(const char *s, char c)
{
	int	len;

	len = 0;
	while (s[len] != '\0' && s[len] != c)
		len++;
	return (len);
}

static char	*splitter(const char *s, char c, int *pos)
{
	int		len;
	int		i;
	char	*word;

	word = NULL;
	i = 0;
	while (s[*pos] != '\0')
	{
		if (s[*pos] != c && s[*pos] != '\0')
		{
			len = word_len(&s[*pos], c);
			word = (char *)malloc(sizeof(char) * (len + 1));
			if (!word)
				return (NULL);
			while (s[*pos] != c && s[*pos] != '\0')
				word[i++] = s[(*pos)++];
			word[i] = '\0';
			return (word);
		}
		(*pos)++;
	}
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	size_t	words;
	int		i;
	char	**strs;
	int		pos;

	if (s == NULL)
		return (NULL);
	words = count_words(s, c);
	strs = (char **)malloc(sizeof(char *) * (words + 1));
	if (strs == NULL)
		return (NULL);
	strs[words] = NULL;
	i = 0;
	pos = 0;
	while (words--)
	{
		strs[i] = splitter(s, c, &pos);
		if (!strs[i])
		{
			free_all(strs);
			return (NULL);
		}
		i++;
	}
	return (strs);
}
