/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manu <manu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 22:16:02 by manu              #+#    #+#             */
/*   Updated: 2022/04/02 23:04:00 by manu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	hlen;
	size_t	nlen;
	size_t	i;
	size_t	n;

	if (!needle || *needle == '\0')
		return ((char *)haystack);
	hlen = ft_strlen((char *)haystack);
	nlen = ft_strlen((char *)needle);
	n = len;
	if (nlen < len)
		n = nlen;
	i = 0;
	while (i < hlen && (i + nlen) <= len)
	{
		if (!ft_strncmp((char *)needle, (char *)haystack + i, n))
			return ((char *)haystack + i);
		i++;
	}
	return (NULL);
}
