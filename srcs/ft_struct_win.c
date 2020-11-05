/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_struct_win.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/21 08:04:36 by fleger            #+#    #+#             */
/*   Updated: 2020/06/12 17:08:04 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub3d.h"

t_win	ft_create_win(char *title, t_map *map, char *str)
{
	t_win info;

	if (!(info.drawing = (t_drawing*)malloc(sizeof(t_drawing))))
		ft_error("Error malloc");
	if (!(info.ray = (t_raycast*)malloc(sizeof(t_raycast))))
		ft_error("Error malloc");
	if (!(info.spr = (t_spritecast*)malloc(sizeof(t_spritecast))))
		ft_error("Error malloc");
	info.map = map;
	info.mlx_ptr = mlx_init();
	mlx_get_screen_size(info.mlx_ptr, &info.sizex, &info.sizey);
	if (info.map->x_res > info.sizex)
		info.map->x_res = info.sizex;
	if (info.map->y_res > info.sizey)
		info.map->y_res = info.sizey;
	info.x_win = info.map->x_res;
	info.y_win = info.map->y_res;
	if (str == NULL)
		info.win_ptr = mlx_new_window(info.mlx_ptr, info.x_win, info.y_win,
		title);
	if (!(info.player = ft_malloc_player()))
		ft_error("Error malloc");
	return (info);
}

t_win	*ft_malloc_win(char *title, t_map *map, char *str)
{
	t_win *info;

	if (!(info = (t_win*)malloc(sizeof(t_win))))
		ft_error("Error malloc");
	*info = ft_create_win(title, map, str);
	return (info);
}

void	ft_free_win(t_win *to_free, int nbr)
{
	mlx_destroy_image(to_free->mlx_ptr, to_free->img);
	free(to_free->mlx_ptr);
	ft_free_map(to_free->map);
	ft_free_player(to_free->player);
	free(to_free->sprite_order);
	free(to_free->sprite_distance);
	ft_free_sprite(to_free->sprite, nbr);
	free(to_free->drawing);
	free(to_free->ray);
	free(to_free->spr);
	free(to_free);
}
