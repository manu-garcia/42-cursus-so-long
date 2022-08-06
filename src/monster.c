/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monster.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manu <manu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 18:42:19 by manu              #+#    #+#             */
/*   Updated: 2022/08/06 18:42:22 by manu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "mlx.h"
#include "state.h"
#include "tile.h"
#include "libft.h"

void	monster_move_right(t_state *state)
{
	state->monster.x++;
}

void	monster_move_left(t_state *state)
{
	state->monster.x--;
}

void	monster_move_up(t_state *state)
{
	state->monster.y--;
}

void	monster_move_down(t_state *state)
{
	state->monster.y++;
}
