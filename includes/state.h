#ifndef STATE_H
# define STATE_H

# define MAX_IMAGE_PER_ANIMATION	10
# define TIME_PER_ANIMATION_FRAME	5

typedef struct s_image
{
	void		*img;
	int			width;
	int			height;
	int			x;
	int			y;
}	t_image;

typedef struct s_animation
{
	t_image	image[MAX_IMAGE_PER_ANIMATION];
	int		n_images;
	int		n_image;
	int		time;
	int		x;
	int		y;
}	t_animation;

typedef struct s_state
{
	void		*map;
	void		*mlx;
	void		*window;
	t_animation	hero;
	t_animation	monster;
	int			n_hero_moves;
}	t_state;

int	init_state(t_state *state);
int	free_state(t_state *state);

#endif
