/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manu <manu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 17:03:16 by manugarc          #+#    #+#             */
/*   Updated: 2022/04/14 18:42:24 by manu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static char	*get_trimmed(char const *s, char c)
{
	char	set[2];

	if (!s)
		return (NULL);
	set[0] = c;
	set[1] = '\0';
	return (ft_strtrim(s, set));
}

static int	count_delimiter(const char	*s, char c)
{
	int		n;
	int		i;
	char	prev;

	n = 0;
	i = 0;
	while (s && s[i])
	{
		if (s[i] == c && prev != c)
			n++;
		prev = s[i];
		i++;
	}
	return (n);
}

static char	**get_empty(void)
{
	char	**split;

	split = (char **) malloc(sizeof(char *));
	split[0] = NULL;
	return (split);
}

static size_t	strlen_delimiter(const char *str, char delimiter)
{
	size_t	number_characters;

	number_characters = 0;
	while (str && *str && *str != delimiter)
	{
		str++;
		number_characters++;
	}
	return (number_characters);
}

char	**ft_split(char const *s, char c)
{
	char	**split;
	char	*trimmed;
	char	*prev;
	size_t	n_delimiters;
	int		i;

	trimmed = get_trimmed(s, c);
	if (!trimmed)
		return (get_empty());
	n_delimiters = count_delimiter(trimmed, c);
	split = (char **)malloc((n_delimiters + 2) * sizeof(char *));
	prev = trimmed;
	i = 0;
	while (prev && *prev)
	{
		while (*prev && *prev == c)
			prev++;
		split[i++] = ft_substr(prev, 0, strlen_delimiter(prev, c));
		prev += strlen_delimiter(prev, c);
	}
	split[i] = NULL;
	free(trimmed);
	return (split);
}
