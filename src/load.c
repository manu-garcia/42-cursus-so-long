#include "mlx.h"
#include "ft_printf.h"
#include "image.h"
#include "state.h"
#include "error.h"
#include "tile.h"

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

int	load_hero(t_state *state)
{
	load_image(state, &(state->hero.image[0]), "./images/hero_1.xpm");
	load_image(state, &(state->hero.image[1]), "./images/hero_2.xpm");
	load_image(state, &(state->hero.image[2]), "./images/hero_3.xpm");
	load_image(state, &(state->hero.image[3]), "./images/hero_4.xpm");
	state->hero.n_images = 4;
	state->hero.n_image = 0;
	state->hero.x = 0;
	state->hero.y = 0;
	return (1);
}

int	load_monster(t_state *state)
{
	load_image(state, &(state->monster.image[0]), "./images/monster_1.xpm");
	load_image(state, &(state->monster.image[1]), "./images/monster_2.xpm");
	load_image(state, &(state->monster.image[2]), "./images/monster_3.xpm");
	load_image(state, &(state->monster.image[3]), "./images/monster_4.xpm");
	state->monster.n_images = 4;
	state->monster.n_image = 0;
	state->monster.x = 4;
	state->monster.y = 0;
	return (1);
}

int	load_all_images(t_state *state)
{
	load_hero(state);
	load_monster(state);
	return (1);
}
