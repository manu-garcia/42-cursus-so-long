#include "mlx.h"
#include "image.h"
#include "state.h"
#include "tile.h"

int	draw_animation(t_state *state, t_animation *animation)
{
	draw_image(state, &animation->image[animation->n_image],
		animation->x, animation->y);
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
	mlx_put_image_to_window(state->mlx, state->window, image->img,
		x * TILE_SIZE, y * TILE_SIZE);
	return (1);
}
