#include <mlx.h>
#include <stdlib.h>

#include "state.h"
#include "image.h"
#include "load.h"
#include "libft.h"

int	init_state(t_state *state)
{
	ft_memset(state, 0, sizeof(t_state));
	state->mlx = mlx_init();
	state->window = mlx_new_window(state->mlx, 1000, 1000, "so_long");
	load_all_images(state);
	return (1);
}

// mlx_destroy_image(state->mlx, state->img);
int	free_state(t_state *state)
{
	mlx_destroy_window(state->mlx, state->window);
	free(state->mlx);
	return (1);
}
