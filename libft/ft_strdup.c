/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manu <manu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 15:58:04 by manugarc          #+#    #+#             */
/*   Updated: 2022/04/14 18:01:51 by manu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <errno.h>
#include "libft.h"

char	*ft_strdup(const char *s1)
{
	void	*ptr;
	int		len;

	if (!s1)
		return (NULL);
	len = ft_strlen((char *)s1);
	ptr = (char *)malloc(len + 1);
	if (!ptr)
	{
		errno = ENOMEM;
		return (NULL);
	}
	ft_strlcpy(ptr, (char *)s1, len + 1);
	return (ptr);
}
