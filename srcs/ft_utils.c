/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/03 00:49:49 by user42            #+#    #+#             */
/*   Updated: 2020/06/05 10:48:08 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub3d.h"

void		ft_error(char *str)
{
	ft_putstr(str);
	exit(0);
}

int			ft_atoi(const char *nptr)
{
	int				i;
	int				result;
	int				signe;

	signe = 1;
	i = 0;
	result = 0;
	while ((nptr[i] >= 8 && nptr[i] <= 13) || nptr[i] == ' ')
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			signe = -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		result = result * 10 + (nptr[i++] - 48);
	}
	result = result * signe;
	return (result);
}

t_color		create_t_color(unsigned char p_b,
unsigned char p_g, unsigned char p_r, unsigned char p_a)
{
	t_color color;

	color.b = p_b;
	color.g = p_g;
	color.r = p_r;
	color.a = p_a;
	return (color);
}

void		my_mlx_put_pxl_to_img(int x, int y, t_color color, t_win *draw)
{
	int pos;

	pos = (x * 4 + draw->line_length * y);
	draw->addr[pos + 0] = color.b;
	draw->addr[pos + 1] = color.g;
	draw->addr[pos + 2] = color.r;
	draw->addr[pos + 3] = color.a;
}
