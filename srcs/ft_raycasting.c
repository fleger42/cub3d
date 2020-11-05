/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raycasting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/03 02:54:13 by user42            #+#    #+#             */
/*   Updated: 2020/06/05 10:47:09 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub3d.h"

void		ft_raydir(t_win *win)
{
	if (win->raydirx < 0)
	{
		win->ray->stepx = -1;
		win->ray->sidedistx = (win->map->x_player - win->ray->mapx)
		* win->ray->deltadistx;
	}
	else
	{
		win->ray->stepx = 1;
		win->ray->sidedistx = (win->ray->mapx + 1.0 - win->map->x_player)
		* win->ray->deltadistx;
	}
	if (win->raydiry < 0)
	{
		win->ray->stepy = -1;
		win->ray->sidedisty = (win->map->y_player - win->ray->mapy)
		* win->ray->deltadisty;
	}
	else
	{
		win->ray->stepy = 1;
		win->ray->sidedisty = (win->ray->mapy + 1.0 - win->map->y_player)
		* win->ray->deltadisty;
	}
}

void		ray_casting_precalculation(t_win *win, int x)
{
	win->ray->mapx = (int)win->map->x_player;
	win->ray->mapy = (int)win->map->y_player;
	win->ray->camerax = (2 * x) / (double)win->map->x_res - 1;
	win->raydirx = win->map->dirx + win->map->planex * win->ray->camerax;
	win->raydiry = win->map->diry + win->map->planey * win->ray->camerax;
	win->ray->deltadistx = fabs(1 / win->raydirx);
	win->ray->deltadisty = fabs(1 / win->raydiry);
}

void		ft_ray_casting_texx(t_win *win)
{
	win->ray->wallx -= floor(win->ray->wallx);
	if (win->ray->perpwalldist < 0)
		win->ray->perpwalldist = 0;
	win->ray->texx = (int)(win->ray->wallx * (double)get_texture_width(win));
	if (win->side == 0 && win->raydirx > 0)
		win->ray->texx = get_texture_width(win) - win->ray->texx - 1;
	else if (win->side == 1 && win->raydiry < 0)
		win->ray->texx = get_texture_width(win) - win->ray->texx - 1;
}

void		ft_perpwalldist_calculation(t_win *win)
{
	if (win->side == 0)
	{
		win->ray->perpwalldist = (win->ray->mapx - win->map->x_player +
		(1 - win->ray->stepx) / 2) / win->raydirx;
		win->ray->wallx = win->map->y_player + win->ray->perpwalldist *
		win->raydiry;
	}
	else
	{
		win->ray->perpwalldist = (win->ray->mapy - win->map->y_player +
		(1 - win->ray->stepy) / 2) / win->raydiry;
		win->ray->wallx = win->map->x_player + win->ray->perpwalldist *
		win->raydirx;
	}
}

double		ray_casting(t_win *win, int x)
{
	win->ray->hit = 0;
	ray_casting_precalculation(win, x);
	ft_raydir(win);
	while (win->ray->hit == 0)
	{
		if (win->ray->sidedistx < win->ray->sidedisty)
		{
			win->ray->sidedistx += win->ray->deltadistx;
			win->ray->mapx += win->ray->stepx;
			win->side = 0;
		}
		else
		{
			win->ray->sidedisty += win->ray->deltadisty;
			win->ray->mapy += win->ray->stepy;
			win->side = 1;
		}
		if (win->map->description[win->ray->mapy][win->ray->mapx] == '1')
			win->ray->hit = 1;
	}
	ft_perpwalldist_calculation(win);
	ft_ray_casting_texx(win);
	draw_wall_calculation(win->ray->perpwalldist, x, win, win->ray->texx * 4);
	return (win->ray->perpwalldist);
}
