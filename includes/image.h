#ifndef IMAGE_H
# define IMAGE_H

# include "state.h"

int	draw_animation(t_state *state, t_animation *animation);
int	draw_image(t_state *state, t_image *image, int x, int y);
int	draw_map(t_state *state);

#endif
