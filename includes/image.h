#ifndef IMAGE_H
# define IMAGE_H

# include "state.h"

int	load_all_images(t_state *state);
int	load_image(t_state *state, t_image *image, char *file);
int	draw_animation(t_state *state, t_animation *animation);
int	draw_image(t_state *state, t_image *image, int x, int y);

#endif
