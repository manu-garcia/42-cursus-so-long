
#include <fcntl.h>
#include <stdlib.h>
#include <mlx.h>

#include "../ft_printf/src/ft_printf.h"
#include "../gnl/get_next_line.h"
#include "../libft/libft.h"
#include "check_extension.h"
#include "state.h"
#include "error.h"

/* int check_lines(int len, int fd, const char *array)
{

	ft_printf("longitud de linea:  %d\n", len);
	while(*array != '\0')
	{
	 	ft_printf("%c\n", *array);
		array++;
	}
	ft_printf("Primera línea correcta.");
return (0);
} */

int check_map(int fd)
{
	const char *line;
	int nbr_of_lines;
	int lenght_of_line;

	nbr_of_lines = 0;
	line = get_next_line(fd);

	if(!line)
	{
		ft_printf("Error.\n El mapa está vacío.\n");
		return(0);
	}
	else
	lenght_of_line = ft_strlen(line);

	return(nbr_of_lines-1);
}
int	main(int argc, char *argv[])
{
	//int fd;
	t_state	state;

	if (!init_state(&state))
		exit_with_error(&state);
	if(argc !=2)
	{
		ft_printf("Numero de argumentos incorrecto\n");
		return(0);
	}

	ft_printf("valor de %d\n", check_extension(argv[1], ".ber"));
	mlx_loop(state.mlx);
	return exit_without_error(&state);
}
