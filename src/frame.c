/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frame.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manu <manu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 18:41:49 by manu              #+#    #+#             */
/*   Updated: 2022/08/06 19:26:48 by manu             ###   ########.fr       */
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
#include "collision.h"
#include "monster.h"

void	update_frame(t_state *state)
{
	state->time++;
	if (state->time > 20)
	{
		state->time = 0;
		if (state->monster_last_axis_move)
		{
			state->monster_last_axis_move = 0;
			move_monster_vertically(state);
		}
		else
		{
			state->monster_last_axis_move = 1;
			move_monster_horizontally(state);
		}
	}
}

static void	draw_n_moves(t_state *state)
{
	char	*str;

	mlx_string_put(state->mlx, state->window, 20, 20,
		0x00FFFFFF, "Number moves:");
	str = ft_itoa(state->n_hero_moves);
	if (str)
	{
		mlx_string_put(state->mlx, state->window, 120, 20, 0x00FFFFFF, str);
		free(str);
	}
}

static void	draw_n_collectibles(t_state *state)
{
	char	*str;

	mlx_string_put(state->mlx, state->window, 20, 40,
		0x00FFFFFF, "Number collectibles:");
	str = ft_itoa(state->n_collectibles);
	if (str)
	{
		mlx_string_put(state->mlx, state->window, 170, 40, 0x00FFFFFF, str);
		free(str);
	}
}

int	on_render_frame(t_state *state)
{
	update_frame(state);
	check_collisions(state);
	draw_map(state);
	draw_n_moves(state);
	draw_n_collectibles(state);
	draw_animation(state, &state->monster);
	draw_animation(state, &state->hero);
	return (1);
}
