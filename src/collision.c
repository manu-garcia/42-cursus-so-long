/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manu <manu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 18:41:49 by manu              #+#    #+#             */
/*   Updated: 2022/08/06 18:55:40 by manu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "image.h"
#include "state.h"
#include "tile.h"
#include "error.h"
#include "ft_printf.h"
#include "mlx.h"
#include "libft.h"
#include "map.h"

#define KNRM  "\x1B[0m"
#define KRED  "\x1B[31m"
#define KGRN  "\x1B[32m"
#define KYEL  "\x1B[33m"
#define KBLU  "\x1B[34m"
#define KMAG  "\x1B[35m"
#define KCYN  "\x1B[36m"
#define KWHT  "\x1B[37m"

int	check_tile_collision(t_state *state, t_tile tile, int x, int y)
{
	if ((t_tile) state->map.grid[y][x] == tile)
		return (1);
	return (0);
}

void	check_collisions(t_state *state)
{
	if (state->hero.x == state->monster.x
		&& state->hero.y == state->monster.y)
	{
		ft_printf("%sGame Over\n", KRED);
		exit_without_error(state);
	}
	if (check_tile_collision(state, TILE_COLLECTIBLE, state->hero.x,
			state->hero.y))
	{
		state->n_collectibles++;
		set_tile(state, TILE_EMPTY, state->hero.x, state->hero.y);
	}
	if (check_tile_collision(state, TILE_EXIT, state->hero.x, state->hero.y))
	{
		if (state->map.n_tiles_collectible == state->n_collectibles)
		{
			ft_printf("%sCaracol!!!\n", KGRN);
			exit_without_error(state);
		}
	}
}
