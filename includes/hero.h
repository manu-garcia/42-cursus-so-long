/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hero.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manu <manu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 19:01:41 by manu              #+#    #+#             */
/*   Updated: 2022/08/06 19:01:42 by manu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HERO_H
# define HERO_H

# include "state.h"

void	hero_move_right(t_state *state);
void	hero_move_left(t_state *state);
void	hero_move_up(t_state *state);
void	hero_move_down(t_state *state);

#endif
