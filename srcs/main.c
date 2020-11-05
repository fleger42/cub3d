/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 04:07:57 by fleger            #+#    #+#             */
/*   Updated: 2020/06/12 17:06:40 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub3d.h"

int		ft_exit(t_win *win)
{
	mlx_destroy_image(win->mlx_ptr, win->text1_ptr);
	mlx_destroy_image(win->mlx_ptr, win->text2_ptr);
	mlx_destroy_image(win->mlx_ptr, win->text3_ptr);
	mlx_destroy_image(win->mlx_ptr, win->text4_ptr);
	mlx_destroy_image(win->mlx_ptr, win->sprite_ptr);
	ft_free_win(win, win->map->nbr_sprite);
	write(1, "\nDESTROYED\n", 12);
	exit(1);
	return (0);
}

void	display(t_win *win, t_map *map, int arg)
{
	int i;

	i = -1;
	while (++i < map->x_res)
		map->perp_buffer[i] = ray_casting(win, i);
	ft_sprite_casting(win, map->nbr_sprite);
	if (arg == 1)
		mlx_put_image_to_window(win->mlx_ptr, win->win_ptr, win->img, 0, 0);
}

void	ft_arg_verif(int ac, char **av, t_win *win)
{
	int length;

	length = ft_strlen(av[1]);
	if (ac == 2 && (length < 5 || !(av[1][length - 1] == 'b' &&
	av[1][length - 2] == 'u' && av[1][length - 3] == 'c'
	&& av[1][length - 4] == '.')))
		ft_error("Problem with .cub name");
	if (ac > 3)
		ft_error("Too many arguments");
	if (ac == 3 && ft_strncmp("--save", av[2], 7) == 0)
	{
		display(win, win->map, 0);
		ft_save_bmp(win);
		ft_exit(win);
	}
	else if (ac == 3)
		ft_error("Unknown arguments");
	else
	{
		display(win, win->map, 1);
		mlx_loop_hook(win->mlx_ptr, ft_key_input, win);
	}
}

int		main(int ac, char **av)
{
	t_win *win;

	if (ac == 1)
		ft_error("No map.cub");
	if (ac == 3)
		win = ft_malloc_win("Cub3D", ft_malloc_map(av[1]), av[2]);
	else
		win = ft_malloc_win("Cub3D", ft_malloc_map(av[1]), NULL);
	win->img = mlx_new_image(win->mlx_ptr, win->map->x_res, win->map->y_res);
	win->addr = mlx_get_data_addr(win->img, &win->bits_per_pixel,
	&win->line_length, &win->endian);
	ft_load_img(win);
	win->map->nbr_sprite = ft_count_sprite(win);
	if (!(win->sprite_distance = malloc(sizeof(double) * win->map->nbr_sprite)))
		ft_error("Error malloc");
	if (!(win->sprite_order = malloc(sizeof(int) * win->map->nbr_sprite)))
		ft_error("Error malloc");
	ft_create_sprite_tab(win->map->nbr_sprite, win);
	ft_get_pos_sprite(win, win->sprite);
	ft_arg_verif(ac, av, win);
	mlx_hook(win->win_ptr, 2, 1L << 0, key_press, win);
	mlx_hook(win->win_ptr, 3, 1L << 1, key_release, win);
	mlx_hook(win->win_ptr, 33, 1L << 17, ft_exit, win);
	mlx_loop(win->mlx_ptr);
	return (0);
}
