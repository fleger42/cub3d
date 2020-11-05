/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_input_player.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/03 02:19:14 by user42            #+#    #+#             */
/*   Updated: 2020/06/07 10:44:27 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub3d.h"

int		key_press(int key, t_win *win)
{
	if (key == 65307)
		win->player->escape = 1;
	else if (key == 122)
		win->player->key_w = 1;
	else if (key == 115)
		win->player->key_s = 1;
	else if (key == 100)
		win->player->key_d = 1;
	else if (key == 113)
		win->player->key_a = 1;
	else if (key == 65361)
		win->player->left = 1;
	else if (key == 65363)
		win->player->right = 1;
	return (1);
}

int		key_release(int key, t_win *win)
{
	if (key == 65307)
		win->player->escape = 0;
	else if (key == 122)
		win->player->key_w = 0;
	else if (key == 115)
		win->player->key_s = 0;
	else if (key == 100)
		win->player->key_d = 0;
	else if (key == 113)
		win->player->key_a = 0;
	else if (key == 65361)
		win->player->left = 0;
	else if (key == 65363)
		win->player->right = 0;
	return (1);
}

int		ft_key_input(t_win *win)
{
	if (win->player->escape == 1)
		ft_exit(win);
	if (win->player->left == 1)
		ft_key_left(win);
	if (win->player->right == 1)
		ft_key_right(win);
	if (win->player->key_s == 1)
		ft_key_s(win);
	if (win->player->key_w == 1)
		ft_key_w(win);
	if (win->player->key_a == 1)
		ft_key_a(win);
	if (win->player->key_d == 1)
		ft_key_d(win);
	display(win, win->map, 1);
	return (1);
}
