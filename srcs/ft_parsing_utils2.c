/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing_utils2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/03 00:48:38 by user42            #+#    #+#             */
/*   Updated: 2020/06/12 17:07:42 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub3d.h"

int			ft_count_digit(char *str)
{
	int i;
	int j;

	j = 0;
	i = 0;
	while (str[i])
	{
		if (ft_isdigit(str[i]) || str[i] == 'N' || str[i] == 'W'
		|| str[i] == 'E' || str[i] == 'S' || str[i] == ' ')
			j++;
		i++;
	}
	return (j);
}

char		**realloc_description(char **description, char *str)
{
	int		i;
	char	**new;

	i = 0;
	while (description[i] != NULL)
		i++;
	if (!(new = malloc(sizeof(char*) * (i + 2))))
		ft_error("Error malloc");
	i = 0;
	while (description[i] != NULL)
	{
		new[i] = ft_strdup(description[i]);
		free(description[i]);
		i++;
	}
	new[i] = ft_strdup(str);
	new[i + 1] = NULL;
	free(description[i]);
	free(description);
	return (new);
}

void		ft_add_line(char ***line, t_map *info, char ***temp, int j)
{
	if (**line[0] != '\0')
	{
		if (verif_line(**line, info) == 1)
			info->y_player = j + 0.5;
		ft_str_one(**line);
		*temp = realloc_description(*temp, **line);
	}
}

char		*char_walk(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == ' ' || (str[i] >= 8 && str[i] <= 13))
			i++;
		else if (str[i] != '\0' && str[i] == '.' && str[i + 1] == '/')
			return (str + i);
		else
			ft_error("Wrong map path");
	}
	return (NULL);
}

void		ft_str_one(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '0')
			ft_error("Map error 1");
		i++;
	}
}
