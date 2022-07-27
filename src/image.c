#include "mlx.h"
#include "ft_printf.h"
#include "image.h"
#include "state.h"
#include "error.h"

int	load_all_images(t_state *state)
{
	load_image(state, &(state->hero.image[0]), "./images/hero_1.xpm");
	load_image(state, &(state->hero.image[1]), "./images/hero_2.xpm");
	load_image(state, &(state->hero.image[2]), "./images/hero_3.xpm");
	load_image(state, &(state->hero.image[3]), "./images/hero_4.xpm");
	state->hero.n_images = 4;
	state->hero.n_image = 0;
	return (1);
}

int	load_image(t_state *state, t_image *image, char *file)
{
	image->img = mlx_xpm_file_to_image(state->mlx, file,
			&image->width, &image->height);
	if (!image->img)
	{
		ft_printf("Error loading image (%s)\n", file);
		return (exit_with_error(state));
	}
	return (1);
}

int	draw_animation(t_state *state, t_animation *animation, int x, int y)
{
	draw_image(state, &animation->image[animation->n_image], x, y);
	animation->time++;
	if (animation->time > 5)
	{
		animation->time = 0;
		animation->n_image++;
		if (animation->n_image >= animation->n_images)
			animation->n_image = 0;
	}
	return (1);
}

int	draw_image(t_state *state, t_image *image, int x, int y)
{
	mlx_put_image_to_window(state->mlx, state->window, image->img, x, y);
	return (1);
}
