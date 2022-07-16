/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manugarc <manugarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 20:49:40 by manu              #+#    #+#             */
/*   Updated: 2022/04/09 15:04:25 by manugarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	copy_index;
	int		src_len_reached;

	if (!size || !src || !dest)
		return (ft_strlen(src));
	copy_index = 0;
	src_len_reached = 0;
	while ((copy_index < size - 1) && src[copy_index] != '\0')
	{
		dest[copy_index] = src[copy_index];
		copy_index++;
	}
	dest[copy_index] = '\0';
	return (ft_strlen(src));
}
