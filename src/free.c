/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manu <manu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 18:42:01 by manu              #+#    #+#             */
/*   Updated: 2022/08/06 19:03:26 by manu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "ft_printf.h"
#include "image.h"
#include "state.h"
#include "error.h"
#include "tile.h"
#include "libft.h"

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
