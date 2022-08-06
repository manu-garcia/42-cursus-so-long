/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manu <manu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 19:01:52 by manu              #+#    #+#             */
/*   Updated: 2022/08/06 19:05:10 by manu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LOAD_H
# define LOAD_H

# include "state.h"

int	load_all_images(t_state *state);
int	load_image(t_state *state, t_image *image, char *file);

#endif
