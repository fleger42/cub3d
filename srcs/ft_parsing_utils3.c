/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing_utils3.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/03 01:07:11 by user42            #+#    #+#             */
/*   Updated: 2020/06/12 16:51:16 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub3d.h"

int			ft_verif_path_color(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == ' ' || (str[i] >= 8 && str[i] <= 13))
			i++;
		else if (ft_isdigit(str[i]))
			return (i);
		else
			ft_error("Wrong path color");
	}
	return (0);
}

t_color		color_f(char *str, t_map *info)
{
	int				i;
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;
	static int		verif = 0;

	i = ft_verif_path_color(str);
	if (verif == 1)
		ft_error("Dup caracter");
	verif = 1;
	info->verif_path_f = 1;
	r = ft_atoi(str + i);
	while (str[i] != ',')
		i++;
	g = ft_atoi(str + i + 1);
	i++;
	while (str[i] != ',')
		i++;
	b = ft_atoi(str + i + 1);
	return (create_t_color(b, g, r, 0));
}

t_color		color_c(char *str, t_map *info)
{
	int				i;
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;
	static int		verif = 0;

	i = ft_verif_path_color(str);
	if (verif == 1)
		ft_error("Dup caracter");
	verif = 1;
	info->verif_path_c = 1;
	i = 0;
	r = ft_atoi(str + i);
	while (str[i] != ',')
		i++;
	g = ft_atoi(str + i + 1);
	i++;
	while (str[i] != ',')
		i++;
	b = ft_atoi(str + i + 1);
	return (create_t_color(b, g, r, 0));
}

int			ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while (s1[i] && s2[i] && s2[i] == s1[i] && i + 1 < n)
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

t_map		param_r(t_map pars, char *str)
{
	int			i;
	static int	verif = 0;

	i = 0;
	while (str[i])
	{
		if (str[i] == ' ' || (str[i] >= 8 && str[i] <= 13))
			i++;
		else if (ft_isdigit(str[i]))
			break ;
		else
			ft_error("Wrong path resolution");
	}
	if (verif == 1)
		ft_error("Dup caracter");
	verif = 1;
	pars.x_res = ft_atoi(str + i);
	while (str[i] >= '0' && str[i] <= '9')
		i++;
	pars.y_res = ft_atoi(str + i);
	if (pars.y_res <= 0 || pars.x_res <= 0)
		ft_error("Wrong resolution");
	return (pars);
}
