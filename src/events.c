#include "events.h"
#include "error.h"

int	on_key_pressed(int key_code, t_state *state)
{
	if (key_code == EVENT_KEY_ESC)
		exit_without_error(state);
	return (0);
}
