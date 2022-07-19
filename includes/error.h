/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manugarc <manugarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 15:44:59 by manugarc          #+#    #+#             */
/*   Updated: 2022/07/19 09:41:58 by manugarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H

# define ERROR_NONE			0
# define ERROR_GENERIC		1

void	exit_with_error(t_state *state);
void	exit_without_error(t_state *state);

#endif
