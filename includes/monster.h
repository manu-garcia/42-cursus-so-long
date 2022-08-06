/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monster.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manu <manu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 19:02:00 by manu              #+#    #+#             */
/*   Updated: 2022/08/06 19:24:41 by manu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MONSTER_H
# define MONSTER_H

# include "state.h"

void	move_monster_horizontally(t_state *state);
void	move_monster_vertically(t_state *state);

#endif
