/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monster.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manu <manu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 18:42:19 by manu              #+#    #+#             */
/*   Updated: 2022/08/06 19:25:09 by manu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "mlx.h"
#include "state.h"
#include "tile.h"
#include "libft.h"
#include "collision.h"

void	move_monster_vertically(t_state *state)
{
	int	mody;

	mody = 0;
	if (state->hero.y >= state->monster.y)
		mody = 1;
	else
		mody = -1;
	if (!check_tile_collision(state, TILE_WALL, state->monster.x,
			state->monster.y + mody))
	{
		state->monster.y += mody;
	}
}

void	move_monster_horizontally(t_state *state)
{
	int	modx;

	modx = 0;
	if (state->hero.x >= state->monster.x)
		modx = 1;
	else
		modx = -1;
	if (!check_tile_collision(state, TILE_WALL, state->monster.x + modx,
			state->monster.y))
	{
		state->monster.x += modx;
	}
}
