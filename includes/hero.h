#ifndef HERO_H
# define HERO_H

# include "state.h"

void	hero_move_right(t_state *state);
void	hero_move_left(t_state *state);
void	hero_move_up(t_state *state);
void	hero_move_down(t_state *state);
void	set_hero_position(t_state *state);

#endif
