/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redraw.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nreher <nreher@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 14:30:39 by nreher            #+#    #+#             */
/*   Updated: 2023/03/28 15:08:09 by nreher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	redraw(t_all *all)
{
	int	c;

	c = 0;
	while (c < all->img.empty->count)
	{
		player_move_handler(all, c);
		c++;
	}
	c = 0;
	while (c < all->img.collect->count)
	{
		if (all->img.collect->instances[c].x == all->img.player
			->instances[0].x && all->img.collect->instances[c].y
			== all->img.player->instances[0].y)
			all->img.collect->instances[c].enabled = 0;
		c++;
	}
	if (all->messages.not_all_collects->enabled == 1)
		all->messages.not_all_collects->enabled = 0;
	if (all->img.exit->instances[0].x == all->img.player->instances[0].x
		&& all->img.exit->instances[0].y == all->img.player->instances[0].y)
		count_missed(all);
	collectables_handler(all);
	do_move(all);
	do_pink(all);
}

void	player_move_handler(t_all *all, int c)
{
	if (all->img.player->instances[0].x == all->img.empty->instances[c].x
		&& all->img.player->instances[0].y
		== all->img.empty->instances[c].y)
		all->img.empty->instances[c].enabled = 0;
	if (all->img.player->instances[0].x != all->img.empty->instances[c].x
		|| all->img.player->instances[0].y
		!= all->img.empty->instances[c].y)
		all->img.empty->instances[c].enabled = 1;
}

void	collectables_handler(t_all *all)
{
	all->current = all->head.first->next_c;
	while (all->current != NULL)
	{
		if (all->current->contnt == 'C' && all->current->x
			== all->img.player->instances[0].x
			&& all->current->y == all->img.player->instances[0].y)
		{
			all->current->contnt = 'c';
			all->pinksies++;
		}
		all->current = all->current->next_c;
	}
}
