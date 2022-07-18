
#include <stdlib.h>
#include "state.h"

int	main(int argc, char *argv[])
{
	t_state	state;

	(void)argc;
	(void)argv;
	if (!init_state(&state))
		exit(0);
	return (0);
}
