/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 21:44:30 by fleger            #+#    #+#             */
/*   Updated: 2020/06/12 16:57:41 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub3d.h"

char		*ft_copy_line(char *str)
{
	int		i;
	int		j;
	char	*copy;

	j = 0;
	i = 0;
	if (!(copy = malloc(sizeof(char) * (ft_count_digit(str) + 1))))
		ft_error("Error malloc");
	while (str[i])
	{
		if (ft_isdigit(str[i]) || str[i] == 'N' || str[i] == 'W' ||
		str[i] == 'E' || str[i] == 'S' || str[i] == ' ')
			copy[j++] = str[i];
		i++;
	}
	copy[j] = '\0';
	return (copy);
}

void		ft_parsing_description(t_map *info, int n, char **line)
{
	int		j;
	int		i;
	char	**temp;

	i = -1;
	j = 1;
	if (!(temp = malloc(sizeof(char*) * 2)))
		ft_error("Error malloc");
	if (verif_line(*line, info) == 1)
		info->y_player = j + 0.5;
	ft_str_one(*line);
	temp[++i] = ft_copy_line(*line);
	temp[++i] = NULL;
	free(*line);
	while (get_next_line(n, &*line) > 0)
	{
		temp = realloc_description(temp, *line);
		if (verif_line(*line, info) == 1)
			info->y_player = j + 0.5;
		free(*line);
		j++;
	}
	ft_add_line(&line, info, &temp, j);
	info->description = temp;
}

void		ft_verif_valid_caracter(char *line)
{
	if (line[0] != '\n' && line[0] != '\0' && line[0] != ' ' &&
	line[0] != 'R' && line[0] != 'C' && line[0] != 'F' && line[0] != 'S' &&
	!(line[0] == 'N' && line[1] == 'O') && !(line[0] == 'S' &&
	line[1] == 'O') && !(line[0] == 'W' && line[1] == 'E') &&
	!(line[0] == 'E' && line[1] == 'A'))
		ft_error("Error invalid caracter");
}

t_map		ft_parsing(t_map info)
{
	char	*line;

	while (get_next_line(info.n, &line) > 0)
	{
		ft_fill_player_direction(line, &info);
		if (line[0] == 'R')
			info = param_r(info, line + 1);
		if (line[0] == 'C')
			info.path_c = color_c(line + 1, &info);
		if (line[0] == 'F')
			info.path_f = color_f(line + 1, &info);
		if (line[0] == 'S' && line[1] != 'O' && info.path_sprite == NULL)
			info.path_sprite = ft_strdup(char_walk(line + 1));
		else if (line[0] == 'S' && line[1] != 'O')
			ft_error("Duplicate S key");
		if (ft_isdigit(line[0]) || line[0] == ' ')
			ft_parsing_description(&info, info.n, &line);
		else
			ft_verif_valid_caracter(line);
		free(line);
	}
	verif_map(info);
	close(info.n);
	free(line);
	return (info);
}

void		ft_fill_player_direction(char *line, t_map *info)
{
	if (line[0] == 'N' && line[1] == 'O' && info->path_no == NULL)
		info->path_no = ft_strdup(char_walk(line + 2));
	else if (line[0] == 'N' && line[1] == 'O')
		ft_error("Duplicate NO key");
	if (line[0] == 'S' && line[1] == 'O' && info->path_so == NULL)
		info->path_so = ft_strdup(char_walk(line + 2));
	else if (line[0] == 'S' && line[1] == 'O')
		ft_error("Duplicate SO key");
	if (line[0] == 'W' && line[1] == 'E' && info->path_we == NULL)
		info->path_we = ft_strdup(char_walk(line + 2));
	else if (line[0] == 'W' && line[1] == 'E')
		ft_error("Duplicate WE key");
	if (line[0] == 'E' && line[1] == 'A' && info->path_ea == NULL)
		info->path_ea = ft_strdup(char_walk(line + 2));
	else if (line[0] == 'E' && line[1] == 'A')
		ft_error("Duplicate EA key");
}
