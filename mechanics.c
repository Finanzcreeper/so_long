/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mechanics.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nreher <nreher@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 10:22:46 by nreher            #+#    #+#             */
/*   Updated: 2023/03/28 14:08:31 by nreher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	count_missed(t_all *all)
{
	int	c;
	int	missed;

	c = 0;
	missed = 0;
	while (c < all->img.collect->count)
	{
		if (all->img.collect->instances[c].enabled == 1)
			missed += 1;
		c++;
	}
	if (missed != 0)
		all->messages.not_all_collects->enabled = 1;
	else
		all->messages.win->enabled = 1;
}

void	do_move(t_all *all)
{
	int		c;
	int		count;

	c = 0;
	count = all->movsies;
	while (count > 0)
	{
		all->moves[c] = (count % 10) + 48;
		count /= 10;
		c++;
	}
	move_while(all);
	all->messages.move_count->enabled = 0;
	all->messages.moves->enabled = 0;
	load_moves(all);
}

void	do_pink(t_all *all)
{
	int		c;
	int		count;

	c = 0;
	count = all->pinksies;
	while (count > 0)
	{
		all->pink[c] = (count % 10) + 48;
		count /= 10;
		c++;
	}
	pink_while(all);
	all->messages.collectables_collected->enabled = 0;
	all->messages.collectables->enabled = 0;
	load_pink(all);
}
