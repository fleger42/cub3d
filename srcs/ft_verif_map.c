/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_verif_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/03 00:51:39 by user42            #+#    #+#             */
/*   Updated: 2020/06/10 16:55:01 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub3d.h"

int			verif_line(char *str, t_map *info)
{
	int i;
	int boolean;

	boolean = 0;
	i = -1;
	while (str[++i])
	{
		if (str[i] == 'N' || str[i] == 'W' || str[i] == 'E' || str[i] == 'S')
		{
			if (info->player_direction == 'N' || info->player_direction == 'W'
			|| info->player_direction == 'E' || info->player_direction == 'S')
				ft_error("Multiple position player");
			info->x_player = i + 0.5;
			info->player_direction = str[i];
			boolean = 1;
		}
		else if (str[i] != ' ' && str[i] != '0' &&
		str[i] != '1' && str[i] != '2')
			ft_error("Wrong caracter map");
	}
	if (boolean == 1)
		return (1);
	return (0);
}

void		verif_map(t_map info)
{
	int i;
	int j;

	i = 0;
	if ((info.path_sprite == NULL || info.path_no == NULL || info.path_so
	== NULL || info.path_we == NULL || info.path_ea == NULL || info.x_res == 0
	|| info.y_res == 0 || info.player_direction == '0' || info.verif_path_c == 0
	|| info.verif_path_f == 0))
		ft_error("Missing information");
	ft_verif_zero_two(info.description, info.x_player, info.y_player);
	while (info.description[i] != NULL)
	{
		j = 0;
		ft_verif_end_start(info.description[i]);
		while (info.description[i][j] != '\0')
		{
			if (info.description[i][j] == '0' || info.description[i][j] == '2')
				ft_verif_zero_two(info.description, j, i);
			if (info.description[i][j] == ' ')
				ft_verif_valid(&info, j, i);
			j++;
		}
		i++;
	}
}

void		ft_verif_valid(t_map *info, int j, int i)
{
	int k;

	k = j;
	while (info->description[i][k] != '1' && k != 0)
		if (info->description[i][k--] == '0' || info->description[i][j] == '2')
			ft_error("Map error 1 la");
	k = j;
	while (info->description[i][k] != '\0' && info->description[i][k] != '1')
		if (info->description[i][k++] == '0' || info->description[i][j] == '2')
			ft_error("Map error 2");
	k = i;
	while (k != 0 && info->description[k][j] != '1')
		if (info->description[k--][j] == '0' || info->description[i][j] == '2')
			ft_error("Map error 3");
	k = i;
	while (info->description[k] != NULL && info->description[k][j] != '1')
		if (info->description[k++][j] == '0' || info->description[i][j] == '2')
			ft_error("Map error 4");
}

void		ft_verif_end_start(char *str)
{
	int i;
	int count;

	count = ft_strlen(str) - 1;
	if (count < 0)
		count = 0;
	i = 0;
	while (str[i] && str[i] == ' ')
		i++;
	if (str[i] == '0' || str[i] == 'N' || str[i] == 'W' || str[i] == 'S'
	|| str[i] == 'E' || str[i] == '2')
		ft_error("Map error 1 start");
	while (count != 0 && str[count] == ' ')
		count--;
	if (str[count] == '0' || str[count] == 'N' || str[count] == 'W' ||
	str[count] == 'S' || str[count] == 'E' || str[count] == '2')
		ft_error("Map error 1 end");
}

void		ft_verif_zero_two(char **str, int x, int y)
{
	if ((int)ft_strlen(str[y - 1]) < x + 1)
		ft_error("Map error 1 end");
	if (str[y + 1] == NULL || (int)ft_strlen(str[y + 1]) < x + 1)
		ft_error("Map error 1 end");
	if (str[y - 1][x] == ' ')
		ft_error("Map error 1 end");
	if (str[y + 1] == NULL || str[y + 1][x] == ' ')
		ft_error("Map error 1 end");
	if (str[y][x - 1] == ' ')
		ft_error("Map error 1 end");
	if (str[y][x + 1] == ' ')
		ft_error("Map error 1 end");
}
