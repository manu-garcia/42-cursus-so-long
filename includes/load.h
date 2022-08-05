#ifndef LOAD_H
# define LOAD_H

# include "state.h"

int	load_all_images(t_state *state);
int	load_image(t_state *state, t_image *image, char *file);
int	free_all_images(t_state *state);

#endif
