/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manugarc <manugarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 12:15:07 by manugarc          #+#    #+#             */
/*   Updated: 2022/04/12 12:42:38 by manugarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*str_dup;

	if (!s)
		return (NULL);
	str_dup = ft_strdup(s);
	if (!str_dup)
		return (NULL);
	i = 0;
	while (str_dup && str_dup[i])
	{
		str_dup[i] = f(i, str_dup[i]);
		i++;
	}
	return (str_dup);
}
