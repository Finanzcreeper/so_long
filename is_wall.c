/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_wall.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nreher <nreher@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 13:07:50 by nreher            #+#    #+#             */
/*   Updated: 2023/03/28 13:13:01 by nreher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	iwa(t_all *all)
{
	int	c;

	c = 0;
	while (c < all->img.wall->count)
	{
		if (all->img.player->instances[0].y
			- all->img.wall->instances[c].y == (int)all->img.empty->height
			&& all->img.player->instances[0].x == all->img.wall->instances[c].x)
		{
			return (1);
		}
		c++;
	}
	return (0);
}

int	iwb(t_all *all)
{
	int	c;

	c = 0;
	while (c < all->img.wall->count)
	{
		if (all->img.wall->instances[c].y
			- all->img.player->instances[0].y == (int)all->img.empty->height
			&& all->img.player->instances[0].x == all->img.wall->instances[c].x)
		{
			return (1);
		}
		c++;
	}
	return (0);
}

int	iwl(t_all *all)
{
	int	c;

	c = 0;
	while (c < all->img.wall->count)
	{
		if (all->img.player->instances[0].x
			- all->img.wall->instances[c].x == (int)all->img.empty->width
			&& all->img.player->instances[0].y == all->img.wall->instances[c].y)
		{
			return (1);
		}
		c++;
	}
	return (0);
}

int	iwr(t_all *all)
{
	int	c;

	c = 0;
	while (c < all->img.wall->count)
	{
		if (all->img.wall->instances[c].x
			- all->img.player->instances[0].x == (int)all->img.empty->width
			&& all->img.player->instances[0].y == all->img.wall->instances[c].y)
		{
			return (1);
		}
		c++;
	}
	return (0);
}
