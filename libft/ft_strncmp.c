/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manugarc <manugarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 18:27:52 by manu              #+#    #+#             */
/*   Updated: 2022/04/09 15:43:17 by manugarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

int	ft_strncmp(char *s1, const char *s2, size_t n)
{
	size_t			cont;
	unsigned char	*uchar_s1;
	unsigned char	*uchar_s2;

	uchar_s1 = (unsigned char *)s1;
	uchar_s2 = (unsigned char *)s2;
	cont = 0;
	while (cont < n && (s1[cont] || s2[cont]))
	{
		if (s1[cont] != s2[cont])
			return (uchar_s1[cont] - uchar_s2[cont]);
		cont++;
	}
	return (0);
}
