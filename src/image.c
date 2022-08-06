#include <stddef.h>

#include "mlx.h"
#include "image.h"
#include "state.h"
#include "tile.h"
#include "map.h"

int	draw_animation(t_state *state, t_animation *animation)
{
	mlx_put_image_to_window(state->mlx, state->window,
		animation->image[animation->n_image].img,
		(animation->x * TILE_SIZE) + 15, (animation->y * TILE_SIZE) + 15);
	animation->time++;
	if (animation->time > TIME_PER_ANIMATION_FRAME)
	{
		animation->time = 0;
		animation->n_image++;
		if (animation->n_image >= animation->n_images
			|| animation->n_image >= MAX_IMAGE_PER_ANIMATION)
			animation->n_image = 0;
	}
	return (1);
}

int	draw_image(t_state *state, t_image *image, int x, int y)
{
	if (!image || !image->img)
		return (0);
	mlx_put_image_to_window(state->mlx, state->window, image->img,
		x * TILE_SIZE, y * TILE_SIZE);
	return (1);
}

t_image	*get_tile_image(t_state *state, t_tile tile)
{
	if (tile == TILE_EMPTY)
		return (&(state->floor));
	else if (tile == TILE_EXIT)
		return (&(state->exit));
	else if (tile == TILE_WALL)
		return (&(state->wall));
	else if (tile == TILE_COLLECTIBLE)
		return (&(state->collectible));
	return (&(state->floor));
}

int	draw_map(t_state *state)
{
	int	x;
	int	y;

	y = 0;
	while (y < state->map.height)
	{
		x = 0;
		while (x < state->map.width)
		{
			draw_image(state, get_tile_image(state, state->map.grid[y][x]),
				x, y);
			x++;
		}
		y++;
	}
	return (1);
}
