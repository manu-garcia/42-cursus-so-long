
#include <stdlib.h>

#include "mlx.h"
#include "state.h"
#include "tile.h"
#include "libft.h"
#include "ft_printf.h"

static void	increase_hero_n_moves(t_state *state)
{
	char	*str;

	state->n_hero_moves++;
	ft_printf("Hero has moved %d times!\n", state->n_hero_moves);
	mlx_string_put(state->mlx, state->window, 20, 20,
		0x00FFFFFF, "Number moves:");
	str = ft_itoa(state->n_hero_moves);
	if (str)
	{
		mlx_string_put(state->mlx, state->window, 120, 20, 0x00FFFFFF, str);
		free(str);
	}
}

void	hero_move_right(t_state *state)
{
	state->hero.x += TILE_SIZE;
	increase_hero_n_moves(state);
}

void	hero_move_left(t_state *state)
{
	state->hero.x -= TILE_SIZE;
	increase_hero_n_moves(state);
}

void	hero_move_up(t_state *state)
{
	state->hero.y -= TILE_SIZE;
	increase_hero_n_moves(state);
}

void	hero_move_down(t_state *state)
{
	state->hero.y += TILE_SIZE;
	increase_hero_n_moves(state);
}
