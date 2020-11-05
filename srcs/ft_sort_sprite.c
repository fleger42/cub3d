/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_sprite.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/05 09:54:49 by user42            #+#    #+#             */
/*   Updated: 2020/06/05 09:58:36 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub3d.h"

void	ft_get_pos_sprite(t_win *win, t_sprite **sprite)
{
	int i;
	int j;
	int count;

	count = 0;
	i = 0;
	while (win->map->description[i] != NULL)
	{
		j = 0;
		while (win->map->description[i][j] != '\0')
		{
			if (win->map->description[i][j] == '2')
			{
				sprite[count]->y = i + 0.5;
				sprite[count]->x = j + 0.5;
				count++;
			}
			j++;
		}
		i++;
	}
}

int		ft_count_sprite(t_win *win)
{
	int i;
	int j;
	int count;

	count = 0;
	i = 0;
	while (win->map->description[i] != NULL)
	{
		j = 0;
		while (win->map->description[i][j] != '\0')
		{
			if (win->map->description[i][j] == '2')
				count++;
			j++;
		}
		i++;
	}
	return (count);
}

void	ft_swap_double(double *tab, int i, int j)
{
	double temp;

	temp = tab[i];
	tab[i] = tab[j];
	tab[j] = temp;
}

void	ft_swap_int(int *tab, int i, int j)
{
	int temp;

	temp = tab[i];
	tab[i] = tab[j];
	tab[j] = temp;
}

void	ft_sort_sprite(int nbr_sprite, t_win *win)
{
	int i;
	int j;

	i = -1;
	while (++i < nbr_sprite)
		win->sprite_order[i] = i;
	i = 0;
	while (i < nbr_sprite)
	{
		j = i + 1;
		while (j < nbr_sprite)
		{
			if (win->sprite_distance[i] < win->sprite_distance[j])
			{
				ft_swap_double(win->sprite_distance, i, j);
				ft_swap_int(win->sprite_order, i, j);
				i = -1;
				break ;
			}
			j++;
		}
		i++;
	}
}
