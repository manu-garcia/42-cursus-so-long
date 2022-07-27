#ifndef STATE_H
# define STATE_H

typedef struct s_image
{
	void		*img;
	int			width;
	int			height;
}	t_image;

typedef struct s_animation
{
	t_image	image[10];
	int		n_images;
	int		n_image;
	int		time;
}	t_animation;

typedef struct s_state
{
	void		*map;
	void		*mlx;
	void		*window;
	t_animation	hero;
}	t_state;

int	init_state(t_state *state);
int	free_state(t_state *state);

#endif
