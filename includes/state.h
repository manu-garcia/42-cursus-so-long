#ifndef STATE_H
# define STATE_H

typedef struct s_state
{
	void	*map;
}	t_state;

int	init_state(t_state *state);
int	free_state(t_state *state);

#endif
