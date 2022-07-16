/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manu <manu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 15:01:43 by manu              #+#    #+#             */
/*   Updated: 2022/04/14 18:23:55 by manu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>
#include <errno.h>
#include "libft.h"

char	*ft_substr(const char *s, size_t start, size_t size)
{
	char	*str;
	size_t	len_s;

	if (!s)
		return (NULL);
	len_s = ft_strlen(s);
	if (!len_s || start >= len_s)
	{
		str = (char *)malloc(1);
		str[0] = '\0';
		return (str);
	}
	if (size > len_s)
		size = len_s - start;
	str = malloc(size + 1);
	if (!str)
	{
		errno = ENOMEM;
		return (NULL);
	}
	ft_strlcpy(str, s + start, size + 1);
	return (str);
}
