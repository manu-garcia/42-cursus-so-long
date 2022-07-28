#include "image.h"
#include "state.h"
#include "tile.h"
#include "error.h"
#include "ft_printf.h"

void	update_frame(t_state *state)
{
	if (state->monster.y == 0)
		state->monster.y = 1;
	else
		state->monster.y = 0;
}

void	check_collisions(t_state *state)
{
	if (state->hero.x == state->monster.x
		&& state->hero.y == state->monster.y)
	{
		ft_printf("Game Over\n");
		exit_without_error(state);
	}
}

int	on_render_frame(t_state *state)
{
	update_frame(state);
	check_collisions(state);
	draw_animation(state, &state->monster);
	draw_animation(state, &state->hero);
	return (1);
}
