/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manu <manu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 20:49:40 by manu              #+#    #+#             */
/*   Updated: 2022/07/21 11:32:25 by manu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	copy_index;

	if (!size || !src || !dest)
		return (ft_strlen(src));
	copy_index = 0;
	while ((copy_index < size - 1) && src[copy_index] != '\0')
	{
		dest[copy_index] = src[copy_index];
		copy_index++;
	}
	dest[copy_index] = '\0';
	return (ft_strlen(src));
}
