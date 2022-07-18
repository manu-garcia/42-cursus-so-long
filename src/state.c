#include "state.h"
#include "libft.h"

int	init_state(t_state *state)
{
	ft_memset(state, 1, sizeof(t_state));
	return (1);
}

// free resources
int	free_state(t_state *state)
{
	(void)state;
	return (1);
}
