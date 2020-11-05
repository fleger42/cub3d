/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_keys_view.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/03 02:35:15 by user42            #+#    #+#             */
/*   Updated: 2020/06/05 10:48:24 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub3d.h"

void	ft_key_left(t_win *win)
{
	double oldplanex;
	double olddirx;

	olddirx = win->map->dirx;
	win->map->dirx = win->map->dirx * cos(-0.1) -
	win->map->diry * sin(-0.1);
	win->map->diry = olddirx * sin(-0.1) + win->map->diry * cos(-0.1);
	oldplanex = win->map->planex;
	win->map->planex = win->map->planex * cos(-0.1) -
	win->map->planey * sin(-0.1);
	win->map->planey = oldplanex * sin(-0.1) + win->map->planey * cos(-0.1);
}

void	ft_key_right(t_win *win)
{
	double oldplanex;
	double olddirx;

	olddirx = win->map->dirx;
	win->map->dirx = win->map->dirx * cos(0.1) - win->map->diry * sin(0.1);
	win->map->diry = olddirx * sin(0.1) + win->map->diry * cos(0.1);
	oldplanex = win->map->planex;
	win->map->planex = win->map->planex * cos(0.1)
	- win->map->planey * sin(0.1);
	win->map->planey = oldplanex * sin(0.1) + win->map->planey * cos(0.1);
}
