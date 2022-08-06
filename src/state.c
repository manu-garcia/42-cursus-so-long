/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manu <manu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 18:42:37 by manu              #+#    #+#             */
/*   Updated: 2022/08/06 19:05:32 by manu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdlib.h>

#include "state.h"
#include "image.h"
#include "load.h"
#include "libft.h"
#include "map.h"
#include "map_validation.h"
#include "tile.h"
#include "load.h"
#include "hero.h"
#include "position.h"
#include "ft_printf.h"
#include "free.h"

int	init_state(t_state *state, char *map_file_name)
{
	ft_memset(state, 0, sizeof(t_state));
	load_map(state, map_file_name);
	if (!is_valid_map(state))
	{
		ft_printf("Error\nThe content of the map is invalid\n");
		return (0);
	}
	state->mlx = mlx_init();
	state->window = mlx_new_window(state->mlx,
			state->map.width * TILE_SIZE,
			state->map.height * TILE_SIZE, "so_long");
	load_all_images(state);
	set_hero_position(state);
	set_monster_position(state);
	set_monster_position(state);
	return (1);
}

/**
// mlx_destroy did not exist in the mlx api. I added it, so that I can also
// free the font that mlx initilizes in the mlx_init function!!!
// Also images need to be freed before mlx_destroy
 */
int	free_state(t_state *state)
{
	free_all_images(state);
	if (state->mlx && state->window)
	{
		mlx_destroy_window(state->mlx, state->window);
		mlx_destroy(state->mlx);
		state->mlx = NULL;
	}
	free_map(state);
	ft_memset(state, 0, sizeof(t_state));
	return (1);
}
