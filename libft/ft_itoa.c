/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manu <manu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 12:44:29 by manugarc          #+#    #+#             */
/*   Updated: 2022/04/12 19:40:00 by manu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <limits.h>
#include "libft.h"

static int	get_num_length(int n)
{
	int	length;

	length = 0;
	if (n < 0)
	{
		length += 1;
		n *= -1;
	}
	if (n == 0)
		return (length + 1);
	while (n > 0)
	{
		n /= 10;
		length++;
	}
	return (length);
}

static char	*_itoa(int n, char *str, int length)
{
	int	i;

	str[length] = '\0';
	i = length - 1;
	while (i >= 0)
	{
		str[i] = n % 10 + '0';
		n /= 10;
		i--;
	}
	return (str);
}

char	*ft_itoa(int n)
{
	int		length;
	char	*str;

	if (n == INT_MIN)
		return (ft_strdup("-2147483648"));
	length = get_num_length(n);
	str = (char *) malloc(length + 1);
	if (n < 0)
	{
		str[0] = '-';
		n *= -1;
		_itoa(n, str + 1, length - 1);
	}
	else
		_itoa(n, str, length);
	return (str);
}
