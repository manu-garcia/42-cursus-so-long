/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hero.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manu <manu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 18:41:28 by manu              #+#    #+#             */
/*   Updated: 2022/08/06 18:41:34 by manu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "mlx.h"
#include "state.h"
#include "tile.h"
#include "libft.h"
#include "map.h"
#include "frame.h"
#include "ft_printf.h"

static void	increase_hero_n_moves(t_state *state)
{
	char	*str;

	state->n_hero_moves++;
	ft_printf("Hero has moved %d times!\n", state->n_hero_moves);
	mlx_string_put(state->mlx, state->window, 20, 20,
		0x00FFFFFF, "Number moves:");
	str = ft_itoa(state->n_hero_moves);
	if (str)
	{
		mlx_string_put(state->mlx, state->window, 120, 20, 0x00FFFFFF, str);
		free(str);
	}
}

void	hero_move_right(t_state *state)
{
	if (!check_tile_collision(state, TILE_WALL,
			state->hero.x + 1, state->hero.y))
	{
		state->hero.x++;
		increase_hero_n_moves(state);
	}
}

void	hero_move_left(t_state *state)
{
	if (!check_tile_collision(state, TILE_WALL,
			state->hero.x - 1, state->hero.y))
	{
		state->hero.x--;
		increase_hero_n_moves(state);
	}
}

void	hero_move_up(t_state *state)
{
	if (!check_tile_collision(state, TILE_WALL,
			state->hero.x, state->hero.y - 1))
	{
		state->hero.y--;
		increase_hero_n_moves(state);
	}
}

void	hero_move_down(t_state *state)
{
	if (!check_tile_collision(state, TILE_WALL,
			state->hero.x, state->hero.y + 1))
	{
		state->hero.y++;
		increase_hero_n_moves(state);
	}
}
