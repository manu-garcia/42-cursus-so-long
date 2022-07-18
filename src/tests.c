#include "check_extension.h"
#include <assert.h>

int	main(int argc, char *argv[])
{
	assert(check_extension("map.ber", ".ber")==1); 
	
	(void)argc;
	(void)argv;
	return (0);
}
