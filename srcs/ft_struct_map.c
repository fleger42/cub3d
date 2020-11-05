/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_struct_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/21 09:03:55 by fleger            #+#    #+#             */
/*   Updated: 2020/06/12 16:46:08 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub3d.h"

void	ft_set_player(t_map *map)
{
	if (map->player_direction == 'S')
	{
		map->dirx = 0;
		map->diry = 1;
		map->planex = -0.66;
		map->planey = 0;
	}
	if (map->player_direction == 'E')
	{
		map->dirx = 1;
		map->diry = 0;
		map->planex = 0;
		map->planey = 0.66;
	}
	if (map->player_direction == 'W')
	{
		map->dirx = -1;
		map->diry = 0;
		map->planex = 0;
		map->planey = -0.66;
	}
}

void	ft_set_path_default(t_map *map)
{
	map->path_no = NULL;
	map->path_so = NULL;
	map->path_we = NULL;
	map->path_ea = NULL;
	map->path_sprite = NULL;
	map->path_c.a = 0;
	map->path_c.r = 0;
	map->path_c.g = 0;
	map->path_c.b = 0;
	map->path_f.a = 0;
	map->path_f.r = 0;
	map->path_f.g = 0;
	map->path_f.b = 0;
	map->verif_path_c = 0;
	map->verif_path_f = 0;
}

t_map	ft_create_map(char *str)
{
	t_map map;

	map.valid = 0;
	map.n = open(str, O_RDONLY);
	map.player_direction = '0';
	map.x_res = 0;
	map.y_res = 0;
	map.x_player = 0;
	map.y_player = 0;
	map.dirx = 0;
	map.diry = 0;
	map.planex = 0;
	map.planey = 0;
	ft_set_path_default(&map);
	map = ft_parsing(map);
	ft_set_player(&map);
	if (map.player_direction == 'N')
	{
		map.dirx = 0;
		map.diry = -1;
		map.planex = 0.66;
		map.planey = 0;
	}
	return (map);
}

t_map	*ft_malloc_map(char *str)
{
	t_map *map;

	if (!(map = (t_map*)malloc(sizeof(t_map))))
		ft_error("Error malloc");
	*map = ft_create_map(str);
	if (!(map->perp_buffer = malloc(sizeof(double) * map->x_res)))
		ft_error("Error malloc");
	return (map);
}

void	ft_free_map(t_map *to_free)
{
	int i;

	i = 0;
	free(to_free->path_no);
	free(to_free->path_so);
	free(to_free->path_we);
	free(to_free->path_ea);
	free(to_free->path_sprite);
	while (to_free->description[i] != NULL)
		free(to_free->description[i++]);
	free(to_free->description[i]);
	free(to_free->description);
	free(to_free->perp_buffer);
	free(to_free);
}
