/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manu <manu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 18:42:01 by manu              #+#    #+#             */
/*   Updated: 2022/08/06 18:42:02 by manu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "ft_printf.h"
#include "image.h"
#include "state.h"
#include "error.h"
#include "tile.h"
#include "libft.h"

int	load_image(t_state *state, t_image *image, char *file)
{
	image->img = mlx_xpm_file_to_image(state->mlx, file,
			&image->width, &image->height);
	if (!image->img)
	{
		ft_printf("Error\nError loading image (%s)\n", file);
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
	load_image(state, &(state->floor), "./images/floor.xpm");
	load_image(state, &(state->wall), "./images/wall.xpm");
	load_image(state, &(state->exit), "./images/exit.xpm");
	load_image(state, &(state->collectible), "./images/collectible.xpm");
	return (1);
}

static void	free_image(t_state *state, t_image *image)
{
	if (image->img)
		mlx_destroy_image(state->mlx, image->img);
}

static void	free_animation(t_state *state, t_animation *animation)
{
	int	i;

	i = 0;
	while (i < animation->n_images)
	{
		free_image(state, &(animation->image[i]));
		i++;
	}
	ft_memset(animation, 0, sizeof(t_animation));
}

int	free_all_images(t_state *state)
{
	free_animation(state, &(state->hero));
	free_animation(state, &(state->monster));
	free_image(state, &state->floor);
	free_image(state, &state->wall);
	free_image(state, &state->exit);
	free_image(state, &state->collectible);
	return (1);
}
