/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_math_sprite.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/05 09:56:46 by user42            #+#    #+#             */
/*   Updated: 2020/06/05 11:04:20 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub3d.h"

void	ft_sprite_texx(t_win *win)
{
	win->spr->texx = (int)(256 * (win->spr->stripe -
	(-win->spr->spritewidth / 2 + win->spr->spritescreenx))
	* win->sprite_width / win->spr->spritewidth) / 256;
	if (win->spr->texx > win->sprite_width)
		win->spr->texx = win->sprite_width;
}

void	ft_sprite_texy(t_win *win, int y)
{
	win->spr->d = (y) * 256 - win->map->y_res * 128 +
	win->spr->spriteheight * 128;
	win->spr->texy = ((win->spr->d * win->sprite_height)
	/ win->spr->spriteheight) / 256;
	if (win->spr->texy > win->sprite_height)
		win->spr->texy = win->sprite_height;
}

void	ft_sprite_calculation(t_win *win, int i)
{
	win->spr->spritex = win->sprite[win->sprite_order[i]]->x -
	win->map->x_player;
	win->spr->spritey = win->sprite[win->sprite_order[i]]->y -
	win->map->y_player;
	win->spr->invdet = 1.0 / (win->map->planex * win->map->diry -
	win->map->dirx * win->map->planey);
	win->spr->transformx = win->spr->invdet * (win->map->diry *
	win->spr->spritex - win->map->dirx * win->spr->spritey);
	win->spr->transformy = win->spr->invdet * (-win->map->planey
	* win->spr->spritex + win->map->planex * win->spr->spritey);
	win->spr->spritescreenx = (int)((win->map->x_res / 2) *
	(1 + win->spr->transformx / win->spr->transformy));
	win->spr->spriteheight = abs((int)(win->map->y_res /
	(win->spr->transformy)));
	win->spr->drawstarty = -win->spr->spriteheight / 2 +
	win->map->y_res / 2;
	if (win->spr->drawstarty < 0)
		win->spr->drawstarty = 0;
	win->spr->drawendy = win->spr->spriteheight / 2 + win->map->y_res / 2;
	if (win->spr->drawendy >= win->map->y_res)
		win->spr->drawendy = win->map->y_res - 1;
	win->spr->spritewidth = abs((int)(win->map->y_res /
	(win->spr->transformy)));
	win->spr->drawstartx = -win->spr->spritewidth / 2 +
	win->spr->spritescreenx;
}

void	ft_sprite_calculation2(t_win *win)
{
	if (win->spr->drawstartx < 0)
		win->spr->drawstartx = 0;
	win->spr->drawendx = win->spr->spritewidth / 2 +
	win->spr->spritescreenx;
	if (win->spr->drawendx >= win->map->x_res)
		win->spr->drawendx = win->map->x_res - 1;
	win->spr->stripe = win->spr->drawstartx;
}

void	ft_sprite_dist(t_win *win, int nbr_sprite)
{
	int i;

	i = -1;
	while (++i < nbr_sprite)
		win->sprite_distance[i] = ((win->map->x_player - win->sprite[i]->x)
		* (win->map->x_player - win->sprite[i]->x) +
		(win->map->y_player - win->sprite[i]->y) * (win->map->y_player
		- win->sprite[i]->y));
}
