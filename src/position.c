
#include <stdlib.h>

#include "mlx.h"
#include "state.h"
#include "tile.h"
#include "libft.h"
#include "map.h"
#include "frame.h"

void	set_hero_position(t_state *state)
{
	int	x;
	int	y;

	y = 0;
	while (y < state->map.height)
	{
		x = 0;
		while (x < state->map.width)
		{
			if (check_tile_collision(state, TILE_PLAYER, x, y))
			{
				state->hero.x = x;
				state->hero.y = y;
				return ;
			}
			x++;
		}
		y++;
	}
}

void	set_monster_position(t_state *state)
{
	int	x;
	int	y;

	y = 0;
	while (y < state->map.height)
	{
		x = 0;
		while (x < state->map.width)
		{
			if (check_tile_collision(state, TILE_EMPTY, x, y))
			{
				if (check_tile_collision(state, TILE_EMPTY, x, y + 1))
				{
					state->monster.x = x;
					state->monster.y = y;
					return ;
				}
			}
			x++;
		}
		y++;
	}
}
