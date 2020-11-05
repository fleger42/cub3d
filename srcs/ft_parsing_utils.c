/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 21:49:51 by fleger            #+#    #+#             */
/*   Updated: 2020/06/03 01:16:47 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub3d.h"

void	ft_putstr(char *str)
{
	int i;

	i = -1;
	while (str[++i])
		ft_putchar(str[i]);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		ft_isdigit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

void	ft_aff(int n)
{
	if (n >= 10)
	{
		ft_aff(n / 10);
		ft_aff(n % 10);
	}
	else
		ft_putchar(n + 48);
}

void	ft_putnbr(int n)
{
	if (n == -2147483648)
	{
		write(1, "-2147483648", 12);
		return ;
	}
	if (n < 0)
	{
		n = -1 * n;
		write(1, "-", 1);
	}
	ft_aff(n);
}
