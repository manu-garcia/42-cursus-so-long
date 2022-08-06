#include <mlx.h>
#include <stdlib.h>

#include "state.h"
#include "image.h"
#include "load.h"
#include "libft.h"
#include "map.h"
#include "tile.h"
#include "load.h"
#include "hero.h"
#include "ft_printf.h"

int	init_state(t_state *state, char *map_file_name)
{
	ft_memset(state, 0, sizeof(t_state));
	load_map(state, map_file_name);
	if (!is_valid_map(state))
	{
		ft_printf("The map is invalid\n");
		return (0);
	}
	state->mlx = mlx_init();
	state->window = mlx_new_window(state->mlx,
			state->map.width * TILE_SIZE,
			state->map.height * TILE_SIZE, "so_long");
	load_all_images(state);
	set_hero_position(state);
	return (1);
}

int	free_state(t_state *state)
{
	if (state->mlx && state->window)
	{
		mlx_destroy_window(state->mlx, state->window);
		free(state->mlx);
	}
	free_map(state);
	// free_all_images(state);
	ft_memset(state, 0, sizeof(t_state));
	return (1);
}
