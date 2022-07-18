#include "libft.h"

int check_extension(char *path, char *extension)
{
	int i;
	int j;
	int check;

	check = 1;
	j = ft_strlen(extension);
	i = ft_strlen(path);
	if(i>=j)
		while(path[i-1] && extension[j-1])
		{
			if(path[i-1] != extension[j-1])
			{
				check = 0;
				break ;
			}
			j--;
			i--;
		}
	else
		check = 0;	 
	return(check);
}