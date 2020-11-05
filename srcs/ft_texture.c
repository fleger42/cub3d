/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_texture.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/03 01:25:50 by user42            #+#    #+#             */
/*   Updated: 2020/06/12 17:06:49 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub3d.h"

int			get_texture_width(t_win *win)
{
	if (win->side == 0 && win->raydirx < 0)
		return (win->text1_width);
	else if (win->side == 0 && win->raydirx > 0)
		return (win->text3_width);
	else if (win->side == 1 && win->raydiry > 0)
		return (win->text2_width);
	else if (win->side == 1 && win->raydiry < 0)
		return (win->text4_width);
	return (0);
}

int			get_texture_height(t_win *win)
{
	if (win->side == 0 && win->raydirx < 0)
		return (win->text1_height);
	else if (win->side == 0 && win->raydirx > 0)
		return (win->text3_height);
	else if (win->side == 1 && win->raydiry > 0)
		return (win->text2_height);
	else if (win->side == 1 && win->raydiry < 0)
		return (win->text4_height);
	return (0);
}

t_color		get_texture(t_win *win, int texx, int texy, double coef)
{
	if (win->side == 0 && win->raydirx < 0)
		return (create_t_color((unsigned char)win->text1_addr[texx + texy *
		win->text1_ll] * coef, (unsigned char)win->text1_addr[texx + texy *
		win->text1_ll + 1] * coef, (unsigned char)win->text1_addr[texx +
		texy * win->text1_ll + 2] * coef, (unsigned char)win->text1_addr[texx
		+ texy * win->text1_ll + 3] * coef));
	else if (win->side == 0 && win->raydirx > 0)
		return (create_t_color((unsigned char)win->text3_addr[texx + texy *
		win->text3_ll] * coef, (unsigned char)win->text3_addr[texx + texy *
		win->text3_ll + 1] * coef, (unsigned char)win->text3_addr[texx +
		texy * win->text3_ll + 2] * coef, (unsigned char)win->text3_addr[texx
		+ texy * win->text3_ll + 3] * coef));
	else if (win->side == 1 && win->raydiry > 0)
		return (create_t_color((unsigned char)win->text2_addr[texx + texy *
		win->text2_ll] * coef, (unsigned char)win->text2_addr[texx + texy *
		win->text2_ll + 1] * coef, (unsigned char)win->text2_addr[texx +
		texy * win->text2_ll + 2] * coef, (unsigned char)win->text2_addr[texx
		+ texy * win->text2_ll + 3] * coef));
	else
		return (create_t_color((unsigned char)win->text4_addr[texx + texy *
		win->text4_ll] * coef, (unsigned char)win->text4_addr[texx + texy *
		win->text4_ll + 1] * coef, (unsigned char)win->text4_addr[texx +
		texy * win->text4_ll + 2] * coef, (unsigned char)win->text4_addr[texx
		+ texy * win->text4_ll + 3] * coef));
}

void		ft_get_addr(t_win *win)
{
	win->text1_addr = mlx_get_data_addr(win->text1_ptr, &win->text1_bpp,
	&win->text1_ll, &win->text1_endian);
	win->text2_addr = mlx_get_data_addr(win->text2_ptr, &win->text2_bpp,
	&win->text2_ll, &win->text2_endian);
	win->text3_addr = mlx_get_data_addr(win->text3_ptr, &win->text3_bpp,
	&win->text3_ll, &win->text3_endian);
	win->text4_addr = mlx_get_data_addr(win->text4_ptr, &win->text4_bpp,
	&win->text4_ll, &win->text4_endian);
	win->text4_addr = mlx_get_data_addr(win->text4_ptr, &win->text4_bpp,
	&win->text4_ll, &win->text4_endian);
	win->sprite_addr = mlx_get_data_addr(win->sprite_ptr,
	&win->sprite_bits_per_pixel, &win->sprite_line_length,
	&win->sprite_endian);
}

void		ft_load_img(t_win *win)
{
	if (!(win->text1_ptr = mlx_xpm_file_to_image(win->mlx_ptr,
	win->map->path_ea, &win->text1_width, &win->text1_height)))
		ft_error("Wrong texture path EA");
	if (!(win->text2_ptr = mlx_xpm_file_to_image(win->mlx_ptr,
	win->map->path_no, &win->text2_width, &win->text2_height)))
		ft_error("Wrong texture path NO");
	if (!(win->text3_ptr = mlx_xpm_file_to_image(win->mlx_ptr,
	win->map->path_we, &win->text3_width, &win->text3_height)))
		ft_error("Wrong texture path WE");
	if (!(win->text4_ptr = mlx_xpm_file_to_image(win->mlx_ptr,
	win->map->path_so, &win->text4_width, &win->text4_height)))
		ft_error("Wrong texture path SO");
	if (!(win->sprite_ptr = mlx_xpm_file_to_image(win->mlx_ptr,
	win->map->path_sprite, &win->sprite_width, &win->sprite_height)))
		ft_error("Wrong path sprite");
	ft_get_addr(win);
}
