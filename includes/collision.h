/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collision.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manu <manu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 18:56:44 by manu              #+#    #+#             */
/*   Updated: 2022/08/06 18:58:25 by manu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLLISION_H
# define COLLISION_H

# include "state.h"
# include "map.h"

int		check_tile_collision(t_state *state, t_tile tile, int x, int y);
void	check_collisions(t_state *state);

#endif
