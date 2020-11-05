/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/03 01:27:02 by user42            #+#    #+#             */
/*   Updated: 2020/06/05 10:34:35 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub3d.h"

void	draw_top(t_win *win, int drawstart, int column)
{
	int i;

	i = 0;
	while (i < drawstart)
	{
		my_mlx_put_pxl_to_img(column, i, win->map->path_c, win);
		i++;
	}
}

void	draw_bottom(t_win *win, int drawend, int column)
{
	while (drawend <= win->map->y_res)
		my_mlx_put_pxl_to_img(column, drawend++, win->map->path_f, win);
}

void	draw_wall(t_win *win, int texx, int i)
{
	draw_top(win, win->drawing->drawstart, i);
	draw_bottom(win, win->drawing->drawend, i);
	if (win->drawing->drawend >= win->map->y_res)
		win->drawing->drawend = win->map->y_res - 1;
	win->drawing->step = (double)get_texture_height(win) /
	(double)win->drawing->lineheight;
	win->drawing->texpos = (win->drawing->drawstart - win->map->y_res
	/ 2 + win->drawing->lineheight / 2) * win->drawing->step;
	while (win->drawing->drawstart <= win->drawing->drawend)
	{
		win->drawing->texy = (int)win->drawing->texpos;
		win->drawing->texpos =
		win->drawing->texpos + win->drawing-> step;
		my_mlx_put_pxl_to_img(i, win->drawing->drawstart,
		get_texture(win, texx, win->drawing->texy,
		win->drawing->intensity), win);
		win->drawing->drawstart++;
	}
}

void	draw_wall_calculation(double perpwalldist, int i, t_win *win, int texx)
{
	win->drawing->intensity = 1;
	if (perpwalldist > 4 && perpwalldist <= 7)
		win->drawing->intensity = 0.70;
	if (perpwalldist > 7 && perpwalldist <= 10)
		win->drawing->intensity = 0.60;
	if (perpwalldist > 10)
		win->drawing->intensity = 0.50;
	if (perpwalldist == 0)
		win->drawing->lineheight = (int)(win->map->y_res);
	else
		win->drawing->lineheight = (int)(win->map->y_res / perpwalldist);
	win->drawing->drawstart = -win->drawing->lineheight / 2 +
	(win->map->y_res) / 2;
	if (win->drawing->drawstart < 0)
		win->drawing->drawstart = 0;
	win->drawing->drawend = win->drawing->lineheight / 2 +
	(win->map->y_res) / 2;
	draw_wall(win, texx, i);
}
