/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manu <manu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 18:42:41 by manu              #+#    #+#             */
/*   Updated: 2022/08/06 18:43:19 by manu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "check_extension.h"
#include <assert.h>

int	main(int argc, char *argv[])
{
	assert(check_extension("map.ber", "ber") == 1);
	(void)argc;
	(void)argv;
	return (0);
}
