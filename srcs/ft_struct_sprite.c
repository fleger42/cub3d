/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_struct_sprite.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 16:14:43 by fleger            #+#    #+#             */
/*   Updated: 2020/06/03 01:18:24 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub3d.h"

t_sprite	ft_create_sprite(void)
{
	t_sprite sprite;

	sprite.x = -1;
	sprite.y = -1;
	return (sprite);
}

t_sprite	*ft_malloc_sprite(void)
{
	t_sprite *sprite;

	if (!(sprite = (t_sprite*)malloc(sizeof(t_sprite))))
		ft_error("Error malloc");
	*sprite = ft_create_sprite();
	return (sprite);
}

void		ft_free_sprite(t_sprite **to_free, int nbr)
{
	int i;

	i = -1;
	while (++i < nbr)
		free(to_free[i]);
	free(to_free);
}
