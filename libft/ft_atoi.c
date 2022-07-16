/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manu <manu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 18:36:08 by manu              #+#    #+#             */
/*   Updated: 2022/07/05 20:47:55 by manu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static char	*ft_remove_starting_characters(const char *str)
{
	char	*str_copy;

	str_copy = (char *)str;
	while ((*str_copy) && (
			(*str_copy) == ' ' || ((*str_copy) >= 9 && (*str_copy) <= 13))
	)
		str_copy++;
	return (str_copy);
}

static char	*ft_get_sign(char *str, int *sign)
{
	if ((*str) == '-')
	{
		(*sign) = -1;
		str++;
	}
	else if ((*str) == '+')
	{
		(*sign) = 1;
		str++;
	}
	else
		(*sign) = 1;
	return (str);
}

static int	ft_get_multiplier(int number_digits)
{
	int	cont;
	int	multiplier;

	cont = 1;
	multiplier = 1;
	while (cont < number_digits)
	{
		multiplier *= 10;
		cont ++;
	}
	return (multiplier);
}

static long	ft_get_number(char *str)
{
	int		index;
	int		len;
	long	number;

	index = 0;
	while (str[index] && str[index] >= '0' && str[index] <= '9')
		index++;
	if (!index)
		return (0);
	len = index;
	index = 0;
	number = 0;
	while (str [index] && str[index] >= '0' && str[index] <= '9')
	{
		number += ((str[index] - '0') * ft_get_multiplier(len - index));
		index++;
	}
	return (number);
}

long	ft_atoi(const char *str)
{
	char	*str_copy;
	int		sign;

	sign = 1;
	str_copy = ft_remove_starting_characters(str);
	str_copy = ft_get_sign(str_copy, &sign);
	return (ft_get_number(str_copy) * sign);
}
