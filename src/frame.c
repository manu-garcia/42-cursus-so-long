#include "image.h"
#include "state.h"

int	on_render_frame(t_state *state)
{
	return (draw_animation(state, &state->hero));
}
