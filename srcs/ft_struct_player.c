/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_struct_player.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 11:41:03 by fleger            #+#    #+#             */
/*   Updated: 2020/06/03 00:43:42 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub3d.h"

t_player	ft_create_player(void)
{
	t_player player;

	player.left = 0;
	player.right = 0;
	player.key_w = 0;
	player.key_a = 0;
	player.key_s = 0;
	player.key_d = 0;
	player.escape = 0;
	return (player);
}

t_player	*ft_malloc_player(void)
{
	t_player *player;

	player = (t_player*)malloc(sizeof(t_player));
	*player = ft_create_player();
	return (player);
}

void		ft_free_player(t_player *to_free)
{
	free(to_free);
}
