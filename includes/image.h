/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manu <manu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 19:01:46 by manu              #+#    #+#             */
/*   Updated: 2022/08/06 19:01:46 by manu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMAGE_H
# define IMAGE_H

# include "state.h"

int	draw_animation(t_state *state, t_animation *animation);
int	draw_image(t_state *state, t_image *image, int x, int y);
int	draw_map(t_state *state);

#endif
