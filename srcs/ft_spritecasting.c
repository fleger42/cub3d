/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_spritecasting.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/05 08:40:47 by user42            #+#    #+#             */
/*   Updated: 2020/06/05 11:01:22 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub3d.h"

void	ft_create_sprite_tab(int nbr_sprite, t_win *win)
{
	int i;

	if (!(win->sprite = malloc(sizeof(t_sprite*) * nbr_sprite)))
		ft_error("Error malloc");
	i = -1;
	while (++i < nbr_sprite)
		if (!(win->sprite[i] = ft_malloc_sprite(*win)))
			ft_error("Error malloc");
}

void	ft_sprite_color(t_win *win, int y)
{
	t_color color;

	color = create_t_color((unsigned char)win->sprite_addr
	[abs(win->sprite_line_length * win->spr->texy +
	win->spr->texx * 4)],
		(unsigned char)win->sprite_addr[
			abs(win->sprite_line_length * win->spr->texy +
			win->spr->texx * 4) + 1],
		(unsigned char)win->sprite_addr[
			abs(win->sprite_line_length * win->spr->texy +
			win->spr->texx * 4) + 2],
		(unsigned char)win->sprite_addr[
			abs(win->sprite_line_length * win->spr->texy +
			win->spr->texx * 4) + 3]);
	if (!(color.g == 0 && color.b == 0 && color.r == 0))
		my_mlx_put_pxl_to_img(win->spr->stripe, y, color, win);
}

void	ft_sprite_casting(t_win *win, int nbr_sprite)
{
	int		y;
	int		i;

	ft_sprite_dist(win, nbr_sprite);
	ft_sort_sprite(nbr_sprite, win);
	i = -1;
	while (++i < nbr_sprite)
	{
		ft_sprite_calculation(win, i);
		ft_sprite_calculation2(win);
		while (win->spr->stripe++ < win->spr->drawendx)
		{
			ft_sprite_texx(win);
			y = win->spr->drawstarty;
			if (win->spr->transformy > 0 && win->spr->stripe > 0 &&
			win->spr->stripe < win->map->x_res && win->spr->transformy
			< win->map->perp_buffer[win->spr->stripe])
				while (y++ < win->spr->drawendy)
				{
					ft_sprite_texy(win, y);
					ft_sprite_color(win, y);
				}
		}
	}
}
