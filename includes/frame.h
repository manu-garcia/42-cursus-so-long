#ifndef FRAME_H
# define FRAME_H

# include "state.h"
#include "map.h"

int	on_render_frame(t_state *state);
int	check_tile_collision(t_state *state, t_tile tile, int x, int y);

#endif
