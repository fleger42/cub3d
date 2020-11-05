/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_keys_move.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/03 02:27:50 by user42            #+#    #+#             */
/*   Updated: 2020/06/05 09:59:56 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub3d.h"

void	ft_key_s(t_win *win)
{
	if (win->map->description[(int)((win->map->y_player))]
	[(int)(win->map->x_player - win->map->dirx * 0.4)] != '1'
	&& !(win->map->description[(int)((win->map->y_player + 0.01))]
	[(int)(win->map->x_player - win->map->dirx * 0.4)] == '1')
	&& !(win->map->description[(int)((win->map->y_player - 0.01))]
	[(int)(win->map->x_player - win->map->dirx * 0.4)] == '1'))
		win->map->x_player -= win->map->dirx * 0.2;
	if (win->map->description[(int)(win->map->y_player - win->map->diry
	* 0.4)][(int)(win->map->x_player)] != '1'
	&& !(win->map->description[(int)(win->map->y_player - win->map->diry
	* 0.4)][(int)(win->map->x_player + 0.01)] == '1')
	&& !(win->map->description[(int)(win->map->y_player - win->map->diry
	* 0.4)][(int)(win->map->x_player - 0.01)] == '1'))
		win->map->y_player -= win->map->diry * 0.2;
}

void	ft_key_w(t_win *win)
{
	if (win->map->description[(int)((win->map->y_player))]
	[(int)(win->map->x_player + win->map->dirx * 0.4)] != '1'
	&& !(win->map->description[(int)((win->map->y_player - 0.01))]
	[(int)(win->map->x_player + win->map->dirx * 0.4)] == '1')
	&& !(win->map->description[(int)((win->map->y_player + 0.01))]
	[(int)(win->map->x_player + win->map->dirx * 0.4)] == '1'))
		win->map->x_player += win->map->dirx * 0.2;
	if (win->map->description[(int)(win->map->y_player + win->map->diry
	* 0.4)][(int)(win->map->x_player)] != '1'
	&& !(win->map->description[(int)(win->map->y_player + win->map->diry
	* 0.4)][(int)(win->map->x_player - 0.01)] == '1')
	&& !(win->map->description[(int)(win->map->y_player + win->map->diry
	* 0.4)][(int)(win->map->x_player + 0.01)] == '1'))
		win->map->y_player += win->map->diry * 0.2;
}

void	ft_key_a(t_win *win)
{
	if (win->map->description[(int)(win->map->y_player)]
	[(int)(win->map->x_player - win->map->planex * 0.4)] != '1'
	&& !(win->map->description[(int)(win->map->y_player - 0.01)]
	[(int)(win->map->x_player - win->map->planex * 0.4)] == '1')
	&& !(win->map->description[(int)(win->map->y_player + 0.01)]
	[(int)(win->map->x_player - win->map->planex * 0.4)] == '1'))
		win->map->x_player -= win->map->planex * 0.2;
	if (win->map->description[(int)(win->map->y_player - win->map->planey
	* 0.4)][(int)(win->map->x_player)] != '1'
	&& !(win->map->description[(int)(win->map->y_player - win->map->planey
	* 0.4)][(int)(win->map->x_player - 0.01)] == '1')
	&& !(win->map->description[(int)(win->map->y_player - win->map->planey
	* 0.4)][(int)(win->map->x_player + 0.01)] == '1'))
		win->map->y_player -= win->map->planey * 0.2;
}

void	ft_key_d(t_win *win)
{
	if (win->map->description[(int)((win->map->y_player))]
	[(int)(win->map->x_player + win->map->planex * 0.4)] != '1'
	&& !(win->map->description[(int)((win->map->y_player + 0.01))]
	[(int)(win->map->x_player + win->map->planex * 0.4)] == '1')
	&& !(win->map->description[(int)((win->map->y_player - 0.01))]
	[(int)(win->map->x_player + win->map->planex * 0.4)] == '1'))
		win->map->x_player += win->map->planex * 0.2;
	if (win->map->description[(int)(win->map->y_player + win->map->planey
	* 0.4)][(int)(win->map->x_player)] != '1'
	&& !(win->map->description[(int)(win->map->y_player + win->map->planey
	* 0.4)][(int)(win->map->x_player + 0.01)] == '1')
	&& !(win->map->description[(int)(win->map->y_player + win->map->planey
	* 0.4)][(int)(win->map->x_player - 0.01)] == '1'))
		win->map->y_player += win->map->planey * 0.2;
}
