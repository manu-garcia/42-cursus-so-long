/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manugarc <manugarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 16:36:48 by manugarc          #+#    #+#             */
/*   Updated: 2022/07/19 09:41:46 by manugarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "state.h"
#include "error.h"

static void	exit_with_code(int code, t_state *state)
{
	free_state(state);
	exit(code);
}

void	exit_with_error(t_state *state)
{
	exit_with_code(ERROR_GENERIC, state);
}

void	exit_without_error(t_state *state)
{
	exit_with_code(ERROR_NONE, state);
}
