#include <stdlib.h>

#include "image.h"
#include "state.h"
#include "tile.h"
#include "error.h"
#include "ft_printf.h"
#include "mlx.h"
#include "libft.h"
#include "map.h"

#define KNRM  "\x1B[0m"
#define KRED  "\x1B[31m"
#define KGRN  "\x1B[32m"
#define KYEL  "\x1B[33m"
#define KBLU  "\x1B[34m"
#define KMAG  "\x1B[35m"
#define KCYN  "\x1B[36m"
#define KWHT  "\x1B[37m"

int	check_tile_collision(t_state *state, t_tile tile, int x, int y)
{
	if ((t_tile) state->map.grid[y][x] == tile)
		return (1);
	return (0);
}

void	update_frame(t_state *state)
{
	int	modx;
	int	mody;

	state->time++;
	if (state->time > 20)
	{
		state->time = 0;
		modx = 0;
		mody = 0;
		if (state->monster_last_axis_move)
		{
			state->monster_last_axis_move = 0;
			if (state->hero.y >= state->monster.y)
				mody = 1;
			else
				mody = -1;
		}
		else
		{
			state->monster_last_axis_move = 1;
			if (state->hero.x >= state->monster.x)
				modx = 1;
			else
				modx = -1;
		}
		if (!check_tile_collision(state, TILE_WALL, state->monster.x + modx,
				state->monster.y + mody))
		{
			state->monster.x += modx;
			state->monster.y += mody;
		}
	}
}

void	check_collisions(t_state *state)
{
	if (state->hero.x == state->monster.x
		&& state->hero.y == state->monster.y)
	{
		ft_printf("%sGame Over\n", KRED);
		exit_without_error(state);
	}
	if (check_tile_collision(state, TILE_COLLECTIBLE, state->hero.x,
			state->hero.y))
	{
		state->n_collectibles++;
		set_tile(state, TILE_EMPTY, state->hero.x, state->hero.y);
	}
	if (check_tile_collision(state, TILE_EXIT, state->hero.x, state->hero.y))
	{
		if (state->map.n_tiles_collectible == state->n_collectibles)
		{
			ft_printf("%sCaracol!!!\n", KGRN);
			exit_without_error(state);
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
